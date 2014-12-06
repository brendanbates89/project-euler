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
 * PROBLEM #10 
 *********************/

/*

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

*/

#include <cstring>
#include <stdio.h>
#include "../AbstractProblem.h"
#include "Problem.h"

FACTORY(Problem10)

Problem10::Problem10()
{
    this->ProblemName = new std::string("Summation of primes");
    this->ProblemNumber = 10;
}

void Problem10::Execute()
{
    uint64_t sum = 0;
    uint8_t* sieve = this->ProjectFunctions->GetPrimeSieve(this->input);
    
    for(uint32_t i = 0; i<this->input; i++) {
        if(sieve[i] == 0) {
            sum += i;
        }
    }
    
    this->answer = sum;
}

void Problem10::GetAnswer()
{
    printf("Answer: %llu\r\n", this->answer);
}

void Problem10::GetInputs()
{
    this->ProjectFunctions->GetInput(&this->input, 2000000, "max number");
}