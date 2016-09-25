function obs_grid = get_obsgrid2(g, obs4grid)
%
% To handle multiple round-shaped obstacles 
%
obs_grid = zeros(g.ny, g.nx);
for j = 1:obs4grid.n
    obs_diff  = g.xy - repmat(obs4grid.obs{j}.pos(1:2), g.n, 1);
    obs_dist  = sqrt(obs_diff(:, 1).*obs_diff(:, 1) + obs_diff(:, 2).*obs_diff(:, 2));
    obs_valid = obs_dist <= obs4grid.obs{j}.r;
    obs_grid(obs_valid) = 1;
end