/* 
 * Project Euler Implementation
 *
 * Author:  Brendan Bates
 * Website: http://www.brendan-bates.com
 * Email:   me@brendan-bates.com
 * License: Apache License, Version 2.0 (See LICENSE file for details)
 *
 */

#ifndef PROBLEM1_H
#define	PROBLEM1_H

#include "../AbstractProblem.h"
#include <cstring>

class Problem1 : public AbstractProblem
{
private:    
    uint32_t input;
    uint32_t answer;
public:
    Problem1();
    virtual void Execute();
    virtual void GetInputs();
    virtual void GetAnswer();
    uint32_t FindMultiples(uint32_t limit);
};

#endif	/* PROBLEM1_H */

