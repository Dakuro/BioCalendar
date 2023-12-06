#ifndef BIOCALENDAR_FUNCTIONS_H
#define BIOCALENDAR_FUNCTIONS_H


typedef struct GregorianDate{
	int day;
	int month;
	int year;
} GregorianDate;


int toJulian(GregorianDate date); // Convert a Gregorian date to a Julian Day and return it
GregorianDate toGregorian(int julianDay); // Convert a Julian Day to a Gregorian date and return it


#endif //BIOCALENDAR_FUNCTIONS_H
