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
 * PROBLEM #3 
 *********************/

#ifndef PROBLEM1_H
#define	PROBLEM1_H

#include "../AbstractProblem.h"

class Problem3 : public AbstractProblem
{
private:
    uint64_t number;
    uint64_t answer;
    void BruteForce();
    void PrimeFactors();
    
public:
    Problem3();
    virtual void Execute();
    virtual void GetInputs();
    virtual void GetAnswer();
};

#endif	/* PROBLEM1_H */

