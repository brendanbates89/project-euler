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
 * PROBLEM #4 
 *********************/

/*

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

 */

#include <cstring>
#include <stdio.h>
#include <math.h>
#include <deque>
#include "../AbstractProblem.h"
#include "Problem.h"

FACTORY(Problem4)

Problem4::Problem4()
{
    this->ProblemName = new std::string("Largest palindrome product");
    this->ProblemNumber = 4;
}

void Problem4::GetInputs()
{
    
}

void Problem4::GetAnswer()
{
    printf("Answer: %u\r\n", this->answer);
}

void Problem4::Execute()
{
    std::deque<int> deque;
    
    uint32_t term1, term2, number, largest = 0;
    
    for(term1=999; term1>0; term1--)
    {
        for(term2=999; term2>0; term2--)
        {
            number = term1*term2;
            if(this->IsPalendrome(number) && number > largest)
            {
                largest = number;
            }
        }
    }
    
    this->answer = largest;
}

bool Problem4::IsPalendrome(uint32_t number)
{
    uint32_t temp = 0, original = number, compare = 0;
    do
    {
        temp = number % 10;
        compare += temp;
        compare *= 10;
        number = (int)(floor(number/10));
    } while(number > 0);
    
    compare /= 10;
    
    return original == compare;
}