.RECIPEPREFIX = >
execute:consigne.o regulation.o simulateur.o visualisationC.o visualisationT.o test_sim.o
>gcc -o execute consigne.o regulation.o simulateur.o test_sim.o visualisationT.o visualisationC.o

consigne.o:consigne.c
>gcc -c -Wall -lm consigne.c

regulation.o:regulation.c
>gcc -c -Wall -lm regulation.c

simulateur.o:simulateur.c
>gcc -c -Wall -lm simulateur.c

visualisationC.o:visualisationC.c
>gcc -c -Wall -lm visualisationC.c

visualisationT.o:visualisationT.c
>gcc -c -Wall -lm visualisationT.c

test_sim.o:test_sim.c
>gcc -c -Wall -lm test_sim.c
