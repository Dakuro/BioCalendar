#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "../header/functions.h"

const char *MONTHS[12] = {
	"jan",
	"fev",
	"mar",
	"avr",
	"mai",
	"jun",
	"jul",
	"aou",
	"sep",
	"oct",
	"nov",
	"dec"
};

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
const int MAX_COLUMN = 102;

// Prompt user for a day, month and year of birth and return their birthdate
int getBirthDate(){
	gregorianDate birthDate;
	printf("Entrer une date de naissance (JJ MM AAAA): ");
	scanf("%d%d%d", &birthDate.day, &birthDate.month, &birthDate.year);
	printf("\n");
	return toJulian(birthDate);
}


// Prompt user for a day, month and year and return the central date of the biorhythm
int getCentralDate(){
	gregorianDate centralDate;
	printf("Entrer la date centrale du biorythme (JJ MM AAAA): ");
	scanf("%d%d%d", &centralDate.day, &centralDate.month, &centralDate.year);
	printf("\n");
	return toJulian(centralDate);
}


int getDaysElapsed(int birthDate, int actualDate){
	return actualDate - birthDate;
}


double getPhysical(int daysElapsed){
	double physicalState = sin((2.0 * M_PI * (double) daysElapsed) / 23.0);
	return physicalState;
}


double getEmotional(int daysElapsed){
	double emotionalState = sin((2.0 * M_PI * (double) daysElapsed) / 28.0);
	return emotionalState;
}


double getIntellectual(int daysElapsed){
	double intellectualState = sin((2.0 * M_PI * (double) daysElapsed) / 33.0);
	return intellectualState;
}


int biorhythmLogic(int line, int column, int birthDate, int centralDate){
	int dateIndex, actualDate, daysElapsed, goodLine;
	double physState, emoState, intelState, tempState;
	char stateLetter;
	bool isMainDate;
	gregorianDate displayDate;
	if(column == 0){
		if(line < 4) printf(LEVELS[0], VALUES[line + 1], VALUES[line]);
		else if(line == 4) printf(LEVELS[1], VALUES[line + 1], VALUES[line]);
		else if(line > 4 && line < 10) printf(LEVELS[2], VALUES[line + 1], VALUES[line]);
		else printf("%s", LEVELS[line == 12 ? 4 : 3]);
		column = (int) strlen(LEVELS[3]);
		return column;
	}
	
	dateIndex = column - (int) strlen(LEVELS[3]) - 1;
	actualDate = centralDate - 14 + dateIndex / 3;
	daysElapsed = getDaysElapsed(birthDate, actualDate);
	physState = getPhysical(daysElapsed);
	emoState = getEmotional(daysElapsed);
	intelState = getIntellectual(daysElapsed);
	
	switch(dateIndex % 3){
	case 0:
		tempState = physState;
		stateLetter = 'P';
		break;
	case 1:
		tempState = emoState;
		stateLetter = 'E';
		break;
	case 2:
		tempState = intelState;
		stateLetter = 'I';
		break;
	default:
		tempState = 0.0;
		stateLetter = 'X';
		break;
	}
	
	for(int index = 0; index < 10; ++index){
		if(tempState >= VALUES[index + 1]){goodLine = index; break;}
	}
	
	isMainDate = (dateIndex / 3) % 7 == 0;
	
	if(line < 10){
		if(tempState != 0 && line == goodLine) printf("%c", stateLetter);
		else if(isMainDate) printf("|");
		else printf(line == 4 ? "-" : " ");
		return column;
	}
	
	if(isMainDate){
		displayDate = toGregorian(actualDate);
		if(line == 10){
			printf(displayDate.day < 10 ? " %d " : "%d ", displayDate.day);
			return column + 2;
		}
		if(line == 11){
			printf("%s", MONTHS[displayDate.month - 1]);
			return column + 2;
		}
		if(line == 12){
			printf("%d", displayDate.year);
			return column + 3;
		}
	} else printf(" ");
	
	return column;
}


// Print a biorhythm
void printBiorhythm(){
	int birthDate = getBirthDate();
	int centralDate = getCentralDate();
	int line, column;
	for(line = 0; line < MAX_LINE; ++line){
		for(column = 0; column < MAX_COLUMN; ++column){
			column = biorhythmLogic(line, column, birthDate, centralDate);
		}
		printf("\n");
	}
	printf("\n");
}
