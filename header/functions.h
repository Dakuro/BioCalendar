#ifndef BIOCALENDAR_FUNCTIONS_H
#define BIOCALENDAR_FUNCTIONS_H

typedef struct gregorianDate{
	int day;
	int month;
	int year;
} gregorianDate;

// Conversions
int toJulian(gregorianDate date); // Convert a Gregorian date to a Julian Day and return it
gregorianDate toGregorian(int julianDay); // Convert a Julian Day to a Gregorian date and return it

// Calendar
gregorianDate getDate(); // Prompt user for a year and month and return the Gregorian date for day 1
int getMonthLength(gregorianDate date); // Use a Gregorian date to get the number of days in its month and return it
int getDayNameID(gregorianDate date); // Return an ID corresponding to the day (0 -> Monday, ..., 6 -> Sunday)
void printCalendar(); // Print a calendar page

#endif //BIOCALENDAR_FUNCTIONS_H
