#ifndef BIOCALENDAR_FUNCTIONS_H
#define BIOCALENDAR_FUNCTIONS_H

typedef struct gregorianDate{
	int day;
	int month;
	int year;
} gregorianDate;

typedef struct bioDates{
    gregorianDate dateMinus2;
    gregorianDate dateMinus1;
    gregorianDate dateCentral;
    gregorianDate datePlus1;
    gregorianDate datePlus2;
} bioDates;

void menu(); // Display a menu to select which program to use

// Conversions
int toJulian(gregorianDate date); // Convert a Gregorian date to a Julian Day and return it
gregorianDate toGregorian(int julianDay); // Convert a Julian Day to a Gregorian date and return it

// Calendar
gregorianDate getDate(); // Prompt user for a year and month and return the Gregorian date for day 1
int getMonthLength(gregorianDate date); // Use a Gregorian date to get the number of days in its month and return it
int getDayNameID(gregorianDate date); // Return an ID corresponding to the day (0 -> Monday, ..., 6 -> Sunday)
int calendarLogic(gregorianDate date, int height, int width, int monthLength, int *dayToPrint, int dayNameID);
void printCalendar(); // Print a calendar page

// Biorhythm
gregorianDate getBirthDate(); // Prompt user for a day, month and year of birth and return their birthdate
gregorianDate getCentralDate(); // Prompt user for a day, month and year and return the central date of the biorhythm
bioDates getDates(gregorianDate dateCentral); // Use the central date to determine 4 dates around it and return them
void printBiorhythm(); // Print a biorhythm

#endif //BIOCALENDAR_FUNCTIONS_H
