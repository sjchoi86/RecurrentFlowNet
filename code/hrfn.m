function [occFlow, occflow_predmtx, xmesh, ymesh, ru, rv] ...
    = hrfn(occFlow, robot, ginfo, gridmap)
%
% HIERARCHICAL RECURRENT FLOW NETWORK
%
occFlow.l1.curr_input = gridmap.map(:);
occFlow.l1 = occflow_wrapper(occFlow.g1, occFlow.l1, occFlow.resize_rate);
occFlow.l2.curr_input = occFlow.l1.binsmallmtx(:);
occFlow.l2 = occflow_wrapper(occFlow.g2, occFlow.l2, occFlow.resize_rate);
occflow_predmtx = imresize(reshape(occFlow.l2.predvec, occFlow.g2.ny, occFlow.g2.nx) ...
    , 1/occFlow.resize_rate);

% ------------------------------------------------ %
%                  OCCFLOW -> RGB                  % 
% ------------------------------------------------ %
flow_gain = 0.3;
flow_th = occFlow.l2.bin_threshold;
[occFlow.l2.rgbflowimg, valid_idx, u, v] ...
    = get_rgbflow(occFlow.l2.context, occFlow.l2.predvec, occFlow.l2.nei.filter.shift_xyi ...
    , occFlow.g2.nx, occFlow.g2.ny, flow_gain, flow_th);
occFlow.l2.rgbflowimg_resize = imresize(occFlow.l2.rgbflowimg, 1/occFlow.resize_rate);

% ------------------------------------------------ %
%                 OCCFLOW -> QUIVER                %
% ------------------------------------------------ %
quiver_rate   = 0.15;
min_quiver    = 0;
max_quiver    = 30;
resize_quiver = 0.5;
[xmesh, ymesh, ru, rv] ...
    = get_dirflow(u, v, valid_idx, robot, ginfo, quiver_rate ...
    , min_quiver, max_quiver, resize_quiver);
