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

/*

 

*/

#include <cstring>
#include <stdio.h>
#include "../AbstractProblem.h"
#include "Problem.h"

FACTORY(ProblemTemplate)

ProblemTemplate::ProblemTemplate()
{
    this->ProblemName = new std::string("");
    this->ProblemNumber = Template;
}

void ProblemTemplate::Execute()
{
    
}

void ProblemTemplate::GetAnswer()
{
    
}

void ProblemTemplate::GetInputs()
{
    
}