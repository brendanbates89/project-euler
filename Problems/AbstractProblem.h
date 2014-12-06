/* 
 * Project Euler Implementation
 *
 * Author:  Brendan Bates
 * Website: http://www.brendan-bates.com
 * Email:   me@brendan-bates.com
 * License: Apache License, Version 2.0 (See LICENSE file for details)
 *
 * The AbstractProblem serves as an "interface" for the project euler problems.
 * Each Problem must implement the methods below, and each problem must also
 * have a function named "factory".  This Factory function is what is used to
 * instantiate the problem itself.
 */
 
#ifndef IPROBLEM_H
#define	IPROBLEM_H

#include <iostream>
#include <cstring>
#include "../Functions/Functions.h"
#include <dlfcn.h>

class AbstractProblem {
protected:
    std::string* ProblemName;
    uint32_t ProblemNumber;
    Functions* ProjectFunctions;    
    
public:
    virtual ~AbstractProblem() {}
    virtual void GetInputs() = 0;
    virtual void GetAnswer() = 0;
    virtual void Execute() = 0;
    
    std::string* GetProblemName() { return this->ProblemName; }
    uint32_t GetProblemNumber() { return this->ProblemNumber; }
    void SetFunctions(Functions* projectFunctions) { this->ProjectFunctions = projectFunctions; }
};

/**
 * Factory macro.  This allows the individual problems to easy
 * declare their factory function, and avoids code duplication if
 * the factory format changes in the future.
 */
#define FACTORY(class_name) extern "C" { \
    AbstractProblem* factory() \
    { \
        return new class_name (); \
    } \
}

#endif	/* IPROBLEM_H */

