function robot = update_robot(robot, sim)
% UPDATE ROBOT POSITION

v = robot.u(1);
w = robot.u(2);
rad = robot.pos(3)*pi/180;

d_x   = v*cos(rad)*sim.T;
d_y   = v*sin(rad)*sim.T;
d_deg = w*sim.T;
robot.pos = robot.pos + [d_x d_y d_deg];

% MAXIMUM VELOCITY
if robot.u(1) > 40, robot.u(1) = 40; end;
if robot.u(1) < -40, robot.u(1) = -40; end;
