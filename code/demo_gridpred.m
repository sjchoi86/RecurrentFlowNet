ccc
%%
ccc
% INIT SIMULATION
nx        = 200;
ny        = 200;
xrange    = [0 100];
yrange    = [0 100]; % [M]
vrange    = [10 30]; % 10M/S = 36KM/H
wrange    = [0 40];  % ANGULAR VELOCITY RANGE
rrange    = [2 4];   % OBJECT RADIUS RANGE
nr_obs    = 10;      % NUMBER OF OBJECTS
err_rates = [0.35];  % ERROR RATE
maxtick   = 100;
T         = 0.05;

% PLOT OPTION
plot_dir  = 1;
save_vid  = 0;

% INIT RECURRENT FLOW NETWORK
[occFlow.g1, occFlow.l1, occFlow.resize_rate, occFlow.g2, occFlow.l2] ...
    = parse_occflowparams( [ ...
    5.0 1.393 3.0 2.84 0.99 3.123 2.7946 1.6778 0.1138 0.2955 0.9120 0.7100 0.2600  ...
    5.0 1.650 3.0 0.72 0.63 8.660 1.2100 4.0330 0.0720 0.5800 0.2800 0.6900 0.2300  ...
    0.5 ] ...
    , xrange, yrange, nx, ny);
ginfo = set_grid(occFlow.g1.xmin, occFlow.g1.xmax, occFlow.g1.nx ...
    , occFlow.g1.ymin, occFlow.g1.ymax, occFlow.g1.ny);

seedidx = randi([0 10000]);

% INIT FIGURE
clear plot_gridpred;
scrsz = get(0,'ScreenSize');
fig = figure(1); set(fig, 'Position', [200 200 scrsz(3)*0.57 scrsz(4)*0.45]);
for err_rate = err_rates % FOR EACH ERROR RATES
    rng(seedidx);
    % INIT OBSTACLES
    obs4grid = init_obs4grid(occFlow.g1, nr_obs, rrange, vrange, wrange);
    obs4grid_init = obs4grid;
    ems_total = 0;
    for tick = 1:maxtick
        
        sec = tick*T;
        
        % GET BINARY OCCUPANCY GRID MAP
        iclk_init = clock;
        obs4grid = update_obs4grid(obs4grid, T);
        obs_grid_ref = get_obsgrid2(occFlow.g1, obs4grid);
        
        % ADD NOISE (FLIP!)
        obs_grid_meas = obs_grid_ref;
        flipidx = randsample(nx*ny, round(err_rate*nx*ny));
        obs_grid_meas(flipidx) = ~obs_grid_meas(flipidx);
        
        
        % ***************************** OCCUPANCY FLOW *****************************
        iclk = clock;
        occFlow.l1.curr_input = obs_grid_meas(:);
        occFlow.l1 = occflow_wrapper(occFlow.g1, occFlow.l1, occFlow.resize_rate);
        occFlow.l2.curr_input = occFlow.l1.binsmallmtx(:);
        occFlow.l2 = occflow_wrapper(occFlow.g2, occFlow.l2, occFlow.resize_rate);
        occflow_predmtx = imresize(reshape(occFlow.l2.predvec, occFlow.g2.ny, occFlow.g2.nx) ...
            , 1/occFlow.resize_rate); 
        ems_occflow = etime(clock, iclk)*1000;
        % OCCFLOW -> RGB
        rgb_gain2 = 0.3; rgb_th = occFlow.l2.bin_threshold;
        [occFlow.l2.rgbflowimg, valid_idx, u, v] ...
            = get_rgbflow(occFlow.l2.context, occFlow.l2.predvec, occFlow.l2.nei.filter.shift_xyi ...
            , occFlow.g2.nx, occFlow.g2.ny, rgb_gain2, rgb_th);
        occFlow.l2.rgbflowimg_resize = imresize(occFlow.l2.rgbflowimg, 1/occFlow.resize_rate);
        % OCCFLOW -> QUIVER
        quiver_rate   = 0.1;
        min_quiver    = 0;
        max_quiver    = 30;
        resize_quiver = 0.5;
        robot.pos     = [0 0 0];
        [xmesh, ymesh, ru, rv] ...
            = get_dirflow(u, v, valid_idx, robot, ginfo, quiver_rate, min_quiver, max_quiver ...
            , resize_quiver);
        % ***************************** OCCUPANCY FLOW *****************************
        
        
        
        % TERMINATE CONDITION
        out_count = 0;
        for i = 1:obs4grid.n
            obspos = obs4grid.obs{i}.pos;
            if obspos(1) < occFlow.g1.axis(1) || obspos(1) > occFlow.g1.axis(2) ...
                    || obspos(2) < occFlow.g1.axis(3) || obspos(2) > occFlow.g1.axis(4)
                out_count = out_count + 1;
            end
        end
        if out_count == obs4grid.n % IF ALL OBJECTS ARE OUT,
            break;
        end
        
        % **************************** PLOT ****************************
        iclk_plot = clock;
        fig = plot_gridpred(fig, obs4grid, occFlow, obs_grid_meas ...
            , tick, plot_dir, occflow_predmtx, ru, rv, err_rate, xmesh, ymesh, sec ...
            , ems_occflow);
        if save_vid
            set(fig,'PaperPositionMode','auto')
            print (fig , '-dpng', ['pics4vid/fig_gridseq_', num2str(tick, '%03d'), '.png']) ;
        end
        % **************************** PLOT ****************************
        
        % CHECK ELAPSED TIME AND PRINT
        ems_plot = etime(clock, iclk_plot)*1000;
        ems_total = etime(clock, iclk_init)*1000;
        fprintf('[%02d/%02d] ems_occflow: %.1fms ems_plot: %.1fms ems_total: %.1fms \n' ...
            , tick, maxtick, ems_occflow, ems_plot, ems_total);
    end
    if save_vid % Save video
        vidName  = sprintf('OccFlow_noise%.0f.avi', err_rate*100);
        frmRate  = 3;
        video    = VideoWriter( vidName );
        video.FrameRate = ( frmRate );
        open( video );
        for ii = 1:tick-1
            fprintf('%d/%d \n', ii, tick-1);
            img = imread( ['pics4vid/fig_gridseq_', num2str(ii, '%03d'), '.png'] );
            img = im2double(img);
            writeVideo( video, img );
        end
        close( video );
        fprintf('vid saved to %s. \n', vidName);
    end % if save_vid % Save video
end % for eidx = 1:length(err_rate_list) % FOR EACH ERROR RATES

fprintf(2, 'Done. \n');

%%

