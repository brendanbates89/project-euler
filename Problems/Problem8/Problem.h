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
 * PROBLEM #8 
 *********************/

#ifndef PROBLEM8_H
#define	PROBLEM8_H

#include "../AbstractProblem.h"
#include <cstring>

class Problem8 : public AbstractProblem
{
private:
    uint32_t answer;
public:
    Problem8();
    virtual void Execute();
    virtual void GetInputs();
    virtual void GetAnswer();
};

#endif	/* PROBLEM8_H */

