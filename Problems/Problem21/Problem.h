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
 * PROBLEM #21 
 *********************/

#ifndef PROBLEM21_H
#define	PROBLEM21_H

#include "../AbstractProblem.h"
#include <cstring>
#include <unordered_map>
#include <vector>

class Problem21 : public AbstractProblem
{
private:
    std::unordered_map<uint32_t, uint32_t> numberTable;
    std::vector<uint32_t> amicableNumbers;
    
    uint32_t answer;
    uint32_t input;
public:
    Problem21();
    virtual void Execute();
    virtual void GetInputs();
    virtual void GetAnswer();
};

#endif	/* PROBLEM21_H */

