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

#ifndef PROBLEM16_H
#define	PROBLEM16_H

#include "../AbstractProblem.h"
#include <deque>
#include <cstring>

class Problem16 : public AbstractProblem
{
    
private:
    uint32_t input, answer;
    void MultiplyByTwo(std::deque<uint8_t> **inputQueue);
    std::deque<uint8_t>* GetPowerOfTwo(uint32_t power);
public:
    Problem16();
    virtual void Execute();
    virtual void GetInputs();
    virtual void GetAnswer();
};

#endif	/* PROBLEM16_H */

