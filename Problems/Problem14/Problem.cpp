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
 * PROBLEM #14 
 *********************/

/*

The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.

*/

#include <cstring>
#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include "../AbstractProblem.h"
#include "Problem.h"

FACTORY(Problem14)

Problem14::Problem14()
{
    this->ProblemName = new std::string("Longest Collatz sequence");
    this->ProblemNumber = 14;
}

void Problem14::BruteForce()
{
    uint32_t steps, i, longestChain, longestStarting;
    uint64_t sum;
    
    longestStarting = 0;
    longestChain = 0;
    
    i = 2;
    while(i < this->input) {
        sum = i;
        steps = 1;
        while(sum != 1) {
            this->CollatzIteration(sum);
            steps++;
        }
        
        if(steps > longestChain) {
            longestChain = steps;
            longestStarting = i;
        }
        
        i++;
    }
    
    this->answer = longestStarting;
}

void Problem14::RecursiveMap()
{
    uint32_t longestChain = 0, longestTerm = 0;
    uint32_t currentTerm, currentChain;
    
    for(currentTerm = 1; currentTerm < this->input; currentTerm++) {
        currentChain = this->GetSteps(currentTerm);
        
        if(currentChain > longestChain) {
            longestChain = currentChain;
            longestTerm = currentTerm;
        }
    }
    
    this->answer = longestTerm;
}

uint32_t Problem14::GetSteps(uint64_t number)
{
    uint32_t steps;
    uint64_t nextValue;
    bool foundInMap;
    
    // End cases.
    if(number == 0) {
        return 0;
    }    
    if(number == 1) {
        return 1;
    }
    
    // Check if this number exists in the map.
    try
    {
        foundInMap = true;
        steps = this->hashtable.at(number);
    }
    catch(const std::out_of_range& ex) {
        foundInMap = false;
    }
    
    // If we found this in the map, return the cached number of steps.
    // Otherwise, let's figure it out and map the number!
    if(foundInMap) {
        return steps;
    } else { 
        nextValue = number;
        CollatzIteration(nextValue);
        steps = (this->GetSteps(nextValue) + 1);
        this->hashtable[number] = steps;
        return steps;
    }
}

void Problem14::CollatzIteration(uint64_t& number)
{
    // Odd
    if(number & 0x00000001) {
        number = 3*number + 1;
    }
    // Even
    else {
        number = number/2;
    }
}

void Problem14::Execute()
{
    if(this->method == 0) {
        this->BruteForce();
    } else
    {
        this->RecursiveMap();
    }
}

void Problem14::GetAnswer()
{
    printf("Answer: %u\r\n", this->answer);
}

void Problem14::GetInputs()
{
    this->ProjectFunctions->GetInput(&this->method, 0, "method:\r\n\t0: Brute force\r\n\t1: Recursive Map\r\n\t");
    this->ProjectFunctions->GetInput(&this->input, 1000000, "max number");
}