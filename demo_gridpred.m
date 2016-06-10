ccc
%% 
ccc
rng('shuffle');
% INIT SIMULATION
nx = 200; xrange = [0 100*nx];
ny = 200; yrange = [0 100*ny];
vrange = [1000 3000];
wrange = [0 20];
rrange = [400 700];
nr_obs = 8;
err_rate_list = 30/100; 
maxtick = 200;
T = 0.1;
save_vid = 0;
plotflowdir = 1; % <= PLOT OPTION

% INIT RECURRENT FLOW NETWORK
[occflow.g1, occflow.l1, occflow.resize_rate, occflow.g2, occflow.l2] ...
    = parse_occflowparams( ...
    [    3.00 1.393 3.00 2.84 0.99 3.1230 2.7946 1.6778 0.1138 0.2955 0.9120 0.7100 0.2600  ...
    5.0000 1.6500 3.0000 0.7200 0.6300 8.6600 1.2100 4.0330 0.0720 0.5800 0.2800 0.6900 0.2300 0.5000] ...
    , xrange, yrange, nx, ny);
ginfo = set_grid(occflow.g1.xmin, occflow.g1.xmax, occflow.g1.nx, occflow.g1.ymin, occflow.g1.ymax, occflow.g1.ny);

% INIT FIGURE 
scrsz = get(0,'ScreenSize');
fig = figure(1); set(fig, 'Position', [200 200 1300 700]);
for err_rate = err_rate_list % FOR EACH ERROR RATES
    % INIT OBSTACLES
    obs4grid = init_obs4grid(occflow.g1, nr_obs, rrange, vrange, wrange);
    obs4grid_init = obs4grid;
    ems_total = 0;
    for tick = 1:maxtick
        iclk_init = clock;
        obs4grid = update_obs4grid(obs4grid, T);
        obs_grid_ref = get_obsgrid2(occflow.g1, obs4grid);
        % ADD NOISE
        obs_grid_meas = obs_grid_ref;
        flipidx = randsample(nx*ny, round(err_rate*nx*ny));
        obs_grid_meas(flipidx) = ~obs_grid_meas(flipidx);
        
        % OCCUPANCY FLOW
        iclk = clock;
        occflow.l1.curr_input = obs_grid_meas(:);
        occflow.l1 = occflow_wrapper(occflow.g1, occflow.l1, occflow.resize_rate);
        occflow.l2.curr_input = occflow.l1.binsmallmtx(:);
        occflow.l2 = occflow_wrapper(occflow.g2, occflow.l2, occflow.resize_rate);
        occflow_predmtx = imresize(reshape(occflow.l2.predvec, occflow.g2.ny, occflow.g2.nx), 1/occflow.resize_rate);
        ems_occflow = etime(clock, iclk)*1000;
        
        % OCCFLOW -> RGB
        rgb_gain2 = 0.3; rgb_th = 0.5; % rgb_th = occflow.l2.bin_threshold;
        [occflow.l2.rgbflowimg, valid_idx, u, v] ...
            = get_rgbflow(occflow.l2.context, occflow.l2.predvec, occflow.l2.nei.filter.shift_xyi ...
            , occflow.g2.nx, occflow.g2.ny, rgb_gain2, rgb_th);
        occflow.l2.rgbflowimg_resize = imresize(occflow.l2.rgbflowimg, 1/occflow.resize_rate);
        
        % OCCFLOW -> QUIVER
        quiver_rate   = 4E+1;
        min_quiver    = 10;
        max_quiver    = 25;
        resize_quiver = 0.8;
        robot.pos = [0 0 0];
        [xmesh, ymesh, ru, rv] = get_dirflow(u, v, valid_idx, robot, ginfo, quiver_rate, min_quiver, max_quiver, resize_quiver);
        
        % TERMINATE CONDITION
        out_count = 0;
        for i = 1:obs4grid.n
            obspos = obs4grid.obs{i}.pos;
            if obspos(1) < occflow.g1.axis(1) || obspos(1) > occflow.g1.axis(2) ...
                    || obspos(2) < occflow.g1.axis(3) || obspos(2) > occflow.g1.axis(4)
                out_count = out_count + 1;
            end
        end
        if out_count == obs4grid.n
            break;
        end
        
        % PLOT
        iclk_plot = clock;
        xm = 0.01; ym = 0.015; tfs = 20; tft = 'Times New Roman';
        colors = jet(obs4grid.n); subnx = 2; subny = 1;
        subaxes(fig, subny, subnx, 1, xm, ym); hold on;
        if ~exist('h1', 'var')
            h1 = imagesc(occflow.g1.xs, occflow.g1.ys, obs_grid_meas);
            colormap gray;
        else
            h1.CData = obs_grid_meas;
        end
        caxis([0 1]); axis equal off; axis(occflow.g1.axis);
        str = sprintf('[%02d] Input ', tick);
        if ~exist('ht1', 'var')
            ht1 = title(str, 'FontSize', tfs, 'FontName', tft);
        else
            ht1.String = str;
        end
        subaxes(fig, subny, subnx, 2, xm, ym); hold on;
        if ~exist('h2', 'var')
            if plotflowdir
                h2 = imagesc(occflow.g1.xs, occflow.g1.ys, occflow_predmtx);
                h3 = quiver(xmesh, ymesh, ru, rv, 'LineWidth', 2, 'AutoScale', 'off', 'Color', 'r');
                colormap gray;
            else
                h2 = image(occflow.g1.xs, occflow.g1.ys, occflow.l2.rgbflowimg_resize);
            end
        else
            if plotflowdir
                h2.CData = occflow_predmtx;
                h3.UData = ru; h3.VData = rv;
            else
                h2.CData = occflow.l2.rgbflowimg_resize;
            end
        end
        if ~exist('hobs', 'var')
            hobs = cell(obs4grid.n, 1);
            colors = lines(obs4grid.n);
            for j = 1:obs4grid.n
                pos = obs4grid.obs{j}.pos;
                r   = obs4grid.obs{j}.r;
                circlebd = get_circle(pos(1), pos(2), r+50, 20);
                hobs{j} = fill(circlebd(:, 1), circlebd(:, 2), colors(j, :) ...
                    , 'EdgeColor', colors(j, :), 'LineWidth', 3);
                set(hobs{j}, 'facealpha', 0.1);
            end
        else
            for j = 1:obs4grid.n
                pos = obs4grid.obs{j}.pos;
                r   = obs4grid.obs{j}.r;
                circlebd = get_circle(pos(1), pos(2), r+50, 20);
                hobs{j}.Vertices = circlebd;
            end
        end
        str = sprintf('Occupancy Flow (%.1f%% noise)', err_rate*100);
        if ~exist('ht2', 'var')
            ht2 = title(str, 'FontSize', tfs, 'FontName', tft);
        else
            ht2.String = str;
        end
        caxis([0 1]); axis equal off; axis(occflow.g1.axis);
        drawnow; 
        if save_vid
            set(fig,'PaperPositionMode','auto')
            print (fig , '-dpng', ['pics4vid/fig_gridseq_', num2str(tick, '%03d'), '.png']) ;
        end
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
        for ii = 1:tick
            fprintf('%d/%d \n', ii, tick);
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
ccc