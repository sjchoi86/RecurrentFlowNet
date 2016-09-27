function [xtemp, ytemp, ru, rv] ...
    = get_dirflow(u, v, valid_idx, robot, ginfo, quiver_rate ...
    , min_quiver, max_quiver, resize_rate)

% Quiver plot
temp_idx = find(valid_idx ~= 1);
u(temp_idx) = 0; v(temp_idx) = 0;
u = quiver_rate*u;
v = quiver_rate*v;
min_val = min_quiver*quiver_rate;
max_val = max_quiver*quiver_rate;
temp_idx = find(abs(u) < min_val);
u(temp_idx) = 0;
temp_idx = find(abs(v) < min_val);
v(temp_idx) = 0;
u = min(u, max_val);
v = min(v, max_val);
u = max(u, -max_val);
v = max(v, -max_val);

ny_res = round(ginfo.ny*resize_rate);
nx_res = round(ginfo.nx*resize_rate);
[xtemp, ytemp]  = meshgrid(linspace(ginfo.xmin, ginfo.xmax, nx_res) ...
    , linspace(ginfo.ymin, ginfo.ymax, ny_res));

xvec = xtemp(:); yvec = ytemp(:); xyvec = [xvec yvec];
deg = robot.pos(3); c = cos(deg*pi/180); s = sin(deg*pi/180);
rotmat = [c s ; -s c];
xyvec  = xyvec * rotmat + repmat(robot.pos(1:2), nx_res*ny_res, 1);
xvec   = xyvec(:, 1); yvec = xyvec(:, 2);
xtemp  = reshape(xvec, ny_res, nx_res); ytemp = reshape(yvec, ny_res, nx_res);

ru = resizem(u, [ny_res nx_res]);
rv = resizem(v, [ny_res nx_res]);

ru_vec = ru(:);
rv_vec = rv(:);

ruv_vec = [ru_vec rv_vec];
ruv_vec = ruv_vec * rotmat;

ru = reshape(ruv_vec(:, 1), ny_res, nx_res);
rv = reshape(ruv_vec(:, 2), ny_res, nx_res);




