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
 * PROBLEM #9 
 *********************/

/*

 

*/

#include <cstring>
#include <stdio.h>
#include <math.h>
#include "../AbstractProblem.h"
#include "Problem.h"

FACTORY(Problem9)

Problem9::Problem9()
{
    this->ProblemName = new std::string("Special Pythagorean triplet");
    this->ProblemNumber = 9;
}

void Problem9::Execute()
{    
    if(this->method == 0) {
        this->BruteForce();
    } else if(this->method == 1) {
        this->Iterative();
    }
}

/**
 * This is an optimized solution which eliminates a variable and
 * iterates over only a and b.  This reduces the looping required
 * by using the equation:
 *      
 *      a^2 + b^2 = (s - a - b)^2
 * 
 * Where 's' is the input.
 */
void Problem9::Iterative()
{
    uint32_t a, b, s;
    
    s = this->input;
    
    for(a=1;a<s;a++)
    {
        for(b=a+1;b<s;b++) {
            if(a*a + b*b == pow(s - a - b, 2)) {
                this->answer = a*b*(1000-a-b);
                return;
            }
        }
    }
}

/**
 * FOR FOR FOR!!!  This is a brute force which uses three for
 * loops to attempt every solution until it finds a valid one.  It
 * was sped up a tiny bit by using the rule that c > b > a.  This
 * eliminates a lot of unnecessary looping.
 */
void Problem9::BruteForce()
{
    uint32_t a,b,c;
    
    for(a=1;a<1000;a++) {
        for(b=a+1;b<1000;b++) {
            for(c=b+1;c<1000;c++) {
                if(a+b+c == 1000)
                {
                    if(a*a + b*b == c*c) {
                        this->answer = a*b*c;
                        return;
                    }
                }
            }
        }
    }
}

void Problem9::GetAnswer()
{
    printf("Answer: %u\r\n", this->answer);
}

void Problem9::GetInputs()
{
    this->ProjectFunctions->GetInput(&this->input, 1000, "sum of triplet");
    this->ProjectFunctions->GetInput(&this->method, 0, "algorithm: \r\n\t0: Brute force\r\n\t1: Iterative\r\n\t");
}