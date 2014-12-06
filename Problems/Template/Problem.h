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
 * PROBLEM #Template 
 *********************/

#ifndef PROBLEMTemplate_H
#define	PROBLEMTemplate_H

#include "../AbstractProblem.h"
#include <cstring>

class ProblemTemplate : public AbstractProblem
{
public:
    ProblemTemplate();
    virtual void Execute();
    virtual void GetInputs();
    virtual void GetAnswer();
};

#endif	/* PROBLEMTemplate_H */

