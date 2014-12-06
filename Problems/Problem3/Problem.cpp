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
 * PROBLEM #3 
 *********************/

/*

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

 */

#include <cstring>
#include <stdio.h>
#include "../AbstractProblem.h"
#include "Problem.h"

FACTORY(Problem3)

Problem3::Problem3()
{
    this->ProblemName = new std::string("Largest prime factor");
    this->ProblemNumber = 3;
}

void Problem3::Execute()
{
    this->PrimeFactors();
}

void Problem3::GetInputs()
{
    this->ProjectFunctions->GetInput(&number, 600851475143, "number");
}

void Problem3::GetAnswer()
{
    printf("Largest Prime Factor: %llu\r\n", this->answer);
}

void Problem3::PrimeFactors()
{
    uint64_t answer = 0;
    std::vector<prime_root_t> factors;
    
    
    this->ProjectFunctions->GetPrimeFactors(this->number, &factors);
        
    for(std::vector<prime_root_t>::iterator it = factors.begin(); it != factors.end(); ++it)
    {
        if(it->number > answer) {
            answer = it->number;
        }
    }
    
    this->answer = answer;
}

void Problem3::BruteForce()
{
    uint64_t i, largest = 0, factor;    
    
    // Iterate through all numbers less than sqrt(number).
    for(i=1;i*i <= this->number;i++)
    {        
        // Check if the number is a valid factor.
        if(this->number % i == 0) {            
            // Calculate the other side of the factor and check if it's a prime.
            factor = this->number / i;
            if(this->ProjectFunctions->IsPrime(factor)) {
                largest = factor;
                break;
            }
            
            if(this->ProjectFunctions->IsPrime(i)) {
                largest = i;
            }
        }
    }
    
    this->answer = largest;
}