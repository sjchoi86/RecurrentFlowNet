function [rgbflowimg, valid_idx, u, v] ...
    = get_rgbflow(context, predvec, nei_shift_xyi ...
    , xres, yres, gain, th)
%
% Get color-coded RGB image from context vector
%
npnt = xres*yres;
u = zeros(npnt, 1);
v = zeros(npnt, 1);
for j = 1:npnt
    col = context(j, :);
    vval = nei_shift_xyi(:, 2);
    uval = nei_shift_xyi(:, 1);
    vmean = col*vval;
    umean = col*uval;
    v(j) = vmean;
    u(j) = umean;
end
valid_idx  = predvec > th;
% rgbflowvec = flow_visualization_blackbg( gain*u, gain*v, valid_idx);
rgbflowvec = flow_visualization_whitebg( gain*u, gain*v, valid_idx);
rgbflowimg = reshape(rgbflowvec, [yres, xres, 3]);

u = reshape(u, yres, xres);
v = reshape(v, yres, xres);