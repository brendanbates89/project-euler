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
 * PROBLEM #18 
 *********************/

#ifndef PROBLEM18_H
#define	PROBLEM18_H

#include "../AbstractProblem.h"
#include <cstring>

struct node {
    uint8_t value;
    int32_t distance;
    node* childLeft;
    node* childRight;
    node* neightborRight;
    node* neightborLeft;
};

struct row {
    node* firstNode;
    row* nextRow;
};

class Problem18 : public AbstractProblem
{
private:
    uint32_t answer;
    
    void BuildLinks(row* firstRow);
    row* BuildTree(uint32_t size);
    node* GetRowIndex(row* row, uint8_t index);
    void FillGridInverse(row* firstRow);
    void InsertData(row *grid, uint8_t *data);
    void PrintTree(row *firstRow);
    void ComputePaths(row *firstRow);
    void GetLargestSum(row *firstRow);
public:
    Problem18();
    virtual void Execute();
    virtual void GetInputs();
    virtual void GetAnswer();
};

#endif	/* PROBLEM18_H */

