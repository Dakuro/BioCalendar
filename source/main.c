#include <stdio.h>
#include "../header/functions.h"


// TEST: For a given Gregorian date, display its Julian Day equivalent
void dispJulianDay(){
	int julianDay;
	gregorianDate date;
	printf("Entrer une date Grégorienne à convertir en Jour Julien: ");
	scanf("%d%d%d", &date.day, &date.month, &date.year);
	julianDay = toJulian(date);
	printf("Pour la date Grégorienne %d-%d-%d, le Jour Julien est: %d\n", date.day, date.month, date.year, julianDay);
}


// TEST: For a given Julian Day, display its Gregorian date equivalent
void dispGregorianDate(){
	int julianDay;
	gregorianDate date;
	printf("\n Entrer un Jour Julien à convertir en date Grégorienne: ");
	scanf("%d", &julianDay);
	date = toGregorian(julianDay);
	printf("Pour le Jour Julian %d, la date Grégorienne est: %d-%d-%d\n", julianDay, date.day, date.month, date.year);
}


void menu(){
	int menuChoice = 0;
	do{
		printf("Quel programme utiliser ?\n"
		       "1 - Calendrier\n"
		       "2 - Biorythme\n"
		       "Autre - Quitter\n");
		scanf("%d", &menuChoice);
		switch(menuChoice){
		case 1:
			printCalendar();
			break;
		case 2:
			printBiorhythm();
			break;
		default:
			break;
		}
	} while(menuChoice == 1 || menuChoice == 2);
}


int main(){
	// dispJulianDay();
	// dispGregorianDate();
	menu();
	return 0;
}
