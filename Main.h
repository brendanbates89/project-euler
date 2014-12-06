/* 
 * Project Euler Implementation
 *
 * Author:  Brendan Bates
 * Website: http://www.brendan-bates.com
 * Email:   me@brendan-bates.com
 * License: Apache License, Version 2.0 (See LICENSE file for details)
 *
 * Main file for loading and running ProjectEuler questions.
 */
 
#ifndef MAIN_H
#define	MAIN_H

#include "Problems/AbstractProblem.h"
#include "Functions/Functions.h"
#include <stdio.h>

// Define the pointer for the factory function.  This will be dynamically loaded in.
typedef AbstractProblem* (*FactoryPtr)(void);

// Define a struct for passing the selected problem, and the
// handle for which is open for the problem.
typedef struct {
    AbstractProblem* problem;
    void* handle;
} Problem;

uint32_t GetProblem(void);
Problem* LinkProblem(uint32_t, char*);
void DispatchProblem(Problem*, Functions* projectFunctions);
void CloseProblem(Problem*);

#endif	/* MAIN_H */

