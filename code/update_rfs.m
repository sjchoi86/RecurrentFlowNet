function robot = update_rfs(robot, obs)

% EMULATE RFS
D2R    = pi/180;
nr_rfs = robot.nr_rfs;
result = robot.rfs_dist*ones(1, nr_rfs);
for i = 1:robot.nr_rfs
    rfs_deg = robot.pos(3) + robot.rfs_degs(i);
    rfs_rad = rfs_deg * D2R;
    rfs_fr  = robot.pos(1:2);
    rfs_to  = robot.pos(1:2) ...
        + (robot.r+robot.rfs_dist)*[cos(rfs_rad) sin(rfs_rad)];
    min_dist2obs = robot.rfs_dist;
    obs_boundary = zeros(2, 1E3);
    nr_obs_b = 0;
    for j = 1:obs.n
        obs_pos      = obs.obs{j}.pos;
        obs_shape    = obs.obs{j}.shape;
        r = obs_pos(3)*pi/180;
        rot_mat = [cos(r) sin(r) ; -sin(r) cos(r) ];
        obs_shape = obs_shape*rot_mat;
        curr_obs_boundary = repmat(obs_pos(1:2), size(obs_shape, 1), 1) + obs_shape;
        curr_obs_boundary = [curr_obs_boundary' [NaN ; NaN]];
        
        nr_curr_obs_b = size(curr_obs_boundary, 2);
        obs_boundary(:, nr_obs_b+1:nr_obs_b + nr_curr_obs_b) = curr_obs_boundary;
        nr_obs_b = nr_obs_b + nr_curr_obs_b;
    end
    obs_boundary = obs_boundary(:, 1:nr_obs_b);
    % Use InterX
    int_xy = InterX([rfs_fr(1) rfs_to(1) ; rfs_fr(2), rfs_to(2)], obs_boundary);
    if ~isempty(int_xy)
        xi = int_xy(1, :);
        yi = int_xy(2, :);
        for k = 1:length(xi)
            dist = norm([ robot.pos(1)-xi(k), robot.pos(2)-yi(k) ]);
            dist = dist - robot.r;
            if dist < min_dist2obs
                min_dist2obs = dist;
            end
        end
    end
    
    result(i) = min_dist2obs;
end
robot.rfs_dists = result;


% GET XY END POSITION
result_xy       = zeros(nr_rfs, 2);
valid_idx       = zeros(1, nr_rfs);
for i = 1:nr_rfs
    rfs_deg = robot.rfs_degs(i);
    rfs_rad = rfs_deg * D2R;
    rfs_x = (robot.rfs_dists(i) + robot.r)*cos(rfs_rad);
    rfs_y = (robot.rfs_dists(i) + robot.r)*sin(rfs_rad);
    result_xy(i, :) = [rfs_x, rfs_y];
    if robot.rfs_dists(i) ~= robot.rfs_dist
        valid_idx(i) = 1;
    else
        valid_idx(i) = 0;
    end
end
robot.rfs_result_xy = result_xy;
robot.rfs_valid_idx = valid_idx;

