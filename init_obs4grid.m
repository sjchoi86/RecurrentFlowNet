function obs4grid = init_obs4grid(g, n, rrange, vrange, wrange)

if nargin == 4
    wrange = 10;
end

if numel(rrange) == 1, rrange = [rrange rrange]; end
if numel(vrange) == 1, vrange = [vrange vrange]; end
if numel(wrange) == 1, wrange = [wrange wrange]; end

obs4grid.n = n;
obs4grid.obs = cell(n, 1);
for i = 1:n
    obs4grid.obs{i}.r   = rrange(1) + (rrange(2)-rrange(1))*rand; % [mm]
    obs4grid.obs{i}.pos = [g.xmin g.ymin 0] + [g.xlen*rand g.ylen*rand 360*rand];
    obs4grid.obs{i}.vel = [vrange(1)+(vrange(2)-vrange(1))*rand ...
        wrange(1)+(wrange(2)-wrange(1))*rand];
end


