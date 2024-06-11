    #include <stdio.h>
	#include <stdlib.h>
    #include <math.h>
	#include "define.h" 
    
   float regulationTest(int regul,float consigne,float* tabT, int nT);
    float regulation(int regul,float consigne,float T,float* oldT, float* oldI, float* oldConsigne);
