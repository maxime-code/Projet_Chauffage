#include <stdio.h>
#include <unistd.h>
#include "simulateur.h"
#include "consigne.h"
//#include "autotests.h"
#include "regulation.h"
#include "visualisationT.h"
#include "visualisationC.h"

int main(){
    // supprimer les verrous
    remove(".verrouConsigne");
    remove(".verrouData");

    // initialisation des informations
    temp_t myTemp;
    myTemp.interieure = 15.0; // on choisit une temperature de depart (celle du python)
    myTemp.exterieure = 5;
    struct simParam_s*  monSimulateur_ps = simConstruct(myTemp);
    float cons = 0; // premiere consigne
    float oldT = myTemp.interieure;
    float oldI = 0;
    float oldConsigne=cons;

    //programme qui tourne en boucle
    while(1){
            cons = consigne(cons);//on recupere la commande en fonction de l
            if(cons == 5){ // quitter le programme si consigne = 5
                myTemp = simCalc(0,monSimulateur_ps);
                simDestruct(monSimulateur_ps); // detruire le simulateur
                return 0;
            }
            float reg = regulation(0,cons, myTemp.interieure, &oldT, &oldI, &oldConsigne); // regulation
            myTemp= simCalc(reg, monSimulateur_ps); // simulateur
            visualisationT(myTemp); // mettre les donnees dans data.txt
            visualisationC(reg);
    }
    simDestruct(monSimulateur_ps);
}
