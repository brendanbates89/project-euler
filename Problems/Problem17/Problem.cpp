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
 * PROBLEM #17 
 *********************/

/*

If the numbers 1 to 5 are written out in words: one, two, three, four, five, 
then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in 
words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and 
forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 
letters. The use of "and" when writing out numbers is in compliance with 
British usage.

*/

#include <cstring>
#include <stdio.h>
#include <math.h>
#include "../AbstractProblem.h"
#include "Problem.h"

FACTORY(Problem17)

Problem17::Problem17()
{
    this->ProblemName = new std::string("Number letter counts");
    this->ProblemNumber = 17;
}

void Problem17::Execute()
{
    this->answer = 0;
    
    for(uint32_t i=1;i<=1000;i++) {
        this->answer += this->GetNumberLength(i);
    }
}

uint32_t Problem17::GetNumberLength(uint32_t number)
{
    uint32_t temp = 0;
    uint8_t wordAnd = 3;
    uint8_t wordHundred = 7;
    uint8_t wordThousand = 11;
    
    if(number > 0 && number < 20) {
        // Just get 1-19.
        return this->SingleOrTeen(number);
    }    
    else if(number >= 20 && number <= 99) {
        // First, get the length of the smaller digit.
        temp += this->SingleOrTeen(number % 10);
        temp += this->PowerOfTen((uint8_t)floor(number/10)*10);
        return temp;
    }
    else if(number >= 100 && number < 1000) {
        // Get the hundred value.
        temp = (this->SingleOrTeen((uint8_t)floor(number/100)) + wordHundred);
        // Check if it's just a multiple of 100.
        if(number % 100 == 0) {
            return temp;
        }        
        // Don't forget and.
        temp += wordAnd;
        
        if((number % 100) < 20) {
            temp += this->SingleOrTeen(number % 100);
        } else
        {
            // Get the tens column.
            temp += this->PowerOfTen((uint8_t)floor((number%100)/10)*10);
            if(number % 10 == 0) {
                return temp;
            }

            // Get the single digits column.
            temp += this->SingleOrTeen(number % 10);
        }
        
        return temp;
    }
    
    return wordThousand;
}

uint8_t Problem17::SingleOrTeen(uint8_t number)
{
    switch(number) {
        case 1: return 3;
        case 2: return 3;
        case 3: return 5;
        case 4: return 4;
        case 5: return 4;
        case 6: return 3;
        case 7: return 5;
        case 8: return 5;
        case 9: return 4;
        case 10: return 3;
        case 11: return 6;
        case 12: return 6;
        case 13: return 8;
        case 14: return 8;
        case 15: return 7;
        case 16: return 7;
        case 17: return 9;
        case 18: return 8;
        case 19: return 8;
    }
    
    return 0;
}

uint8_t Problem17::PowerOfTen(uint8_t number)
{
    switch(number) {
        case 20: return 6;
        case 30: return 6;
        case 40: return 5;
        case 50: return 5;
        case 60: return 5;
        case 70: return 7;
        case 80: return 6;
        case 90: return 6;
    }
    
    return 0;
}

void Problem17::GetAnswer()
{
    printf("Answer: %u\r\n", this->answer);
}

void Problem17::GetInputs()
{
}