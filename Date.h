#pragma once 
#include <iostream>

using namespace std;

class Date {
  private:
    int day, month, year;

  public:
    Date(int inMonth, int inDay, int inYear) : month(inMonth), day(inDay), year(inYear) {};

    void formatDate() {
      cout << month << "/" << day << "/" << year << endl;
    }

    Date* operator +(int days) {
      Date* newDate = new Date(month, day, year);
      while(newDate->day + days > newDate->meses()) {
        days -= (newDate->meses() - newDate->day);
        newDate->incrementMonth(1);
        newDate->day = 0;
      }
      newDate->day += days;
      return newDate;
    }

    void incrementMonth(int monthsToAdd) {
      while(month + monthsToAdd > 12) {
        monthsToAdd -= 12 - month;
        incrementYear(1);
        month = 0;
      }
      month += monthsToAdd;
    }

    void incrementYear(int yearsToAdd) {
      year += yearsToAdd;
    }

    Date* operator -(int days) {
      Date* newDate = new Date(month, day, year);
      while(newDate->day - days < 1) { 
        days -= newDate->day;
        newDate->subtractMonth(1);
        newDate->day = newDate->meses();
      }
      newDate->day -= days;
      return newDate;
    }

    void subtractMonth(int monthsToSubstract) {
      while(month - monthsToSubstract < 1) {
        monthsToSubstract -= month;
        substractYear(1);
        month = 12;
      }
      month -= monthsToSubstract;
    }

    void substractYear(int yearsTosubstract) {
      if(year - yearsTosubstract > 0) {
        year -= yearsTosubstract;
      }
      else {
        year -= yearsTosubstract + 1;
      }
    }

    bool biciesto() {
      return (year%4==0 && year%100==0 &&year%400==0);
    }

    int meses() {
      int dias = 31;
      if(month == 4 || month == 6 || month == 9 || month == 11) {
        dias--;
      }
      if(month == 2) {
        if(biciesto()) {
          dias = 29;
        }
        else {
          dias = 28;
        }
      }
      return dias;
    }

    //Prefix
    Date& operator ++() {
      ++day;
      return *this;
    }
    Date& operator --() {
      --day;
      return *this;
    }

    //postfix
    Date operator ++(int) {
      Date copy(month, day, year);
      ++day;
      return copy;
    }
    Date operator --(int) {
      Date copy(month, day, year);
      --day;
      return copy;
    }
 
};