function obs = add_obs(obs, pos, u, shape, rgb_color)

if nargin == 3
    obs_r = 2;
    shape = get_ellipse(0, 0, 0, obs_r, 0.75, 10);
    shape = make_boundary(shape);
    rgb_color = rand(1, 3);
end

obs.n = obs.n + 1;
n     = obs.n;
obs.obs{n}.pos   = pos;  
obs.obs{n}.shape = shape; 
obs.obs{n}.vel   = u;     
obs.obs{n}.color = rgb_color;
obs.obs{n}.sec   = 0;


function boundary = make_boundary(corners)
boundary = [corners ; corners(1, :)];

