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
 * PROBLEM #5 
 *********************/

/*

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

 */

#include <cstring>
#include <stdio.h>
#include <math.h>
#include "../AbstractProblem.h"
#include "Problem.h"

FACTORY(Problem5)

Problem5::Problem5()
{
    this->ProblemName = new std::string("Smallest multiple");
    this->ProblemNumber = 5;
}

void Problem5::Execute()
{
    //this->PrimeFactor();
    this->PrimeFactor();
}

void Problem5::GetInputs()
{

    this->ProjectFunctions->GetInput(&this->input, 20, "max divisible number");
}

void Problem5::GetAnswer()
{    
    printf("Answer: %llu\r\n", this->answer);
}

/**
 * Better solution.  This gets all of the prime factors from 2 to the
 * number provided.  It then uses the highest powers of all the prime factors
 * (e.g. if one prime factor was 2^2 and one was 2^4, 2^4 would be used) and
 * multiplies those together.
 */
void Problem5::PrimeFactor()
{
    std::vector<prime_root_t> vector;
    std::vector<prime_root_t> factors;
    prime_root_t factor;
    uint64_t answer = 1;

    // 
    while(this->input > 1)
    {
        // Clear the vector.
        vector.clear();
        
        // Retrieve the prime factors.
        this->ProjectFunctions->GetPrimeFactors(this->input--, &vector);
        
        // Loop through the prime factors.
        for(std::vector<prime_root_t>::iterator it = vector.begin(); it != vector.end(); ++it)
        {            
            factor.number = it->number;
            factor.power = it->power;
            this->AddToList(&factor, &factors);
        }
    }
    
    // Loop through the prime factors to compute the answer.
    for(std::vector<prime_root_t>::iterator it = factors.begin(); it != factors.end(); ++it)
    {
        answer *= (int)pow(it->number, it->power);
    }
    
    this->answer = answer;
}

/**
 * This solution brute forces the solution by count up every number and
 * checking if it's evenly divisible by 1 through the input.  Bad solution,
 * I believe it's probably O(n^2) or O(log(n)).
 */
void Problem5::BruteForce()
{
    uint64_t i, number = 1;
    
    while(number != 0)
    {
        for(i=1;i<=this->input;i++)
        {
            if(number % i != 0) {
                break;
            }
        }
        
        if(i > this->input) {
            break;
        }
        
        number++;
    }
    
    this->answer = number;
}

void Problem5::AddToList(prime_root_t* factor, std::vector<prime_root_t>* vector)
{
    bool match = false;
    
    for(std::vector<prime_root_t>::iterator it = vector->begin(); it != vector->end(); ++it)
    {
        if(it->number == factor->number) {
            match = true;
            if(it->power < factor->power) {
                it->power = factor->power;
            }
        }
    }
    
    if(!match) {
        vector->push_back(*factor);
    }
}