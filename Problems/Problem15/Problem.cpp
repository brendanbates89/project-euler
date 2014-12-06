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

/*

 

*/

#include <cstring>
#include <stdio.h>
#include <unordered_map>
#include <stdexcept>
#include "../AbstractProblem.h"
#include "Problem.h"

FACTORY(Problem15)

Problem15::Problem15()
{
    this->ProblemName = new std::string("Lattice paths");
    this->ProblemNumber = 15;
}

void Problem15::Execute()
{
    node *grid, *targetNode;
    
    // Build the grid and get the node in the bottom right corner.
    grid = BuildGrid(this->inputSize+1);
    targetNode = GetNode(grid, this->inputSize, this->inputSize);
    
    // Get the number of paths.
    this->answer = this->FindPaths(grid, targetNode);
}

/**
 * Recursively finds all paths to the target node.
 * 
 * According to the problem specs, we can only go down and right.
 * 
 * @param node
 * @return 
 */
uint64_t Problem15::FindPaths(node *currentNode, node *targetNode)
{
    uint64_t paths;
    bool cacheHit;
        
    // We've reached the target.  Return 1.
    if(currentNode == targetNode) {
        return 1;
    }    
    
    // Attempt a cache lookup.
    try {
        cacheHit = true;
        paths = this->hashtable.at(currentNode);
    } catch(const std::out_of_range& ex)
    {
        cacheHit = false;
    }
    
    if(!cacheHit)
    {
        paths = 0;
        if(currentNode->right != NULL) {
            paths += this->FindPaths(currentNode->right, targetNode);
        }

        if(currentNode->down != NULL) {
            paths += this->FindPaths(currentNode->down, targetNode);
        }        
        this->hashtable[currentNode] = paths;
    }
    
    return paths;
}

node* Problem15::BuildGrid(uint32_t size)
{
    node *firstNode, *rowNode, *currentNode, *nextNode, *lastRowNode;
    
    lastRowNode = NULL;
    firstNode = NULL;
    
    for(uint32_t i=0;i<size;i++)
    {
        // Create the first row node.
        rowNode = new node;
        currentNode = rowNode;
        
        // Keep a reference to the first node created (top left corner).
        if(firstNode == NULL) {
            firstNode = currentNode;
        }
        
        // Create the entire row.
        for(uint32_t j=1;j<size;j++)
        {
            // Create the next entry.
            nextNode = new node;
            
            // Link the next entry to the current.
            currentNode->right = nextNode;
            nextNode->left = currentNode;
            
            // Switch to the next node.
            currentNode = nextNode;
        }
        
        // Check to see if the last row exists.
        // If it does, we need to link it up!
        if(lastRowNode != NULL) {
            // Go to the beginning of the row.
            currentNode = rowNode;
            
            // Iterate until they are null.
            while(currentNode != NULL && lastRowNode != NULL) {
                currentNode->up = lastRowNode;
                lastRowNode->down = currentNode;
                
                currentNode = currentNode->right;
                lastRowNode = lastRowNode->right;
            }
        }
        
        lastRowNode = rowNode;
    }
    
    return firstNode;
}

node* Problem15::GetNode(node *grid, uint32_t x, uint32_t y)
{
    uint32_t i;
    
    for(i=0;i<x;i++) {
        if(grid != NULL) {
            grid = grid->right;
        }
    }
    
    for(i=0;i<y;i++) {
        if(grid != NULL) {
            grid = grid->down;
        }
    }
    
    return grid;
}

void Problem15::GetAnswer()
{
    printf("Answer: %llu\r\n", this->answer);
}

void Problem15::GetInputs()
{
    this->ProjectFunctions->GetInput(&this->inputSize, 20, "grid size");
}