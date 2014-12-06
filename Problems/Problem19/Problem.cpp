/* 
 * Project Euler Implementation
 *
 * Author:  Brendan Bates
 * Website: http://www.brendan-bates.com
 * Email:   me@brendan-bates.com
 * License: Apache License, Version 2.0 (See LICENSE file for details)
 *
 */

/*********************
 * PROBLEM #19 
 *********************/

/*

You are given the following information, but you may prefer to do some research for yourself.

    1 Jan 1900 was a Monday.
    Thirty days has September,
    April, June and November.
    All the rest have thirty-one,
    Saving February alone,
    Which has twenty-eight, rain or shine.
    And on leap years, twenty-nine.
    A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

*/

#include <cstring>
#include <stdio.h>
#include "../AbstractProblem.h"
#include "Problem.h"

FACTORY(Problem19)

#define BASELINE_YEAR   1900
#define BASELINE_MONTH  JAN
#define BASELINE_DAY    MON

Problem19::Problem19()
{
    this->ProblemName = new std::string("Counting Sundays");
    this->ProblemNumber = 19;
}

void Problem19::Execute()
{
    uint32_t year = 1901;
    uint32_t month = JAN;
    uint32_t sum = 0;
    
    printf("%u \r\n", this->GetDayOfWeek(27, MAR, 2014));
    
    while(year < 2001) {
        month = JAN;        
        while(month <= DEC) {
            if(this->GetDayOfWeek(1, month, year) == SUN) {
                sum++;
            }
            month++;
        }
        year++;
    }
    
    this->answer = sum;
}

uint8_t Problem19::GetDaysInMonth(uint8_t month, uint32_t year)
{
    uint32_t modFactor;
    
    if(month == FEB) {
        modFactor = ((year % 100) == 0) ? 400 : 4;      
        return (year % modFactor) == 0 ? 29 : 28;
    }
    
    switch(month) {
        case JAN: return 31;
        case MAR: return 31;
        case APR: return 30;
        case MAY: return 31;
        case JUN: return 30;
        case JUL: return 31;
        case AUG: return 31;
        case SEP: return 30;
        case OCT: return 31;
        case NOV: return 30;
        case DEC: return 31;
    }
    
    return 0;
}

uint32_t Problem19::GetDaysInYear(uint32_t year)
{
    return this->GetDaysInMonth(JAN, year) +
           this->GetDaysInMonth(FEB, year) +
           this->GetDaysInMonth(MAR, year) +
           this->GetDaysInMonth(APR, year) +
           this->GetDaysInMonth(MAY, year) +
           this->GetDaysInMonth(JUN, year) +
           this->GetDaysInMonth(JUL, year) +
           this->GetDaysInMonth(AUG, year) +
           this->GetDaysInMonth(SEP, year) +
           this->GetDaysInMonth(OCT, year) +
           this->GetDaysInMonth(NOV, year) +
           this->GetDaysInMonth(DEC, year);
}

uint8_t Problem19::GetDayOfWeek(uint8_t day, uint8_t month, uint32_t year)
{
    uint32_t startingDay = BASELINE_DAY;
    uint32_t originalYear = year;
    
    // Add previous years.
    while(year > BASELINE_YEAR) {
        startingDay += this->GetDaysInYear(--year);
        startingDay = startingDay % 7;
    }
    
    // Add previous months.
    while(month > JAN) {
        startingDay += this->GetDaysInMonth(--month, originalYear);
        startingDay = startingDay % 7;
    }
    
    // Add days.
    startingDay += (day - 1);
    startingDay = startingDay % 7;
    
    return startingDay;
}

void Problem19::GetAnswer()
{
    printf("Answer: %u\r\n", this->answer);
}

void Problem19::GetInputs()
{
    
}