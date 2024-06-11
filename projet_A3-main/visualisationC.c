#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "visualisationC.h"


void visualisationC(float puissance_f){
    if(access( ".verrouData", F_OK ) == -1 ) { // verifier si le verrou existe

        fopen(".verrouData", "a+"); // creer verrou
        FILE *fichier = NULL;
        fichier = fopen("data.txt", "r");
        if (fichier != NULL) { // ouvrir data pour lire les valeurs de temperature

            float temp_ext;
            float temp_int;
            char* temoin_chauffe_read;

            fscanf(fichier, "%f\n%f",&temp_ext,&temp_int);
            fclose(fichier);

            fichier = fopen("data.txt", "w"); // ecrire true ou false en fonction de la commande
            if(puissance_f == 0){
                temoin_chauffe_read = "false";
            }
            else{
                temoin_chauffe_read = "true";
            }
            fprintf(fichier, "%.2f\n%.2f\n%s", temp_ext, temp_int, temoin_chauffe_read); // tout ecrire dansda data
        }
        fclose(fichier);
        remove(".verrouData"); // supprimer le verrou
    }

}
