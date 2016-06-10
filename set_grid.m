function g = set_grid(xmin, xmax, nx, ymin, ymax, ny)

xlen = xmax - xmin;
ylen = ymax - ymin;
g.xmin  = xmin;
g.xmax  = xmax;
g.ymin  = ymin;
g.ymax  = ymax;
g.xlen  = xlen; g.nx = nx;  
g.ylen  = ylen; g.ny = ny;
g.xunit = xlen / nx;
g.yunit = ylen / ny;
g.grid  = rand(g.ny, g.nx); % empty grids
g.n     = g.nx * g.ny;
g.xs    = linspace(g.xmin, g.xmax, g.nx); 
g.ys    = linspace(g.ymin, g.ymax, g.ny);
[g.xmesh, g.ymesh] = meshgrid(g.xs, g.ys);
xlist   = g.xmesh(:); 
ylist   = g.ymesh(:); 
g.xy    = [xlist ylist];
[xitemp, yitemp] = meshgrid(1:g.nx, 1:g.ny);
yilist  = yitemp(:); xilist = xitemp(:); g.xyidx = [xilist yilist]; % <= This may not be necessary
g.axis  = [xmin xmax ymin ymax];
