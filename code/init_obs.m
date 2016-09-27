function obs = init_obs()
MAX_OBS = 1E2;
obs.n = 0;
obs.obs = cell(MAX_OBS, 1);
for i = 1:MAX_OBS
    obs.obs{i}.pos   = zeros(1, 3);
    obs.obs{i}.vel   = zeros(1, 2);
    obs.obs{i}.color = rand(1, 3);
end


