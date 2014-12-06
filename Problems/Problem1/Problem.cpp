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
 * PROBLEM #1
 *********************/

/*

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

*/

#include <cstring>
#include <stdio.h>
#include "../AbstractProblem.h"
#include "Problem.h"

FACTORY(Problem1)
 
Problem1::Problem1()
{
    this->ProblemName = new std::string("Multiples of 3 and 5");
    this->ProblemNumber = 1;
}

void Problem1::GetInputs()
{    
    this->ProjectFunctions->GetInput(&this->input, 1000, "max number");
}

void Problem1::GetAnswer()
{
    printf("Answer: %u\r\n", this->answer);
}

void Problem1::Execute()
{
    this->answer = this->FindMultiples(this->input);
}

uint32_t Problem1::FindMultiples(uint32_t limit)
{
    uint32_t i = 0, sum = 0;
    for(i=1;i<limit;i++)
    {
        if(i%3 == 0 || i%5 == 0) {
            sum += i;
        }
    }
    
    return sum;
}