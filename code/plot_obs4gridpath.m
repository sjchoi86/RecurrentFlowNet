function plot_obs4gridpath(obs4grid_init, T)


obs4grid = obs4grid_init;
colors   = jet(obs4grid.n);
horizon  = 20;
paths    = cell(obs4grid.n, 1);
for j = 1:obs4grid.n
    paths{j} = zeros(horizon, 2);
end
for i = 1:horizon
    obs4grid = update_obs4grid(obs4grid, T);
    for j = 1:obs4grid.n
        pos = obs4grid.obs{j}.pos;
        paths{j}(i, :) = pos(1:2);
    end
end
for j = 1:obs4grid.n
    % plot(paths{j}(:, 1), paths{j}(:, 2), ':', 'Color', colors(j, :), 'LineWidth', 3);
end

