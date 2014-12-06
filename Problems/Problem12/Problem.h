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
 * PROBLEM #12 
 *********************/

#ifndef PROBLEM12_H
#define	PROBLEM12_H

#include "../AbstractProblem.h"
#include <cstring>

class Problem12 : public AbstractProblem
{
private:
    uint64_t answer;
    uint32_t input;
public:
    Problem12();
    virtual void Execute();
    virtual void GetInputs();
    virtual void GetAnswer();
};

#endif	/* PROBLEM12_H */

