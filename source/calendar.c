#include <stdio.h>
#include <string.h>
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
	date.day = 1;
	return date;
}


// Use a Gregorian date to get the number of days in its month and return it
int getMonthLength(gregorianDate date){
	int julianDay1, julianDay2;
	julianDay1 = toJulian(date);
	date.month == 12 ? (date.month = 1, date.year++) : date.month++;
	julianDay2 = toJulian(date);
	return julianDay2 - julianDay1;
}


// Return an ID corresponding to the day (0 -> Monday, ..., 6 -> Sunday)
int getDayNameID(gregorianDate date){
	return toJulian(date) % 7;
}


// Print a calendar page
void printCalendar(){
	gregorianDate date = getDate();
	int monthLength = getMonthLength(date);
	int dayToPrint = 1;
	int dayNameID = getDayNameID(date);
	printf("\n");
	for(int i = 0; i < CALENDAR_HEIGHT; i++){
		for(int j = 0; j < CALENDAR_WIDTH; j++){
			switch(i){
				case 0: // First line
				case 2: // Third line
				case 10: // Last line
					printf(j == 0 || j == CALENDAR_WIDTH - 1 ? "+" : "-");
					break;
				case 1: // Second line
					(j != 0 && j != CALENDAR_WIDTH - 1) ? (
						j == 2 ? ( // Display month and year
							printf("%s %d", MONTH_NAMES[date.month - 1], date.year),
							j += strlen(MONTH_NAMES[date.month - 1]) +
								(date.month == 2 || date.month == 8 || date.month == 12 ? 3 : 4)
						) : printf(" ")
					) : printf("|");
					break;
				case 3: // Fourth line
					(j != 0 && j != CALENDAR_WIDTH - 1) ? (
						j == 2 ? ( // Display names of the days
							printf("%s", DAYS_NAMES), j += strlen(DAYS_NAMES) - 1
						) : printf(" ")
					) : printf("|");
					break;
				default: // All other lines
					if(i > 4) dayNameID = 0; // Reset dayNameID if day 1 has already been printed (= on fifth line)
					if(j != 0 && j != CALENDAR_WIDTH - 1){
						if(j == 2 + 3 * dayNameID && dayToPrint <= monthLength){ // Display days, if applicable
							for(int k = dayNameID; k < 7; k++){
								dayToPrint < 10 ? printf(" %d", dayToPrint) : printf("%d", dayToPrint);
								printf(" ");
								dayToPrint++;
								j += 3;
								if(dayToPrint > monthLength) break;
							}
							j--;
						} else{ printf(" "); }
					} else{ printf("|"); }
					break;
			}
		}
		printf("\n");
	}

}