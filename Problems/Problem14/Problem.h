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
 * PROBLEM #14 
 *********************/

#ifndef PROBLEM14_H
#define	PROBLEM14_H

#include "../AbstractProblem.h"
#include <cstring>
#include <unordered_map>
#include <stdio.h>

class Problem14 : public AbstractProblem
{
private:
    uint32_t answer, input, method;
    uint64_t sum;
    std::unordered_map<uint64_t, uint32_t> hashtable;
    
    uint32_t GetSteps(uint64_t number);
    void CollatzIteration(uint64_t& number);
public:
    Problem14();
    virtual void Execute();
    virtual void GetInputs();
    virtual void GetAnswer();
    void BruteForce();
    void RecursiveMap();
};

#endif	/* PROBLEM14_H */

