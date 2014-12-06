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
 * PROBLEM #2 
 *********************/

#ifndef PROBLEM1_H
#define	PROBLEM1_H

#include "../AbstractProblem.h"
#include <cstring>

class Problem2 : public AbstractProblem
{
private:
    uint32_t answer;
    uint32_t max;
public:
    Problem2();
    virtual void Execute();
    virtual void GetInputs();
    virtual void GetAnswer();
};

#endif	/* PROBLEM1_H */

