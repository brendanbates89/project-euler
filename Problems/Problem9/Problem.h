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

#ifndef PROBLEM9_H
#define	PROBLEM9_H

#include "../AbstractProblem.h"
#include <cstring>

class Problem9 : public AbstractProblem
{
private:
    uint32_t answer, method, input;
    void BruteForce();
    void Iterative();
public:
    Problem9();
    virtual void Execute();
    virtual void GetInputs();
    virtual void GetAnswer();
};

#endif	/* PROBLEM9_H */

