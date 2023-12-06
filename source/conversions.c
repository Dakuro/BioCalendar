#include "../header/functions.h"


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
