#include "regulation.h"
float max(float a, float b);

float regulationTest(int regul,float consigne,float* tabT, int nT){
    float reg;
    float oldT = tabT[0];
    float oldI = 0; // integrale demarre à 0
    float oldConsigne=consigne;
    for(int i=1;i<nT;i++){ // tester la fonction regulation nT fois
        reg = regulation(regul, consigne, tabT[i], &oldT, &oldI,&oldConsigne);
    }
    printf("This is final reg : %f",reg); // commande finale
    return reg;
}

float regulation(int regul,float consigne,float T,float* oldT, float* oldI, float* oldConsigne){
    float cmd;
    if(regul == 1){ // TOR
        *oldI = 0;
        if(consigne>T){ // si on doit chauffer
            cmd=40;
        }
        else{
            cmd=0; // si on doit pas chauffer -> tend vers la temp exterieure
        }
        return cmd; // retourne 0 ou 40
    }
    else{ // PID
        if(T>=consigne){ // si le chauffe ne doit pas demarrer
            return 0;
        }

        if(*oldConsigne!=consigne){//check si la consigne a changee entre temps
            *oldI = 0;
        }
        *oldConsigne=consigne;


        float Kp=1,Ki=0.099998875,Kd=0.1, dt=10; // 3 coefficients
        float e = consigne - T;
        //P
        float P = Kp*e;

        //I
        float I = (consigne - max(*oldT,T))*dt;
        I+=fabs(T-*oldT)*dt/2;
        I = *oldI + Ki*I;

        //D
        float D = Kd * fabs(T - *oldT)/dt;

        float PID = I+P+D;
        *oldT = T; // reactualise l'ancienne temp avec la temp actuel
        *oldI = I; // ancienne integrale devient la nouvelle integrale
        if(PID>100){ // si la valeur depasse 100
            PID=100;
        }
        return PID;
    }
}
float max(float a, float b){return (a>b)?a:b;} // renvoie le max
