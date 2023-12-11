#include <stdio.h>
#include "../header/functions.h"

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


// Print a biorhythm
void printBiorhythm(){
	gregorianDate birthDate = getBirthDate();
	gregorianDate centralDate = getCentralDate();
	bioDates dates = getDates(centralDate);
}
