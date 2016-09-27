ccc
%%
ccc
global key_pressed; key_pressed = '';

% INITIALIZE
sim = init_sim(600, 0.05);
robot = init_robot();
obs = init_obs();
ginfo = set_grid(-50, 50, 200, -50, 50, 200);
% ADD WALLS
wallbd = [120 20 ; -30 20 ; -30 -20 ; 120 -20 ; 120 20];
obs = add_obs(obs, [0 0 0], [0 0], wallbd, 'k');
% ADD MOVING OBJECTS (POSSIBLY HUMANS, HOPELY..)
nr_peds = 10;
obs = add_peds(obs, nr_peds, wallbd, robot);
% INIT HIERARCHICAL RECURRENT FLOW NETWORK
[occFlow.g1, occFlow.l1, occFlow.resize_rate, occFlow.g2, occFlow.l2, esec] ...
    = parse_occflowparams( [ ...
    5.0 1.393 3.0 2.84 0.99 3.123 2.7946 1.6778 0.1138 0.2955 0.9120 0.7100 0.2600  ...
    5.0 1.650 3.0 0.72 0.63 8.660 1.2100 4.0330 0.0720 0.5800 0.2800 0.6900 0.2300  ...
    0.5 ] ...
    , [ginfo.xmin ginfo.xmax], [ginfo.ymin ginfo.ymax], ginfo.nx, ginfo.ny);
fprintf('HIERARCHICAL RECURRENT FLOW NETWORK INITIALIZED (TOOK %.2fsec). \n', esec);

% FIGURE
axisinfo = [-50 130 -40 40];
scrsz = get(0,'ScreenSize');
fig = figure(1);
set(fig, 'NumberTitle', 'off', 'Position' ...
    , [scrsz(3)*0.1 scrsz(4)*0.2 scrsz(3)*0.8 scrsz(4)*0.6] ...
    , 'KeyPressFcn', @keyDownListener)
axes('Parent', fig, 'Position', [0.05, 0.05, 0.9, 0.9] );
% RUN
while sim.flag
    
    % ------------------------------------------------------- %
    %                     KEYBD HANDLER                       %
    % ------------------------------------------------------- %
    switch key_pressed
        case 'p', sim.pause = ~sim.pause;
            if sim.pause
                fprintf('PAUSED. \n');
            else
                fprintf('RESUME. \n');
            end
        case 'q',           sim.flag = 0;
        case 'uparrow',     robot.u(1) = robot.u(1) + 10;
        case 'downarrow',   robot.u(1) = robot.u(1) - 10;
        case 'leftarrow',   robot.u(2) = robot.u(2) + 30;
        case 'rightarrow',  robot.u(2) = robot.u(2) - 30;
        case 'space',       robot.u = [0 0];
        otherwise
    end
    key_pressed = '';
    
    if sim.pause == 0
        % ------------------------------------------------------- %
        %                         UPDATE                          %
        % ------------------------------------------------------- %
        iclk = clock;
        sim = update_sim(sim);
        obs = update_obs(obs, sim);
        robot = update_robot(robot, sim);
        ems_update = etime(clock, iclk)*1000;
        
        % ------------------------------------------------------- %
        %                       GET GRIDMAP                       %
        % ------------------------------------------------------- %
        iclk = clock;
        robot = update_rfs(robot, obs);
        mlevel = 2; orgmargin = 2; % [M]
        gridmap = get_gridmap(robot.rfs_result_xy ...
            , robot.rfs_valid_idx, mlevel, ginfo, orgmargin);
        ems_gridmap = etime(clock, iclk)*1000;
        
        % ADD ERRORS TO THE GRIDMAP
        err_rate = 0.1;
        flipidx = randsample(ginfo.n, round(err_rate*ginfo.n));
        gridmap.map(flipidx) = ~gridmap.map(flipidx);
        
        % ------------------------------------------------------- %
        %                RUN OCCUPANCY FLOW ALGORITHM             %
        % ------------------------------------------------------- %
        iclk = clock;
        [occFlow, occflow_predmtx, xmesh, ymesh, ru, rv] ...
            = hrfn(occFlow, robot, ginfo, gridmap);
        ems_occflow = etime(clock, iclk)*1000;
    end
    
    % ------------------------------------------------------- %
    %                            PLOT                         %
    % ------------------------------------------------------- %
    iclk = clock;
    fig = plot_navirfs(fig, axisinfo, robot, sim, obs, gridmap ...
        , occflow_predmtx, xmesh, ymesh, ru, rv);
    ems_plot = etime(clock, iclk)*1000;
    
    if 0
        fprintf('update: %.1fms gridmap: %.1fms occflow: %.1fms plot: %.1fms \n' ...
            , ems_update, ems_gridmap, ems_occflow, ems_plot);
    end
end
fprintf(2, 'Done. \n');


%%























