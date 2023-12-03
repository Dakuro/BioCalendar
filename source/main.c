#include <stdio.h>
#include <stdlib.h>


int convertToJulian(int day, int month, int year){
	return (1461 * (year + 4800 + (month - 14) / 12)) / 4 +
		(367 * (month - 2 - 12 * ((month - 14) / 12))) / 12 -
		(3 * ((year + 4900 + (month - 14) / 12) / 100)) / 4 +
		day - 32075;
}


void convertToGregorian(int julianDay, int *day, int *month, int *year){
	int f = julianDay + 1401 + (((4 * julianDay + 274277) / 146097) * 3) / 4 - 38;
	int e = 4 * f + 3;
	int g = (e % 1461) / 4;
	int h = 5 * g + 2;

	*day = (h % 153) / 5 + 1;
	*month = ((h / 153 + 2) % 12) + 1;
	*year = e / 1461 - 4716 + (12 + 2 - *month) / 12;
}


int main(){
	int julianDay, day, month, year;
	printf("\n Enter a Julian Day to be converted to a Gregorian date: ");
	scanf("%d", &julianDay);
	convertToGregorian(julianDay, &day, &month, &year);
	printf("For Julian Day %d, the Gregorian date is: %d-%d-%d\n", julianDay, day, month, year);
	printf("Enter a Gregorian date to be converted to a Julian Day: ");
	scanf("%d%d%d", &day, &month, &year);
	int JourJulien = convertToJulian(day, month, year);
	printf("For the Gregorian date %d-%d-%d, Julian Day is: %d\n", day, month, year, julianDay);
	return 0;
}
