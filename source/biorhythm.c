#include <stdio.h>
#include <math.h>
#include <string.h>
#include "../header/functions.h"

const char *LEVELS[5] = {
	" %.2lf.. %.2lf: ", // Both positive values
	"%.2lf.. %.2lf: ", // Mixed values
	"%.2lf..%.2lf: ", // Both negative values
	"              ", // Day/Month line
	"             " // Year line
};

const double VALUES[11] = {
	1.00,
	0.80,
	0.60,
	0.40,
	0.20,
	-0.00,
	-0.20,
	-0.40,
	-0.60,
	-0.80,
	-1.00
};

const int MAX_LINE = 13;
const int MAX_COLUMN = 100;

// Prompt user for a day, month and year of birth and return their birthdate
gregorianDate getBirthDate(){
	gregorianDate birthDate;
	printf("Entrer une date de naissance (JJ MM AAAA): ");
	scanf("%d%d%d", &birthDate.day, &birthDate.month, &birthDate.year);
	printf("\n");
	return birthDate;
}


// Prompt user for a day, month and year and return the central date of the biorhythm
gregorianDate getCentralDate(){
	gregorianDate centralDate;
	printf("Entrer la date centrale du biorythme (JJ MM AAAA): ");
	scanf("%d%d%d", &centralDate.day, &centralDate.month, &centralDate.year);
	printf("\n");
	return centralDate;
}


// Use the central date to determine 4 dates around it and return them
bioDates getDates(gregorianDate dateCentral){
	bioDates dates;
	dates.dateMinus2 = toGregorian(toJulian(dateCentral) - 14);
	dates.dateMinus1 = toGregorian(toJulian(dateCentral) - 7);
	dates.dateCentral = dateCentral;
	dates.datePlus1 = toGregorian(toJulian(dateCentral) + 7);
	dates.datePlus2 = toGregorian(toJulian(dateCentral) + 14);
	return dates;
}


double getDaysElapsed(gregorianDate birthDate, gregorianDate actualDate){
	double daysElapsed = toJulian(actualDate) - toJulian(birthDate);
	return daysElapsed;
}


double getPhysical(double daysElapsed){
	double physicalState = sin((2.0 * M_PI * daysElapsed) / 23.0);
	return physicalState;
}


double getEmotional(double daysElapsed){
	double emotionalState = sin((2.0 * M_PI * daysElapsed) / 28.0);
	return emotionalState;
}


double getIntellectual(double daysElapsed){
	double intellectualState = sin((2.0 * M_PI * daysElapsed) / 33.0);
	return intellectualState;
}


int biorhythmLogic(int line, int column, gregorianDate birthDate, bioDates dates){
	if(column == 0){
		if(line < 4) printf(LEVELS[0], VALUES[line + 1], VALUES[line]);
		else if(line == 4) printf(LEVELS[1], VALUES[line + 1], VALUES[line]);
		else if(line > 4 && line < 10) printf(LEVELS[2], VALUES[line + 1], VALUES[line]);
		else printf("%s", LEVELS[line == 12 ? 4 : 3]);
		column = (int) strlen(LEVELS[3]);
		return column;
	}
	switch(line){
	case 0:
		printf("-");
		break;
	case 1:
		printf("+");
		break;
	default:
		printf("*");
		break;
	}
	return column;
}


// Print a biorhythm
void printBiorhythm(){
	gregorianDate birthDate = getBirthDate();
	gregorianDate centralDate = getCentralDate();
	bioDates dates = getDates(centralDate);
	int line, column;
	for(line = 0; line < MAX_LINE; ++line){
		for(column = 0; column < MAX_COLUMN; ++column){
			column = biorhythmLogic(line, column, birthDate, dates);
		}
		printf("\n");
	}
	printf("\n");
}
