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
 * PROBLEM #15 
 *********************/

#ifndef PROBLEM15_H
#define	PROBLEM15_H

#include "../AbstractProblem.h"
#include <cstring>
#include <unordered_map>

struct node
{    
    node* left;
    node* right;
    node* up;
    node* down;
};

class Problem15 : public AbstractProblem
{
private:
    std::unordered_map<node*, uint64_t> hashtable;
    uint64_t answer;
    uint32_t inputSize;
    uint64_t FindPaths(node* currentNode, node* targetNode);
    node* BuildGrid(uint32_t size);
    node* GetNode(node* grid, uint32_t x, uint32_t y);
public:
    Problem15();
    virtual void Execute();
    virtual void GetInputs();
    virtual void GetAnswer();
};

#endif	/* PROBLEM15_H */

