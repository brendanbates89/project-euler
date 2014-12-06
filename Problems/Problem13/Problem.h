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
 * PROBLEM #13 
 *********************/

#ifndef PROBLEM13_H
#define	PROBLEM13_H

#include "../AbstractProblem.h"
#include <cstring>
#include <queue>
#include <deque>

class Problem13 : public AbstractProblem
{
private:
    std::deque<uint8_t> numbers;
    uint64_t answer;
    uint32_t numDigits;
public:
    Problem13();
    virtual void Execute();
    virtual void GetInputs();
    virtual void GetAnswer();
    
    void InitDigits();
    void AddDigit(uint8_t digit);
};

#endif	/* PROBLEM13_H */

