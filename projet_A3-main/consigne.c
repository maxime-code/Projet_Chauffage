#include "consigne.h"
#include <string.h>
#define MAX_TAILLE 5

float consigne(float thermostatprec_f){
   float value;
   if(access( ".verrouConsigne", F_OK ) == -1 ){ // verifier si le verrou
       fopen(".verrouConsigne","a+"); // creer verrou
       char str[MAX_TAILLE]= "";
       char * endPtr;
       FILE* f = NULL;
       f = fopen("consigne.txt","r");
       if (!feof(f)){
           fgets(str, MAX_TAILLE, f); // on lit la chaine de caractère de la premiere ligne du fichier
           value = strtof( str, &endPtr); // transformer la chaine de caractere en float
           fclose(f);
       }
       if(value<5.0 || value>40.0){ // on regarde si la valeur est en dehors des bornes souhaitees
           value =  thermostatprec_f; // si non, on renverra l'ancienne valeur
       }
       remove(".verrouConsigne");
   }
   else{ // cas ou le verrou est present : on reprend l'ancienne valeur
       value = thermostatprec_f;
   }
   return value;
}
