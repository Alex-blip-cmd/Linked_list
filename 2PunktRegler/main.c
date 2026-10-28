//
// Created by pimen on 27.10.2026.
//

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#include "sim.h"


int main() {
    double soll;
    double buffer=0.5;
    printf("Sollwert eingeben: ");
    scanf("%lf", &soll);
    double ist=15;
    double istd=15;
    bool anstieg=true;
    int x=0;
    FILE *file=fopen("out.csv","w");
    if (file==NULL) {
        return 1;
    }
    fprintf(file,"ZEIT;TEMP\n ");
    while (x<=40) {
        if (istd<ist) {
            anstieg=true;
        }
        istd=ist;
        ist=Istberechnung(soll,ist,buffer,anstieg);
        if (istd>ist) {
            anstieg=false;
        }
        fprintf(file,"%i; %g\n",x, ist);
        x++;
    }
    fclose(file);
    return 0;
}
