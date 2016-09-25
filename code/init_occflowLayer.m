function layer = init_occflowLayer( ...
    g, neixres, neiyres, neisig, nei4uxres, nei4uyres, nei4usig ...
    , minthreshold, maxthreshold, reinitval ...
    , intensifyrate, nocc_attenuaterate, unknown_attenuaterate ...
    , sigm_coef, pred_threshold, bin_threshold, occval, noccval ...
    )
% 
% Initialize occupancy flow layer
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%       Parameters       %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Neighborhood for context propagation
layer.neixres = neixres;
layer.neiyres = neiyres;
layer.neisig  = neisig;

% Neighborhood for uncertainty in acceleration
layer.nei4uxres = nei4uxres;
layer.nei4uyres = nei4uyres;
layer.nei4usig = nei4usig;

% Set neighboorhood structure
roundshape = 0;
layer.nei = set_nei(g, neixres, neiyres, neisig, roundshape);
layer.nei4u = set_nei4u(g, nei4uxres, nei4uyres, nei4usig, roundshape);

% Update parameters
layer.minthreshold          = minthreshold;
layer.maxthreshold          = maxthreshold;
layer.reinitval             = reinitval;
layer.intensifyrate         = intensifyrate;
layer.nocc_attenuaterate    = nocc_attenuaterate;
layer.unknown_attenuaterate = unknown_attenuaterate;
layer.sigm_coef             = sigm_coef;

% first-to-second layer
layer.pred_threshold        = pred_threshold;
layer.bin_threshold         = bin_threshold;

% Gridmap property 
layer.occval                = occval;
layer.noccval               = noccval;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%        Variables       %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
layer.prev_gridvec   = zeros(g.n, 1);
layer.predvec        = zeros(g.n, 1);
layer.context        = layer.reinitval*ones(g.n, layer.nei.filter.n);

layer.binpredvec     = zeros(g.n, 1);
layer.binpredmtx     = zeros(g.ny, g.nx);
layer.smallmtx       = zeros(round(g.ny/2), round(g.nx/2));
layer.binsmallmtx    = zeros(round(g.ny/2), round(g.nx/2));

