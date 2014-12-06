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

#ifndef PROBLEM1_H
#define	PROBLEM1_H

#include "../AbstractProblem.h"
#include <cstring>
#include <deque>

class Problem4 : public AbstractProblem
{
private:
    uint32_t answer;
public:
    Problem4();
    virtual void Execute();
    virtual void GetInputs();
    virtual void GetAnswer();
    void MapNumberToDeque(uint32_t number, std::deque<int>*);
    bool IsPalendrome(uint32_t number);
};

#endif	/* PROBLEM1_H */

