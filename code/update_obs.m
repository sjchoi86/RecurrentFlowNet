function obs = update_obs(obs, sim)
%
% UPDATE OBSTACLES
%
for i = 1:obs.n
    curr_vel = obs.obs{i}.vel;
    vel      = curr_vel(1);
    w_deg    = curr_vel(2);
    
    curr_pos = obs.obs{i}.pos;
    deg      = curr_pos(3);
    rad      = deg*pi/180;
    
    d_x      = vel*cos(rad)*sim.T;
    d_y      = vel*sin(rad)*sim.T;
    d_deg    = w_deg*sim.T;

    curr_pos(1:2) = curr_pos(1:2) + [d_x d_y];
    curr_pos(3)   = curr_pos(3) + d_deg;
    
    obs.obs{i}.pos = curr_pos;
end


