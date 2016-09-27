function [ellipsebd, p1, p2] = get_ellipse(x, y, d, r, e, n)
%
% (x, y): center
% d: deg
% r: radius to longer side
% e: eccentricity (0: circle 1:..?)
% n: #points
%

c = cos(d*pi/180); s = sin(d*pi/180);
x1 = x + r*s; y1 = y - r*c;
x2 = x - r*s; y2 = y + r*c;
a = 1/2*sqrt((x2-x1)^2+(y2-y1)^2);
b = a*sqrt(1-e^2);
t = linspace(0,2*pi, n);
X = a*cos(t);
Y = b*sin(t);
w = atan2(y2-y1,x2-x1);
x = (x1+x2)/2 + X*cos(w) - Y*sin(w);
y = (y1+y2)/2 + X*sin(w) + Y*cos(w);

p1 = [x1 y2];
p2 = [x2 y2];
ellipsebd = [x' y'];
