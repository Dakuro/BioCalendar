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
	if(date.month == 12){
		date.month = 1;
		date.year += 1;
	} else{date.month += 1;}
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
			switch (i) {
				case 0: // First line
				case 2: // Third line
				case 10: // Last line
					if(j == 0 || j == CALENDAR_WIDTH - 1){
						printf("+");
					} else{printf("-");}
					break;
				case 1: // Second line
					if(j == 0 || j == CALENDAR_WIDTH - 1){
						printf("|");
					} else if(j == 2){ // Display month and year
						printf("%s%s%d", MONTH_NAMES[date.month - 1], " ", date.year);
						if (date.month == 12) {
							j += strlen(MONTH_NAMES[date.month - 1]) + 3;
						} else {
							j += strlen(MONTH_NAMES[date.month - 1]) + 4;
						}
					} else{printf(" ");}
					break;
				case 3: // Fourth line
					if(j == 0 || j == CALENDAR_WIDTH - 1){
						printf("|");
					} else if(j == 2){ // Display names of the days
						printf("%s", DAYS_NAMES);
						j += strlen(DAYS_NAMES) - 1;
					} else{printf(" ");}
					break;
				default: // All other lines
					if(i > 4){dayNameID = 0;}
					if(j == 0 || j == CALENDAR_WIDTH - 1){
						printf("|");
					} else if(j == 2 + 3 * dayNameID && dayToPrint <= monthLength){ // Display days, if applicable
						for(int k = dayNameID; k < 7; k++){
							dayToPrint < 10 ? printf("%s%d", " ", dayToPrint) : printf("%d", dayToPrint);
							printf(" ");
							dayToPrint++;
							j += 3;
							if(dayToPrint > monthLength){break;}
						}
						j--;
					} else{printf(" ");}
					break;
			}
		}
		printf("\n");
	}

}
