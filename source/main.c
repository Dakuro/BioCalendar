#include <stdio.h>
#include <stdlib.h>



int ConversionJJ(int jour, int mois, int année){
    return (1461 * (année+ 4800 + (mois - 14) / 12)) / 4 +
           (367 * (mois - 2 - 12 * ((mois - 14) / 12))) / 12 -
           (3 * ((année + 4900 + (mois - 14) / 12) / 100)) / 4 +
           jour - 32075;

}

void ConversionJJMMAAAA(int JourJulien, int *jour, int *mois, int *année) {
    int f = JourJulien + 1401 + (((4 * JourJulien + 274277) / 146097) * 3) / 4 - 38;
    int e = 4 * f + 3;
    int g = (e % 1461) / 4;
    int h = 5 * g + 2;

    *jour = (h % 153) / 5 + 1;
    *mois = ((h / 153 + 2) % 12) + 1;
    *année = e / 1461 - 4716 + (12 + 2 - *mois) / 12;
}



int main()
{


    int JourJulien, jour, mois, année;
    printf("\n Entrer Jour Julien pour la conversion Grégorienne: ");
    scanf("%d", &JourJulien);
    ConversionJJMMAAAA(JourJulien, &jour, &mois, &année);
    printf("Le jour julien est %d  donc le jour grégorien est: %d-%d-%d\n", JourJulien, jour, mois, année);
    return 0;
}



