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
 * PROBLEM #7 
 *********************/

/*

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

*/

#include <cstring>
#include <stdio.h>
#include <math.h>
#include "../AbstractProblem.h"
#include "Problem.h"

FACTORY(Problem7)

Problem7::Problem7()
{
    this->ProblemName = new std::string("");
    this->ProblemNumber = 7;
}

void Problem7::GetInputs()
{
    this->ProjectFunctions->GetInput(&this->input, 10001, "number of prime");
    this->ProjectFunctions->GetInput(&this->approach, 1, "algorithm \r\n\t0: Brute force\r\n\t1: Sieve\r\n\t");
}

void Problem7::Execute()
{
    if(!this->approach) {
        this->BruteForce();
    } else {
        this->ApproximationSieve();
    }
}

void Problem7::GetAnswer()
{
    printf("Answer: %llu\r\n", this->answer);
}
    
/**
 * This method simply counts up from 2 until the prime which is wanted is
 * retrieved.
 */
void Problem7::BruteForce()
{
    uint32_t currentPrime = 0;
    uint64_t currentNumber = 1;
    
    
    while(currentPrime < this->input)
    {        
        currentNumber++;
        
        if(this->ProjectFunctions->IsPrime(currentNumber)) {
            currentPrime++;
        }
    }
    
    this->answer = currentNumber;
}

/**
 * This method uses two combinations of methods:
 *   - It first approximates the value of 
 */
void Problem7::ApproximationSieve()
{
    uint32_t i, item=0;
    uint8_t* sieve = NULL;    
    
    sieve = this->ProjectFunctions->GetPrimeSieve(this->input);
    
    item = 0;
    i = 0;
    while(item < this->input)
    {
        if(!sieve[++i]) {
            item++;
        }
    }
    
    free(sieve);
    
    this->answer = i;
}