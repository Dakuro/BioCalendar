#include <stdio.h>
#include <stdlib.h>
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


int main(){
	// dispJulianDay();
	// dispGregorianDate();
	printCalendar();
	return 0;
}
