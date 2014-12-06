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
 * PROBLEM #16 
 *********************/

/*

2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?

*/

#include <cstring>
#include <stdio.h>
#include <deque>
#include <math.h>
#include <bits/stl_deque.h>
#include "../AbstractProblem.h"
#include "Problem.h"

FACTORY(Problem16)

Problem16::Problem16()
{
    this->ProblemName = new std::string("Power digit sum");
    this->ProblemNumber = 16;
}

void Problem16::Execute()
{
    std::deque<uint8_t> *digits;
    
    digits = this->GetPowerOfTwo(this->input);
    
    this->answer = 0;
    while(!digits->empty()) {
        this->answer += digits->front();
        digits->pop_front();
    }
}

std::deque<uint8_t>* Problem16::GetPowerOfTwo(uint32_t power)
{
    std::deque<uint8_t> *number = new std::deque<uint8_t>;    
    number->push_front(2);
    
    for(uint32_t i=1;i<power;i++) {
        this->MultiplyByTwo(&number);
    }
    
    return number;
}

void Problem16::MultiplyByTwo(std::deque<uint8_t> **inputQueue)
{
    std::deque<uint8_t> *digitQueue;
    uint8_t carry, currentDigit, currentInput;
    
    digitQueue = new std::deque<uint8_t>;
    
    carry = 0;
    while(!(*inputQueue)->empty()) {
        currentInput = (*inputQueue)->back();
        (*inputQueue)->pop_back();
        
        currentDigit = (currentInput * 2) + carry;
        carry = 0;
        if(currentDigit > 9) {
            carry = 1;
            currentDigit = currentDigit % 10;
        }
       
        digitQueue->push_front(currentDigit);
    }
    
    if(carry>0) {
        digitQueue->push_front(carry);
    }
    
    
    delete (*inputQueue);
    *inputQueue = digitQueue;
    
}

void Problem16::GetAnswer()
{
    printf("Answer: %u\r\n", this->answer);
}

void Problem16::GetInputs()
{
    this->ProjectFunctions->GetInput(&this->input, 1000, "power of two");
}