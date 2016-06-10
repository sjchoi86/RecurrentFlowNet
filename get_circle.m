function circlebd = get_circle(x, y, r, n)
%
% Draw Circle 
%
ang = linspace(0, 2*pi, n); 
xp = r*cos(ang);
yp = r*sin(ang); 

% Circle boundary 
circlebd = repmat([x, y], n, 1) + [xp' , yp'];
circlebd = [circlebd ; circlebd(end, :)];

