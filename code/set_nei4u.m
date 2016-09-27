function nei = set_nei4u(g, neixres, neiyres, neisig, roundshape)

nei.filter     = set_neifilter(neixres, neiyres, neisig, roundshape);
nei.nei_idx    = zeros(g.n, nei.filter.n); 
nei.nei_weight = zeros(g.n, nei.filter.n);
nei.filnter_n  = nei.filter.n;
g_n = g.n;
g_xyidx = g.xyidx;
nei_filter_n = nei.filter.n;
nei_filter_shift_xyi = nei.filter.shift_xyi;
g_nx = g.nx;
g_ny = g.ny;
nei_filter_weight = nei.filter.weight;
nei_nei_idx = zeros(size(nei.nei_idx));
nei_nei_weight = zeros(size(nei.nei_weight));
% ------------------------------------------------------------------ %
[nei_nei_idx, nei_nei_weight] ...
    = set_nei4u_unit_mex(nei_nei_idx, nei_nei_weight ...
    , g_n, g_xyidx, nei_filter_n, nei_filter_shift_xyi ...
    , g_nx, g_ny, nei_filter_weight);
% ------------------------------------------------------------------ %
nei.nei_idx = nei_nei_idx;
nei.nei_weight = nei_nei_weight;


function nei = set_neifilter(xres, yres, sig, roundshape)
%
% Set neighbor for occupancy flow
%
if nargin == 2
    roundshape = 1;
end

center_xi = (xres+1)/2;
center_yi = (yres+1)/2;

% set filter shape (2d Gaussian)
nei.f = gaussian_filter(xres, yres, sig);

% make it circle!
if roundshape
    nei.f = getroundfilter(nei.f);
end

% normalize value so that the center pixel to have 1
nei.f = nei.f / nei.f(center_xi, center_yi);

% number of neighbors
nei.n = xres*yres;

% list of neighbors and weights
[mesh_x, mesh_y] = meshgrid(1:xres, 1:yres);
nei.shift_xyi = [mesh_x(:) mesh_y(:)] - repmat([center_xi, center_yi], nei.n, 1);
nei.weight = zeros(nei.n, 1);
for i = 1:nei.n
    nei.weight(i) = nei.f(center_xi + nei.shift_xyi(i, 1), center_yi + nei.shift_xyi(i, 2));
end

% handle zeros
zidx = find(nei.weight == 0);
nei.shift_xyi(zidx, :) = [];
nei.weight(zidx, :) = [];
nei.n = nei.n - length(zidx);

nei.shift_ij = [nei.shift_xyi(:, 2) nei.shift_xyi(:, 1)];

function round_filter = getroundfilter(square_filter)

round_filter = square_filter;
lenx = size(round_filter, 2);
leny = size(round_filter, 1);
lenx_half = (lenx+1)/2;
leny_half = (leny+1)/2;
for xi = 1:lenx
    for yi = 1:leny
        r = sqrt((xi-lenx_half)^2 + (yi-leny_half)^2);
        if r > max(lenx_half, leny_half)-1
            round_filter(leny-yi+1, xi) = 0;
        end
    end
end

function h = gaussian_filter(xres, yres, sig)
% set filter shape (2d Gaussian)
ind = -floor(xres/2) : floor(yres/2);
[X, Y] = meshgrid(ind, ind);
%// Create Gaussian Mask
h = exp(-(X.^2 + Y.^2) / (2*sig*sig));
%// Normalize so that total area (sum of all weights) is 1
h = h / sum(h(:));
