#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int howManyDays() {
  const char*daysOfWeek[]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
  (void)daysOfWeek;
  const char*monthsOfYear[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
  (void)monthsOfYear;
  int day = 18;
  int month = 05;
  int year = 2007;
  // days in a month
  int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  // get size of daysofweek list
  int sizeDaysOfWeek = sizeof(daysOfWeek) / sizeof(daysOfWeek[0]) -1;
  // start from Tuesday
  int currentDayIndex = 1;
  int totalMondays = 0;
  while ((day >0) && (year >= 1401 && year <= 2007) ){
    // decrease day by 1
    day--;
    currentDayIndex--;
    const char* currentDay = daysOfWeek[currentDayIndex];
    (void)currentDay;

    if (currentDayIndex < 0) {
        currentDayIndex = sizeDaysOfWeek;
    }

    // decrease month by 1 if day = 0
    if (day == 0) {
      month--;
      // february == 29 on a leap year (years evenly divisible by 4, but non on a century unless it is divisible by 400)
      if ((year % 4 == 0 && year % 100 != 0 && month ==2) || (year % 400 == 0 && month == 2)) {
        day=29;
      } else {
        day=daysInMonth[month-1];
      }
    }

    // decrease year by 1 if day = 0
    if (month == 0) {
      year--;
      // instantiate days on last day of the month
      month=12;
      day=daysInMonth[11];
    }
    // you must also count the amount of times a monday falls on month ==12
    if ((year >= 1401 && year <= 1800) && (day==12 && currentDayIndex==0)) {
      totalMondays++;
    }
  }
  return totalMondays;
}