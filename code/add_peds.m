function obs = add_peds(obs, nr_peds, wallbd, robot)
%
% ADD PEDESTRIANS INSIDE THE WALLS WITHOUT BEING TOO CLOSE TO THE ROBOT
%
nr_added = 0;
minxy = min(wallbd);
maxxy = max(wallbd);
flag = 1;
while flag
    xrand = minxy(1) + (maxxy(1)-minxy(1))*rand;
    yrand = minxy(2) + (maxxy(2)-minxy(2))*rand;
    dist2robot = norm([xrand yrand] - robot.pos(1:2)); % [M]
    if dist2robot > 3 % MAKE SURE THE PEDESTRIAN IS FAR FROM THE ROBOT (3M)
        drand = 360*rand;
        vrand = 0;
        wrand = 0;
        obs = add_obs(obs, [xrand yrand drand], [vrand wrand]);
        nr_added = nr_added + 1;
    end
    
    if nr_added >= nr_peds  
        flag = 0;
    end
end
