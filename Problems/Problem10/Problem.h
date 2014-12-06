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
 * PROBLEM #10 
 *********************/

#ifndef PROBLEM10_H
#define	PROBLEM10_H

#include "../AbstractProblem.h"
#include <cstring>

class Problem10 : public AbstractProblem
{
private:
    uint32_t input;
    uint64_t answer;
public:
    Problem10();
    virtual void Execute();
    virtual void GetInputs();
    virtual void GetAnswer();
};

#endif	/* PROBLEM10_H */

