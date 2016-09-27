function [nei_nei_idx, nei_nei_weight] ...
    = set_nei4u_unit(nei_nei_idx, nei_nei_weight ...
    , g_n, g_xyidx, nei_filter_n, nei_filter_shift_xyi ...
    , g_nx, g_ny, nei_filter_weight)

for i = 1:g_n
    curr_xyidx = g_xyidx(i, :);
    for j = 1:nei_filter_n
        shift_xyidx = nei_filter_shift_xyi(j, :);
        nei_xyidx = curr_xyidx + shift_xyidx;
        if nei_xyidx(1) > 0 && nei_xyidx(2) > 0 ...
                && nei_xyidx(1) <= g_nx && nei_xyidx(2) <= g_ny
            vec_idx = g_ny*(nei_xyidx(1)-1) + nei_xyidx(2);
            nei_nei_idx(i, j) = vec_idx;
            nei_nei_weight(i, j) = nei_filter_weight(j);
        else
            nei_nei_idx(i, j) = 1;
            nei_nei_weight(i, j) = 0;
        end
    end
end
% MAKE ROW SUM TO ONE
for i = 1:g_n
    nei_nei_weight(i, :) = nei_nei_weight(i, :) / sum(nei_nei_weight(i, :));
end