%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%   This file is part of the HCI-Correspondence Estimation Benchmark.
%
%   More information on this benchmark can be found under:
%       http://hci.iwr.uni-heidelberg.de/Benchmarks/
%
%    Copyright (C) 2011  <Sellent, Lauer>
%
%    This program is free software: you can redistribute it and/or modify
%    it under the terms of the GNU General Public License as published by
%    the Free Software Foundation, either version 3 of the License, or
%    (at your option) any later version.
%
%    This program is distributed in the hope that it will be useful,
%    but WITHOUT ANY WARRANTY; without even the implied warranty of
%    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
%    GNU General Public License for more details.
%
%    You should have received a copy of the GNU General Public License
%    along with this program.  If not, see <http://www.gnu.org/licenses/>.
%
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [ rgbImageDirection, rgbImageCyclic, rgbImageDifference ] = flow_visualization_whitebg( u, v, valid)
%This file provides the colour map and the visualization of optical flow 
%as they are used on the webpage http://hci.iwr.uni-heidelberg.de//Benchmarks/
%IN:    
%          u : the horizontal component of the flow field, a (height x width x 1)-matrix
%          v : the vertical component of the flow field, a (height x width x 1)-matrix
%IN [OPTIONAL]
%      valid : (height x width x 1)-matrix of bool values to indicate that
%              flow at this pixel should be visualized; 
%              default = true( height x width x 1 );
%      meanU : a scalar value for adjusting the difference-direction colour encoding horizontally, 
%              default = 0
%      meanV : a scalar value for adjusting the direction colour encoding horizontally,
%              default = 0
%OUT:
%    rgbImageDirection : (height x width x 3) uint8 image of the direction encoding
%       rgbImageCyclic : (height x width x 3) uint8 image of the cyclic encoding
%   rgbImageDifference : (height x width x 3) uint8 image of the difference-direction encoding

    %%%%%%%%%%%%%
    %Check input
    %%%%%%%%%%%%%
    if ~exist( 'valid', 'var' )
        valid = true( size( u ) );
        if ~exist( 'meanV', 'var' )
            meanV = 0;
            if ~exist( 'meanU', 'var' )
                meanU = 0;
            end
        end
    end

    %%%%%%%%%%%%%
    %Constants
    %%%%%%%%%%%%%
    
    nColors = 128;              %Number of colours in the map
    colorOffset = 15.0 / 16.0;  	%Shift colour map so that downward motion is yellow.

    saturationThreshold = 2;    %Used to compress the colour scheme to avoid oversaturation
    fullSaturationLength = 20; 	%At this length the motion is fully saturated in the direction encoding.
    cycleLength = 10;           %the pixel-displacement that fits into one cycle of colours in the cyclic representation
    
    inversPi = 1.0 / 3.1415926535897932384626433832795;

    [ height, width] = size( u );
    u = u( valid );
    v = v( valid );

    %%%%%%%%%%%%%
    %Calculate colour-map once.
    %%%%%%%%%%%%%

    [CM_r, CM_g, CM_b] = createColourmap( );


    %%%%%%%%%%%%%
    % Determine colour and saturation based on motion direction and length.
    %%%%%%%%%%%%%

    %Represent angle of motion via colour
    radian = atan2( v, u) * inversPi;   % in [-1,1]
    index = ( radian + 1 ) * 0.5;       % in [0, 1]

    [ r, g, b] = getColor( index );
    

    %Represent length via saturation, with white for small lengths
    saturation = sqrt( u.^2 + v.^2 );
    saturation = capSaturation( saturation );
    
    saturation = saturation/ capSaturation( fullSaturationLength );
    saturation( saturation > 1) = 1;    %threshold to [0,1]

