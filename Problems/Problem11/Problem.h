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
 * PROBLEM #11 
 *********************/

#ifndef PROBLEM11_H
#define	PROBLEM11_H

#include "../AbstractProblem.h"
#include <cstring>

class Problem11 : public AbstractProblem
{
private:
    uint32_t answer;
public:
    Problem11();
    virtual void Execute();
    virtual void GetInputs();
    virtual void GetAnswer();
};

#endif	/* PROBLEM11_H */

