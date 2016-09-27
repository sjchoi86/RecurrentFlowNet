function fig = plot_navirfs(fig, axisinfo, robot, sim, obs, gridmap ...
    , occflow_predmtx, xmesh, ymesh, ru, rv)

persistent first_flag h
if isempty(first_flag)
    first_flag = true;
end

% TITLE
tfs = 30; tfn = 'Times New Roman';
afs = 20; afn = 'Times New Roman';
title_str = sprintf('[%d] %.1fsec (%.1fkm/h, %.1fdeg/s)' ...
    , sim.tick, sim.sec, robot.u(1)*3.6, robot.u(2));

% MESHGIRD FOR OCCUPANCY FLOW
[xtemp, ytemp] = meshgrid(linspace(gridmap.xmin, gridmap.xmax ...
    , gridmap.xres) ...
    , linspace(gridmap.ymin, gridmap.ymax, gridmap.yres));
xvec = xtemp(:);
yvec = ytemp(:);
xyvec = [xvec yvec];
c = cos(robot.pos(3)*pi/180);
s = sin(robot.pos(3)*pi/180);
rotmat = [c s ; -s c];
xyvec = xyvec * rotmat ...
    + repmat(robot.pos(1:2), gridmap.xres*gridmap.yres, 1);
xvec = xyvec(:, 1);
yvec = xyvec(:, 2);
xmesh_grid = reshape(xvec, gridmap.yres, gridmap.xres);
ymesh_grid = reshape(yvec, gridmap.yres, gridmap.xres);
% OBSTACLE BOUNDARIES
obs_shapes = cell(obs.n, 1);
for obsidx = 1:obs.n
    obs_pos = obs.obs{obsidx}.pos; obs_radius = obs_pos(3)*pi/180;
    obs_shape = obs.obs{obsidx}.shape;
    obs_rotmtx = [cos(obs_radius) sin(obs_radius) ...
        ; -sin(obs_radius) cos(obs_radius)];
    obs_shape = obs_shape*obs_rotmtx ...
        + repmat(obs_pos(1:2), size(obs_shape, 1), 1);
    obs_shapes{obsidx} = obs_shape;
end
% ROBOT BOUNDARY + FUTURE POSITIONS
robot_bd = get_circle(robot.pos(1), robot.pos(2), robot.r, 20);
robot_pos = robot.pos;
robot_u = robot.u;
robot_bds = cell(5, 1);
T = sim.T*2;
for t = 1:5
    robot_pos(1:2) = robot_pos(1:2) ...
        + T*robot_u(1)*[cos(robot_pos(3)*pi/180) sin(robot_pos(3)*pi/180)];
    robot_pos(3) = robot_pos(3) + T*robot_u(2);
    robot_bds{t} = get_circle(robot_pos(1), robot_pos(2), robot.r, 20);
end
robot_heading = get_arrow(robot.pos(1:2), robot.r, robot.pos(3));

% ROBOT RFS BOUNDARIES
rfs_bd = zeros(robot.nr_rfs+2, 2);
for rfsbdi = 1:robot.nr_rfs
    rfs_deg = robot.pos(3) + robot.rfs_degs(rfsbdi);
    rfs_bd(rfsbdi+1, :) = robot.pos(1:2)  ...
        + (robot.r+robot.rfs_dists(rfsbdi)) ...
        *[cos(rfs_deg*pi/180) sin(rfs_deg*pi/180)];
end
rfs_bd(1, :) = robot.pos(1:2);
rfs_bd(end, :) = robot.pos(1:2);

% SURFACE
cdata = gridmap.map;
% cdata = occflow_predmtx;

