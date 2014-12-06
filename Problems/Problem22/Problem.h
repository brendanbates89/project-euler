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
 * PROBLEM #22 
 *********************/

#ifndef PROBLEM22_H
#define	PROBLEM22_H

#include "../AbstractProblem.h"
#include <cstring>
#include <string>
#include <vector>

class Problem22 : public AbstractProblem
{
private:
    uint64_t answer;
    uint32_t LoadNames(std::vector<char*> &names);
    void QuickSort(std::vector<char*> &names, uint32_t left, uint32_t right);
    uint32_t QuickSortPartition(std::vector<char*> &names, uint32_t left, uint32_t right, uint32_t pivotIndex);
    uint8_t CompareStrings(char* string1, char* string2);
    uint64_t NameScores(std::vector<char*> &names, uint32_t nameCount);
public:
    Problem22();
    virtual void Execute();
    virtual void GetInputs();
    virtual void GetAnswer();
};

#endif	/* PROBLEM22_H */

