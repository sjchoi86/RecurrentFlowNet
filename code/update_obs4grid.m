function obs4grid = update_obs4grid(obs4grid, T)

if nargin == 1
    T = 0.2;
end

for i = 1:obs4grid.n
    x = obs4grid.obs{i}.pos(1);
    y = obs4grid.obs{i}.pos(2);
    d = obs4grid.obs{i}.pos(3);
    v = obs4grid.obs{i}.vel(1);
    w = obs4grid.obs{i}.vel(2);
    
    nx = x + T*v*cos(d*pi/180);
    ny = y + T*v*sin(d*pi/180);
    nd = d + T*w;
    
    obs4grid.obs{i}.pos = [nx ny nd];
end