%     imageR = zeros( height, width );
%     imageG = zeros( height, width );
%     imageB = zeros( height, width );
    imageR = 255*ones( height, width );
    imageG = 255*ones( height, width );
    imageB = 255*ones( height, width );
    
    imageR( valid ) = floor(255.5 - ( saturation .* ( 255 - r( valid ) )  ));
    imageG( valid ) = floor(255.5 - ( saturation .* ( 255 - g( valid ) ) ) );
    imageB( valid ) = floor(255.5 - ( saturation .* ( 255 - b( valid ) ) ) );

   
    rgbImageDirection = uint8( cat( 3, imageR, imageG, imageB ) );
    
  
    if ( 2 <= nargout )
        %%%%%%%%%%%%%
        % A cyclic length representation to find length inaccuracies
        %%%%%%%%%%%%%
        length = sqrt( u.^2 + v.^2 );
        modulus = mod( length, cycleLength );

        [r, g, b] = getColor( modulus / cycleLength );
        rgbImageCyclic = uint8( cat( 3, r, g, b ) );

        if ( 3 == nargout )
            
            %%%%%%%%%%%%%
            % Direction coding after removing mean
            %%%%%%%%%%%%%
            
            uDiff = u - meanU;
            vDiff = v - meanV;

            %Represent direction via colour
            radian = atan2( vDiff, uDiff) * inversPi;   %in [-1,1]
            index = ( radian + 1 ) * 0.5;               %in [0, 1]

            [r, g, b] = getColor( index );

            %Represent length via saturation, with white for small lengths
            saturation = sqrt( uDiff.^2 + vDiff.^2 );
            saturation = capSaturation( saturation );
            
            saturation = saturation / capSaturation( fullSaturationLength );
            saturation( saturation > 1) = 1; %threshold to [0,1]

            imageR = zeros( height, width );
            imageG = zeros( height, width );
            imageB = zeros( height, width );

            imageR( valid ) = floor(255.5 - ( saturation .* ( 255 - r( valid ) ) ) );
            imageG( valid ) = floor(255.5 - ( saturation .* ( 255 - g( valid ) ) ) );
            imageB( valid ) = floor(255.5 - ( saturation .* ( 255 - b( valid ) ) ) );

            rgbImageDifference = uint8( cat( 3, imageR, imageG, imageB ) );
            
        end
        
    end

    %%%%%%%%%%%%%
    % Nested Functions
    %%%%%%%%%%%%%

    function [ rImg, gImg, bImg] = getColor( index )
        
        %get index into range [0...1]
        while ( min(index(:)) < 0.0 )
            idx = find(index < 0.0);
            index(idx) = index(idx) + 1.0;
        end
        while ( max(index(:)) > 1.0 )
            idx = find(index > 1.0);
            index(idx) = index(idx) - 1.0;
        end
        
        adr_f = 1 + index * ( nColors - 2); % in [1, nColors - 1]
        adr_i = floor( adr_f );
        
        %interpolate linearly
        w = adr_f - adr_i;
        
        rImg = zeros( height, width );
        gImg = zeros( height, width );
        bImg = zeros( height, width );

        % round
        rImg( valid ) = floor(0.5 + ( 1 - w) .* CM_r( adr_i ) + w .* CM_r( adr_i + 1 ) );
        gImg( valid ) = floor(0.5 + ( 1 - w) .* CM_g( adr_i ) + w .* CM_g( adr_i + 1 ) );
        bImg( valid ) = floor(0.5 + ( 1 - w) .* CM_b( adr_i ) + w .* CM_b( adr_i + 1 ) );
    end


    function [ CM_r, CM_g, CM_b] = createColourmap( )
        %initialize the colourmap
        HSV = ones( nColors, 3 );
        offsetColor = floor( colorOffset * nColors); %shift so that yellow is at the black asphalt for driver-assistance videos
        pos = mod( offsetColor + (0:nColors-1), nColors );
        HSV(:,1) = pos/nColors;
        CM = round(255 * hsv2rgb( HSV ));

        CM_r = CM( :, 1 );
        CM_g = CM( :, 2 );
        CM_b = CM( :, 3 );
    end


    function y = capSaturation( x )
        % compress values greater than threshold to avoid saturation
        id = ( abs(x) > saturationThreshold );
        y = x;
        y(id) = sign( x(id) ) .* ( saturationThreshold*( 1+log( abs( x(id) )/saturationThreshold )));
    end

end

