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
 * PROBLEM #6 
 *********************/

#ifndef PROBLEM1_H
#define	PROBLEM1_H

#include "../AbstractProblem.h"
#include <cstring>

class Problem6 : public AbstractProblem
{
private:
    uint64_t answer;
    uint32_t input;
    void BruteForce();
public:
    Problem6();
    virtual void Execute();
    virtual void GetInputs();
    virtual void GetAnswer();
};

#endif	/* PROBLEM1_H */

