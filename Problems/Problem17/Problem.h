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
 * PROBLEM #17 
 *********************/

#ifndef PROBLEM17_H
#define	PROBLEM17_H

#include "../AbstractProblem.h"
#include <cstring>

class Problem17 : public AbstractProblem
{
private:
    uint32_t answer;
    uint8_t SingleOrTeen(uint8_t number);
    uint32_t GetNumberLength(uint32_t number);
    uint8_t PowerOfTen(uint8_t number);
public:
    Problem17();
    virtual void Execute();
    virtual void GetInputs();
    virtual void GetAnswer();
};

#endif	/* PROBLEM17_H */

