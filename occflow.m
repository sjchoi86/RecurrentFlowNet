function [predvec, cgridvecprev, context, maxvec] ...
    ...
    = occflow( ...
    cgridvec, cgridvecprev, context ...
    , nei_idx, nei_weight, nei_filter_n ...
    , nei4u_idx, nei4u_weight, nei4u_filter_n ...
    , occval , minthreshold, maxthreshold, reinitval ...
    , intensifyrate, nocc_attenuaterate, unknown_attenuaterate, sigm_coef ...
    )
%
% Occupancy flow with vector input
%
% coder.extrinsic('clock')

% Compute indices first
newlyoccidx  = find(cgridvec == occval & cgridvecprev ~= occval);
nrnewlyocc   = length(newlyoccidx);
occidx       = find(cgridvec == occval);
nrocc        = length(occidx);
noccidx      = find(cgridvec ~= occval);
nrnocc       = length(noccidx);

% 1 Intensify newly occupied cells
% iclk = clock;
for j = 1:nrnewlyocc % For newly occupied cells
    coccidx  = newlyoccidx(j);
    curr_col = context(coccidx, :);
    if max(curr_col) < minthreshold
        context(coccidx, :) = reinitval;        % Reinitialize
    else
        updt_col = intensifyrate*curr_col;      % Intensify
        updt_col = min(updt_col, maxthreshold); % Max-thesholding
        context(coccidx, :) = updt_col;
    end
end
% ems_intensify = etime(clock, iclk)*1000;


% 2 Attenuate unoccupied cells
% iclk = clock;
for j = 1:nrnocc % For unoccupied cells
    cnoccidx = noccidx(j);
    curr_col = context(cnoccidx, :);
    updt_col = curr_col*nocc_attenuaterate;  % Attenuate
    context(cnoccidx, :) = updt_col;
end
% ems_attenuate = etime(clock, iclk)*1000;


% 3 Propagation
% iclk = clock;
for j = 1:nrocc % For occupied cells
    cpropidx   = occidx(j);
    curr_col   = context(cpropidx, :);
    cneicon    = nei_idx(cpropidx, :);
    cneiweight = nei_weight(cpropidx, :);
    for k = 1:nei_filter_n % For all neighbor cells
        contextval = curr_col(k);
        neiidx     = cneicon(k);
        weightval  = cneiweight(k);
        if neiidx ~= 0 % If properly connected, propagate
            origvontextval = context(neiidx, k);
            updtcontextval = weightval*contextval;
            updtcontextval = min(updtcontextval, maxthreshold); % Maximum value thresholding
            context(neiidx, k) = max(origvontextval, updtcontextval); % Make sure current context propagation does not weaken the flow information
        end
    end
end
% ems_propagate = etime(clock, iclk)*1000;

% 4 Uncertainty in acceleration
% iclk = clock;
tempcontext = zeros(size(context));
for k = 1:size(nei_idx, 1) % For all cells
    for j = 1:nei_filter_n % For all context level
        sumval = 0;
        for m = 1:nei4u_filter_n
            sumval = sumval + nei4u_weight(k, m)*context(nei4u_idx(k, m), j);
        end
        tempcontext(k, j) = sumval;
    end
end
context = tempcontext;
% ems_uia = etime(clock, iclk)*1000;

% 5 Prediction
% iclk = clock;
maxvec  = max(context')';
predvec = sigm(maxvec, sigm_coef);
% ems_predict = etime(clock, iclk)*1000;

% 6 Save previous grid
cgridvecprev = cgridvec;

if 0
    %     fprintf('%.2f + %.2f + %.2f + %.2f + %.2f \n' ...
    %         , ems_intensify, ems_attenuate, ems_propagate, ems_uia, ems_predict);
end

function y = sigm(x, sigm_a)
a = sigm_a; % sigm_a  <= if we increase the value, than the sigm function gets peaky!
y = (1-exp(-a*x))./(1+exp(-a*x));


