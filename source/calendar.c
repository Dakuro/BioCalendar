#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../header/functions.h"

const char *MONTH_NAMES[12] = {
    "Janvier",
    "Février",
    "Mars",
    "Avril",
    "Mai",
    "Juin",
    "Juillet",
    "Août",
    "Septembre",
    "Octobre",
    "Novembre",
    "Décembre"
};

const char *DAYS_NAMES = "lu ma me je ve sa di";

const int CALENDAR_HEIGHT = 11;
const int CALENDAR_WIDTH = 24;


// Prompt user for a year and month and return the Gregorian date for day 1
gregorianDate getDate(){
	gregorianDate date;
	printf("Entrer une année puis un mois: ");
	scanf("%d%d", &date.year, &date.month);
	printf("\n");
	date.day = 1;
	return date;
}


// Use a Gregorian date to get the number of days in its month and return it
int getMonthLength(gregorianDate date){
	int julianDay1, julianDay2;
	julianDay1 = toJulian(date);
	date.month == 12 ? (date.month = 1, ++date.year) : ++date.month;
	julianDay2 = toJulian(date);
	return julianDay2 - julianDay1;
}


// Return an ID corresponding to the day (0 -> Monday, ..., 6 -> Sunday)
int getDayNameID(gregorianDate date){
	return toJulian(date) % 7;
}


int calendarLogic(gregorianDate date, int height, int width, int monthLength, int *dayToPrint, int dayNameID){
	int newWidth = width;
	bool isBorder = newWidth == 0 || newWidth == CALENDAR_WIDTH - 1;
	bool isWriteable = newWidth == 2 + 3 * dayNameID && *dayToPrint <= monthLength;
	bool isAccentuated = date.month == 2 || date.month == 8 || date.month == 12;
	switch(height){
	case 0: // First line
	case 2: // Third line
	case 10: // Last line
		printf(isBorder ? "+" : "-");
		break;
	case 1: // Second line
		if(isBorder){ printf("|"); break; }
		if(newWidth != 2){ printf(" "); break; }
		// Display month and year
		printf("%s %d", MONTH_NAMES[date.month - 1], date.year);
		// Months with an accentuated letter in their name need different spacing
		newWidth += (int) strlen(MONTH_NAMES[date.month - 1]) + (isAccentuated ? 3 : 4);
		break;
	case 3: // Fourth line
		if(isBorder){ printf("|"); break; }
		if(newWidth != 2){ printf(" "); break; }
		// Display names of the days
		printf("%s", DAYS_NAMES);
		newWidth += (int) strlen(DAYS_NAMES) - 1;
		break;
	default: // All other lines
		if(isBorder){ printf("|"); break; }
		if(!isWriteable){ printf(" "); break; }
		// Display days, if applicable
		for(; dayNameID < 7; ++dayNameID){
			printf(*dayToPrint < 10 ? " %d " : "%d ", *dayToPrint);
			++*dayToPrint;
			newWidth += 3;
			if(*dayToPrint > monthLength) break;
		}
		--newWidth;
		break;
	}
	return newWidth;
}


// Print a calendar page
void printCalendar(){
	gregorianDate date = getDate();
	int monthLength = getMonthLength(date);
	int dayToPrint = 1;
	int dayNameID = getDayNameID(date);
	int height, width;
	for(height = 0; height < CALENDAR_HEIGHT; ++height){
		if(height == 5) dayNameID = 0; // Reset dayNameID if week 1 has already been printed
		for(width = 0; width < CALENDAR_WIDTH; ++width){
			width = calendarLogic(date, height, width, monthLength, &dayToPrint, dayNameID);
		}
		printf("\n");
	}
	printf("\n");
}
