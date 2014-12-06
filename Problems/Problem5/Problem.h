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
 * PROBLEM #5 
 *********************/

#ifndef PROBLEM1_H
#define	PROBLEM1_H

#include "../AbstractProblem.h"
#include <cstring>

class Problem5 : public AbstractProblem
{
private:
    uint64_t answer;
    uint64_t input;
    void BruteForce();
    void PrimeFactor();
        
public:
    Problem5();
    virtual void Execute();
    virtual void GetInputs();
    virtual void GetAnswer();
    void AddToList(prime_root_t* factor, std::vector<prime_root_t>* vector);
};

#endif	/* PROBLEM1_H */

