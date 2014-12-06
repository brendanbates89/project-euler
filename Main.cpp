/* 
 * Project Euler Implementation
 *
 * Author:  Brendan Bates
 * Website: http://www.brendan-bates.com
 * Email:   me@brendan-bates.com
 * License: Apache License, Version 2.0 (See LICENSE file for details)
 *
 * Main file for loading and running ProjectEuler questions.  All of the
 * questions are built as an individual shared object and loaded/freed
 * individually.
 */

#include <cstdlib>
#include <stdio.h>
#include <dlfcn.h>
#include <cstdio>
#include <time.h>
#include <math.h>
#include "Problems/AbstractProblem.h"
#include "Functions/Functions.h"
#include "Main.h"

/*
 * Primary entry function.
 */
int main(int argc, char** argv) 
{
    Problem* problem;
    Functions projectFunctions;
    char path[256] = "build";
    
    if(argc > 1) {
        strncpy(path, argv[1], 256);
    }
    
    uint32_t problemNumber = GetProblem();
    problem = LinkProblem(problemNumber, path);
    
    if(problem != NULL) {
        DispatchProblem(problem, &projectFunctions);
        CloseProblem(problem);  
    }

    return 0;
}   

/**
 * Retrieves the integer value of the desired problem from the user.
 * 
 * @return uint32_t
 */
uint32_t GetProblem()
{
    uint32_t number;
    
    // Print Introduction.
    printf("Welcome to my C++ implementation of Project Euler.\r\n");
    printf("Written by Brendan Bates <me@brendan-bates.com>.\r\n");
    printf("For more information on Project Euler, visit https://projecteuler.net/\r\n");
    printf("\r\n\tEnter Problem Number: ");
    
    // Get problem number.
    scanf("%u", &number);
    
    // Validate the problem number is above 0.
    if(number < 1)
    {
        printf("\r\nNumber must be above zero.");
        return 0;
    }
    
    return number;
}

/**
 * Dynamically loads the given problem number if it exists.
 * 
 * @param number The problem number to load.
 * @return AbstractProblem*
 */
Problem* LinkProblem(uint32_t number, char* path)
{
    void* handle;
    char module[100];
    char* error;
    FILE *file;
    
    // The problem which is selected by the user.
    AbstractProblem* selectedProblem;
    
    // The function pointer to the problem factory.
    FactoryPtr factory;
    
    // Error check the number.
    if(number < 1) {
        return NULL;
    }
    
    // Generate the filename.
    sprintf(module, "%s/Problem%u.so", path, number);
    
    // Check to make sure the file exists.
    if(!(file = fopen(module, "r"))) {
        printf("\r\nGiven problem does not exist.\r\n");
        printf("The problem may not be completed yet, or the problem itself\r\n");
        printf("may not exist in Project Euler.");
        return NULL;
    } else
    {        
        fclose(file);
    }        
    
    // Attempt to open the link using dlopen.
    handle = dlopen(module, RTLD_NOW);
    if(!handle) {
        error = dlerror();
        printf("\r\nError opening the specified module: \r\n\t");
        printf("%s",error);
        return NULL;
    }
    
    // Attempt to link to the factory function provided by the
    // problem.  This function is what will return the implemented 
    // AbstractProblem back to us.
    //
    // C++ requires explicit casting of void* function pointers to
    // their target types, so we need to cast the linked object to 
    // our FactoryPtr.
    factory = (FactoryPtr)dlsym(handle, "factory");
    if ((error = dlerror()) != NULL)  {
        printf("\r\nError opening the specified module: \r\n\t");
        printf("%s",error);
        dlclose(handle);
        return NULL;
    }
    
    // Instantiate the new problem.
    selectedProblem = (*factory)();
    if(!selectedProblem) {
        printf("\r\nError linking the selected problem.");
        dlclose(handle);
        return NULL;
    }
    
    return new Problem {
        problem     : selectedProblem,
        handle      : handle
    };
}

/**
 * Dispatches the given pointer to an AbstractProblem by calling the
 * execute function.
 * 
 * @param problem
 */
void DispatchProblem(Problem* selectedProblem, Functions* projectFunctions)
{    
    time_t start, end;
    double duration;
    
    printf("\r\n---------------------------------------------\r\n");
    printf("Number:\t%u\r\n", selectedProblem->problem->GetProblemNumber());
    printf("Name: \t%s\r\n", selectedProblem->problem->GetProblemName()->c_str());
    printf("Link: \thttps://projecteuler.net/problem=%u\r\n", selectedProblem->problem->GetProblemNumber());
    printf("---------------------------------------------");
    printf("\r\n\r\n");
    
    // Print line break before executing.
    selectedProblem->problem->SetFunctions(projectFunctions);
    selectedProblem->problem->GetInputs();
    
    // Execute with timer.
    start = time(0);
    selectedProblem->problem->Execute();
    end = time(0);
    duration = difftime(end, start) * 1000.0;
    
    // Get answer.
    selectedProblem->problem->GetAnswer();
    
    // Execution time.
    printf("Execution time: %f\r\n", duration);
    printf("Total ticks: %u", (uint32_t)(end - start));
}

/**
 * Clean up after the problem has completed.
 */
void CloseProblem(Problem* selectedProblem) {    
    // Delete the problem which was created from the factory.
    delete selectedProblem->problem;
    
    // Close the dynamic link file and handle.
    dlclose(selectedProblem->handle);
}