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
 * PROBLEM #21 
 *********************/

/*

Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 221 are 1, 2, 4, 5, 10, 11, 21, 22, 44, 55 and 110; therefore d(221) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 221.

Evaluate the sum of all the amicable numbers under 10000.

*/

#include <cstring>
#include <stdio.h>
#include "../AbstractProblem.h"
#include "Problem.h"
#include <vector>
#include <unordered_map>

FACTORY(Problem21)

Problem21::Problem21()
{
    this->ProblemName = new std::string("Amicable numbers");
    this->ProblemNumber = 21;
}

void Problem21::Execute()
{
    std::vector<uint32_t> factors;
    uint32_t iter;
    uint32_t sum;
    
    this->answer = 0;
    
    iter = 1;
    while(iter < this->input) {
        factors.clear();
        sum = 0;
        this->ProjectFunctions->GetFactors(iter, &factors);
        
        while(!factors.empty()) {
            if(factors.back() < iter) {
                sum += factors.back();
            }
            factors.pop_back();
        }
        
        this->numberTable[iter] = sum;
        if(this->numberTable.count(sum) > 0) {
            if(this->numberTable[sum] == iter && iter != sum) {
                this->amicableNumbers.push_back(sum);
                this->amicableNumbers.push_back(iter);
            }
        }
        
        iter++;
    }
    
    while(!this->amicableNumbers.empty()) {
        this->answer += this->amicableNumbers.back();
        this->amicableNumbers.pop_back();
    }
}

void Problem21::GetAnswer()
{
    printf("Answer: %u\r\n", this->answer);
}

void Problem21::GetInputs()
{
    this->ProjectFunctions->GetInput(&this->input, 10000, "max number");
}