% --------------------------------------------------------------- %
if first_flag
    first_flag = false;
    hold on;
    % AXIS & LABEL
    grid on;
    xlabel('X [m]'); ylabel('Y [m]');
    set(gca, 'FontSize', afs, 'FontName', afn);
    % PREDICTED OCCUPANCY GRID MAP
    
    h.surface = surface('xdata', xmesh_grid, 'ydata', ymesh_grid ...
        , 'zdata', zeros(gridmap.yres, gridmap.xres) ...
        , 'cdata', cdata, 'FaceColor', 'TextureMap' ...
        , 'EdgeColor','None', 'LineStyle', 'None');
    colormap gray; caxis([0 1]);
    % OBSTACLES
    for obsidx = 1:obs.n
        h.obs_shapes{obsidx} = plot(obs_shapes{obsidx}(:, 1) ...
            , obs_shapes{obsidx}(:, 2), 'b-', 'LineWidth', 3);
    end
    % ROBOT
    for t = 1:5
        h.robot_bds{t} = plot(robot_bds{t}(:, 1), robot_bds{t}(:, 2), '-' ...
            , 'Color', 0.5*[1 1 1], 'LineWidth', 1);
    end
    h.robot_bd = plot(robot_bd(:, 1), robot_bd(:, 2), '-' ...
        , 'Color', 'g', 'LineWidth', 3);
    h.robot_arrow{1} = plot(robot_heading.l1(:, 1), robot_heading.l1(:, 2), '-' ...
        , 'Color', 'g', 'LineWidth', 3);
    h.robot_arrow{2} = plot(robot_heading.l2(:, 1), robot_heading.l2(:, 2), '-' ...
        , 'Color', 'g', 'LineWidth', 3);
    h.robot_arrow{3} = plot(robot_heading.l3(:, 1), robot_heading.l3(:, 2), '-' ...
        , 'Color', 'g', 'LineWidth', 3);
    
    % RFS BOUNDARY
    h.rfs_bd = plot(rfs_bd(:, 1), rfs_bd(:, 2), '-' ...
        , 'Color', 0.7*[1 1 1], 'LineWidth', 1);
    % PREDICTED ARROWS (QUIVER)
    h.quiver = quiver(xmesh, ymesh, ru, rv ...
        , 'LineWidth', 1, 'AutoScale', 'off', 'Color', 'r');
    axis equal; axis(axisinfo);
    % TITLE
    h.title = title(title_str, 'FontSize', tfs, 'FontName', tfn);
    hold off;
else
    % PREDICTED OCCUPANCY GRID MAP
    h.surface.XData = xmesh_grid;
    h.surface.YData = ymesh_grid;
    h.surface.ZData = zeros(gridmap.yres, gridmap.xres);
    h.surface.CData = cdata;
    % OBSTACLES
    for obsidx = 1:obs.n
        h.obs_shapes{obsidx}.XData = obs_shapes{obsidx}(:, 1);
        h.obs_shapes{obsidx}.YData = obs_shapes{obsidx}(:, 2);
    end
    % ROBOT
    h.robot_bd.XData = robot_bd(:, 1);
    h.robot_bd.YData = robot_bd(:, 2);
    for t = 1:5
        h.robot_bds{t}.XData = robot_bds{t}(:, 1);
        h.robot_bds{t}.YData = robot_bds{t}(:, 2);
    end
    h.robot_arrow{1}.XData = robot_heading.l1(:, 1);
    h.robot_arrow{1}.YData = robot_heading.l1(:, 2);
    h.robot_arrow{2}.XData = robot_heading.l2(:, 1);
    h.robot_arrow{2}.YData = robot_heading.l2(:, 2);
    h.robot_arrow{3}.XData = robot_heading.l3(:, 1);
    h.robot_arrow{3}.YData = robot_heading.l3(:, 2);
    % RFS BOUNDARY
    h.rfs_bd.XData = rfs_bd(:, 1);
    h.rfs_bd.YData = rfs_bd(:, 2);
    % PREDICTED ARROWS
    h.quiver.XData = xmesh;
    h.quiver.YData = ymesh;
    h.quiver.UData = ru;
    h.quiver.VData = rv;
    % TITLE
    h.title.String = title_str;
end
% --------------------------------------------------------------- %
drawnow;
