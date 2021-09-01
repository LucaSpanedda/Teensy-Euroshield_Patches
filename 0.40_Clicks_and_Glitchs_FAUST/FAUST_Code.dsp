import("stdfaust.lib");
freq = nentry("freq",1,1,1024,1);
gain = nentry("gain",1,0,1,0.01);

decimale(step)= step-int(step);
varnoise(seed) = (seed *(1103515245) /2147483647.0 : decimale)*8; 
fasore(f) = ((f/ma.SR) : (+ : decimale) ~ _) - 0.5;
ifmajzero(f) = ((fasore(f) > 0) *  1) <: mem, _ :> -;
ifminzero(f) = ((fasore(f) < 0) * -1) <: mem, _ :> -;
sumifs(f) = ifmajzero(f) + ifminzero(f);

process = 
sumifs(varnoise(freq*1242))*gain,
sumifs(varnoise(freq*2214))*gain;