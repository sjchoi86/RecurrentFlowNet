function nei = set_nei(g, neixres, neiyres, neisig, roundshape)

nei.filter     = set_neifilter(neixres, neiyres, neisig, roundshape);
nei.nei_idx    = zeros(g.n, nei.filter.n); % 100 is a maximum number of neis per cell
nei.nei_weight = zeros(g.n, nei.filter.n);
nei.filnter_n  = nei.filter.n;
for i = 1:g.n
    curr_xyidx = g.xyidx(i, :);
    for j = 1:nei.filter.n 
        shift_xyidx = nei.filter.shift_xyi(j, :);
        nei_xyidx = curr_xyidx + shift_xyidx;
        if nei_xyidx(1) > 0 && nei_xyidx(2) > 0 && nei_xyidx(1) <= g.nx && nei_xyidx(2) <= g.ny
            vec_idx = g.ny*(nei_xyidx(1)-1) + nei_xyidx(2);
            nei.nei_idx(i, j) = vec_idx;
            nei.nei_weight(i, j) = nei.filter.weight(j);
        end
    end
end



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
nei.f = fspecial('gaussian', [xres yres], sig);

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

