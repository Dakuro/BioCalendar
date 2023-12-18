#ifndef BIOCALENDAR_FUNCTIONS_H
#define BIOCALENDAR_FUNCTIONS_H

typedef struct gregorianDate{
	int day;
	int month;
	int year;
} gregorianDate;

void menu(); // Display a menu to select which program to use

// Conversions
int toJulian(gregorianDate date); // Convert a Gregorian date to a Julian Day and return it
gregorianDate toGregorian(int julianDay); // Convert a Julian Day to a Gregorian date and return it

// Calendar
gregorianDate getDate(); // Prompt user for a year and month and return the Gregorian date for day 1
int getMonthLength(gregorianDate date); // Get the number of days in a month and return it
int getDayNameID(gregorianDate date); // Return an ID corresponding to the day (0 -> Monday, ..., 6 -> Sunday)
int calendarLogic(gregorianDate date, int height, int width, int monthLength, int *dayToPrint, int dayNameID);
void printCalendar(); // Print a calendar page

// Biorhythm
int getBirthDate(); // Prompt user for a day, month and year of birth and return as Julian Day
int getCentralDate(); // Prompt user for a day, month and year and return as a Julian Day
int getDaysElapsed(int birthDate, int actualDate); // Get the number of days elapsed since birth and return it
double getPhysical(int daysElapsed); // Get a physical value and return it
double getEmotional(int daysElapsed); // Get an emotional value and return it
double getIntellectual(int daysElapsed); // Get an intellectual value and return it
int biorhythmLogic(int line, int column, int birthDate, int centralDate);
void printBiorhythm(); // Print a biorhythm

#endif //BIOCALENDAR_FUNCTIONS_H
