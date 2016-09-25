function plot_obs4grid(obs4grid, colorful)

if nargin == 1
    colorful = 1;
end

colors = jet(obs4grid.n);
for j = 1:obs4grid.n
    pos = obs4grid.obs{j}.pos;
    r   = obs4grid.obs{j}.r;
    
    circlebd = get_circle(pos(1), pos(2), r+50, 20);
    
    if colorful
        h = fill(circlebd(:, 1), circlebd(:, 2), colors(j, :) ...
            , 'EdgeColor', colors(j, :), 'LineWidth', 3);
        set(h,'facealpha', 0.1);
        plot_arrow(pos(1:2), r, pos(3), colors(j, :), 3);
    else
        ccolor = 'k';
        h = fill(circlebd(:, 1), circlebd(:, 2), ccolor ...
            , 'EdgeColor', ccolor, 'LineWidth', 3);
        set(h,'facealpha', 0.1);
        plot_arrow(pos(1:2), r, pos(3), ccolor, 3);
    end
    
    if 0
        vel = obs4grid.obs{j}.vel;
        text(pos(1) + 2*r, pos(2) + r ...
            , sprintf('%.1fm/s', vel(1)/1000) ...
            , 'BackgroundColor', 'w', 'EdgeColor', 'b');
    end
end

