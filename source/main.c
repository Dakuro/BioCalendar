#include <stdio.h>
#include <stdlib.h>
#include "../header/functions.h"


// TEST: For a given Gregorian date, display its Julian Day equivalent
void dispJulianDay(){
	int julianDay;
	GregorianDate date;

	printf("Enter a Gregorian date (format: DD/MM/YYYY) to be converted to a Julian Day: ");
	scanf("%d%d%d", &date.day, &date.month, &date.year);
	julianDay = toJulian(date);
	printf("For the Gregorian date %d-%d-%d, Julian Day is: %d\n", date.day, date.month, date.year, julianDay);
}


// TEST: For a given Julian Day, display its Gregorian date equivalent
void dispGregorianDate(){
	int julianDay;
	GregorianDate date;

	printf("\n Enter a Julian Day to be converted to a Gregorian date (format: DD/MM/YYYY): ");
	scanf("%d", &julianDay);
	date = toGregorian(julianDay);
	printf("For Julian Day %d, the Gregorian date is: %d-%d-%d\n", julianDay, date.day, date.month, date.year);
}


int main(){
	// dispJulianDay();
	// dispGregorianDate();

	return 0;
}

// IN: year, month
// OUT: calendar
// Step 01: Find number of days
	// JDN1 = toJulian({1, month, year});
	// JDN2 = month == 12 ? toJulian({1, 1, year + 1}) : toJulian({1, month + 1, year});
	// days = JDN2 - JDN1;
// Step 02: Determine starting day name
	// switch(JDN1 % 7){0 -> "mo", ..., 6 -> "su"}
// Step 03: Display calendar
	//
