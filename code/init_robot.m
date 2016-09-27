function robot = init_robot()

% METER SCALE [M]

% POSITION
robot.pos = [0 0 0];

% VELOCITY
robot.u = [0 0];

% RADIUS
robot.r = 2.0;

% RANGEFINDER SENSOR
robot.rfs_dist = 50; 
robot.rfs_def = 360;
robot.nr_rfs = 300;
robot.rfs_degs = linspace(-robot.rfs_def/2, robot.rfs_def/2, robot.nr_rfs);
robot.rfs_dists = robot.rfs_dist*ones(1, robot.nr_rfs);
