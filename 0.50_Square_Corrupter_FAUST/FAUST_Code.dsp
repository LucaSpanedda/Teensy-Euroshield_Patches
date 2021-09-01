import("stdfaust.lib");
freq = nentry("freq",1,1,1024,1);
gain = nentry("gain",1,1,1024,1);

decimale(step)= step-int(step);
varnoise(seed) = (seed*(1103515245)/2147483647.0 : decimale)*freq/10; 
fasore(f) = ((f/ma.SR) : (+ : decimale) ~ _) - 0.5;
ifmajzero(f) = ((fasore(f) > 0) *  1) <: _@(gain), _ :> -;
ifminzero(f) = ((fasore(f) < 0) * -1) <: _@(gain), _ :> -;
sumifs(f) = ifmajzero(f) + ifminzero(f);

process = 
sumifs(varnoise(freq*1242)),
sumifs(varnoise(freq*2214));