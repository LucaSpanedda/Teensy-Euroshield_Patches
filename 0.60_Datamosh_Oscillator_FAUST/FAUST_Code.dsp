import("stdfaust.lib");
freq = nentry("freq",1,1,1024,1);
gain = nentry("gain",1,1,1024,1)/1024*10;

decimale(x) = x-int(x);
mixer(g) = _*(g)+_*(1-g);
datamoshosc(f,seed,samps,gainin) =
(f/ma.SR) 
* gainin : 
    (+ : decimale : 
        _*( 
            (seed):(+ @(samps)~ *(1103515245))/2147483647.0)
            * (1+(gainin/2))
        )~_;

process = 
datamoshosc(freq,12426538,freq,gain),
datamoshosc(freq,48423276,freq,gain);