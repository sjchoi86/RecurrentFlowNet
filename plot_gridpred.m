function fig = plot_gridpred(fig, obs4grid, occFlow, obs_grid_meas ...
    , tick, plot_dir, occflow_predmtx, ru, rv, err_rate, xmesh, ymesh, sec ...
    , ems_occflow)

persistent first_flag h1 ht1 h2 ht2 h3 hobs

if isempty(first_flag)
    first_flag = true;
end

if first_flag
    h1 = '';
    ht1 = '';
    h2 = '';
    h3 = '';
    hobs = '';
    first_flag = false;
end
% ----------------------------------------------------------
tfs = 20; tft = 'Times New Roman';
str = sprintf('[%02d][%.2fsec] Input ', tick, sec);
if isempty(h1)
    axes('Parent', fig, 'Position', [0.04, 0.08, 0.46, 0.86] );     
    hold on;
    h1 = imagesc(occFlow.g1.xs, occFlow.g1.ys, obs_grid_meas);
    colormap gray; caxis([0 1]); 
    axis equal; axis(occFlow.g1.axis);
    xlabel('X [m]'); ylabel('Y [m]'); set(gca, 'FontSize', 15);
    ht1 = title(str, 'FontSize', tfs, 'FontName', tft);
    hold off;
else
    h1.CData = obs_grid_meas;
    ht1.String = str;
end
% ----------------------------------------------------------


% ----------------------------------------------------------
str = sprintf('Occupancy Flow took %.1fms (%.1f%% noise)', ems_occflow, err_rate*100);
if isempty(h2)
    axes('Parent', fig, 'Position', [0.54, 0.08, 0.46, 0.86] );     
    hold on;
    if plot_dir
        h2 = imagesc(occFlow.g1.xs, occFlow.g1.ys, occflow_predmtx);
        h3 = quiver(xmesh, ymesh, ru, rv ...
            , 'LineWidth', 2, 'AutoScale', 'off', 'Color', 'r');
        colormap gray;
    else
        h2 = image(occFlow.g1.xs, occFlow.g1.ys ...
            , occFlow.l2.rgbflowimg_resize);
    end
    hobs = cell(obs4grid.n, 1);
    colors = lines(obs4grid.n);
    for j = 1:obs4grid.n
        pos = obs4grid.obs{j}.pos;
        r   = obs4grid.obs{j}.r;
        circlebd = get_circle(pos(1), pos(2), r, 20);
        hobs{j} = fill(circlebd(:, 1), circlebd(:, 2), colors(j, :) ...
            , 'EdgeColor', colors(j, :), 'LineWidth', 3);
        set(hobs{j}, 'facealpha', 0.1);
    end
    xlabel('X [m]'); ylabel('Y [m]'); set(gca, 'FontSize', 15);
    ht2 = title(str, 'FontSize', tfs, 'FontName', tft);
    caxis([0 1]); axis equal; axis(occFlow.g1.axis);
    hold off;
else
    if plot_dir
        h2.CData = occflow_predmtx;
        h3.UData = ru; h3.VData = rv;
    else
        h2.CData = occFlow.l2.rgbflowimg_resize;
    end
    for j = 1:obs4grid.n
        pos = obs4grid.obs{j}.pos;
        r   = obs4grid.obs{j}.r;
        circlebd = get_circle(pos(1), pos(2), r, 20);
        hobs{j}.Vertices = circlebd;
    end
    ht2.String = str;
end
% ----------------------------------------------------------

drawnow;

