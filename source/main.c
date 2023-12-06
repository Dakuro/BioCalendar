#include <stdio.h>
#include <stdlib.h>

typedef struct GregorianDate{
	int day;
	int month;
	int year;
} GregorianDate;


// Convert a Gregorian date to a Julian Day and return it
int toJulian(GregorianDate date){
	int day = date.day;
	int month = date.month;
	int year = date.year;
	int julianDay = (1461 * (year + 4800 + (month - 14) / 12)) / 4
			+ (367 * (month - 2 - 12 * ((month - 14) / 12))) / 12
			- (3 * ((year + 4900 + (month - 14) / 12) / 100)) / 4
			+ day - 32075;

	return julianDay;
}



// Convert a Julian Day to a Gregorian date and return it
GregorianDate toGregorian(int julianDay){
	int f = julianDay + 1401 + (((4 * julianDay + 274277) / 146097) * 3) / 4 - 38;
	int e = 4 * f + 3;
	int g = (e % 1461) / 4;
	int h = 5 * g + 2;

	GregorianDate date;
	date.day = (h % 153) / 5 + 1;
	date.month = ((h / 153 + 2) % 12) + 1;
	date.year = e / 1461 - 4716 + (12 + 2 - date.month) / 12;

	return date;
}


// For a given Gregorian date, display its Julian Day equivalent
void dispJulianDay(){
	int julianDay;
	GregorianDate date;

	printf("Enter a Gregorian date (format: DD/MM/YYYY) to be converted to a Julian Day: ");
	scanf("%d%d%d", &date.day, &date.month, &date.year);
	julianDay = toJulian(date);
	printf("For the Gregorian date %d-%d-%d, Julian Day is: %d\n", date.day, date.month, date.year, julianDay);
}


// For a given Julian Day, display its Gregorian date equivalent
void dispGregorianDate(){
	int julianDay;
	GregorianDate date;

	printf("\n Enter a Julian Day to be converted to a Gregorian date (format: DD/MM/YYYY): ");
	scanf("%d", &julianDay);
	date = toGregorian(julianDay);
	printf("For Julian Day %d, the Gregorian date is: %d-%d-%d\n", julianDay, date.day, date.month, date.year);
}


int main(){
	dispJulianDay();
	dispGregorianDate();

	return 0;
}
