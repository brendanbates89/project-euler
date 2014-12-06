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
 * PROBLEM #6 
 *********************/

/*

The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)^2 = 55^2 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

*/

#include <cstring>
#include <stdio.h>
#include "../AbstractProblem.h"
#include "Problem.h"

FACTORY(Problem6)

Problem6::Problem6()
{
    this->ProblemName = new std::string("Sum square difference");
    this->ProblemNumber = 6;
}

void Problem6::Execute()
{
    this->BruteForce();
}

void Problem6::GetInputs()
{    
    this->ProjectFunctions->GetInput(&this->input, 100, "max number");
}

void Problem6::GetAnswer()
{
    printf("Answer: %llu\r\n", this->answer);
}

void Problem6::BruteForce()
{
    uint64_t sumSquares = 0, squareSum = 0, answer;
    
    
    for(uint32_t i=1; i<=this->input; i++)
    {
        sumSquares += i*i;
        squareSum += i;
    }
    
    squareSum *= squareSum;
    answer = squareSum - sumSquares;

    this->answer = answer;
}
