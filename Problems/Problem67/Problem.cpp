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
 * PROBLEM #67 
 *********************/

/*

By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'), a 15K text file containing a triangle with one-hundred rows.

NOTE: This is a much more difficult version of Problem 18. It is not possible
to try every route to solve this problem, as there are 299 altogether! If you 
could check one trillion (1012) routes every second it would take over twenty 
billion years to check them all. There is an efficient algorithm to 
solve it. ;o)

*/

#include <cstring>
#include <stdio.h>
#include "../AbstractProblem.h"
#include "Problem.h"
#include "Data.h"

#define GRAPH_ROWS 4

FACTORY(Problem67)

Problem67::Problem67()
{
    this->ProblemName = new std::string("Maximum path sum I");
    this->ProblemNumber = 67;
}

void Problem67::Execute()
{    
    row *firstRow;        
    
    firstRow = this->BuildTree(100);
    this->BuildLinks(firstRow);
    this->InsertData(firstRow, data);
    this->ComputePaths(firstRow);
    
    this->GetLargestSum(firstRow);
}

/**
 * Builds the initial binary tree.
 * 
 * @param size
 * @return 
 */
row* Problem67::BuildTree(uint32_t size)
{
    uint8_t i, j;
    
    row *firstRow = NULL, *currentRow, *lastRow;
    node *currentNode, *nextNode;       
    
    // Build the tree!
    for(i = 0;i < size; i++) {
        
        // Create the new row and check if its the first row.
        currentRow = new row();                
        if(firstRow == NULL) {
            firstRow = currentRow;
        }        
        
        // If the last row is set, then make sure we link it to the current row.
        if(lastRow != NULL) {
            lastRow->nextRow = currentRow;
        }        
        lastRow = currentRow;
        
        // Create the first node of the row.
        currentRow->firstNode = new node();
        currentNode = currentRow->firstNode;
        currentNode->distance = -1;
        
        // Create the remaining nodes.
        for(j = 0;j < i; j++) {
            nextNode = new node();
            nextNode->distance = -1;
            nextNode->neightborLeft = currentNode;
            currentNode->neightborRight = nextNode;
            currentNode = nextNode;
        }
    }
    
    // Return a reference to the first row.
    return firstRow;
}

/**
 * Inserts the given pointed data into the grid.
 * 
 * @param grid
 * @param data
 */
void Problem67::InsertData(row *grid, uint8_t *data)
{
    uint32_t index = 0;
    row *currentRow;
    node *currentNode;
    
    currentRow = grid;
    
    while(currentRow != NULL) {
        currentNode = currentRow->firstNode;
        while(currentNode != NULL) {
            currentNode->value = data[index++];
            currentNode = currentNode->neightborRight;
        }        
        currentRow = currentRow->nextRow;
    }
}

/**
 * Builds the child links of a tree.
 * 
 * @param firstRow
 */
void Problem67::BuildLinks(row* firstRow)
{
    uint32_t i;
    row *currentRow, *nextRow;
    node *currentNode, *nextNode;
    
    currentRow = firstRow;
    
    while(currentRow != NULL) {
        nextRow = currentRow->nextRow;
        if(nextRow == NULL) {
            return;
        }
        
        currentNode = currentRow->firstNode;
        
        i=0;
        
        while(currentNode != NULL) {
            nextNode = this->GetRowIndex(nextRow, i++);
            currentNode->childLeft = nextNode;
            currentNode->childRight = nextNode->neightborRight;
            currentNode = currentNode->neightborRight;
        }
        
        currentRow = currentRow->nextRow;
    }
}

/**
 * Retrieves a node at the given index of the row.
 * 
 * @param row
 * @param index
 * @return 
 */
node* Problem67::GetRowIndex(row* row, uint8_t index)
{
    node* currentNode = row->firstNode;    
    
    uint8_t i = 0;
    while(currentNode != NULL && i++ < index) {
        currentNode = currentNode->neightborRight;
    }
    
    return currentNode;
}

/**
 * Prints a tree.
 * 
 * @param firstRow
 */
void Problem67::PrintTree(row *firstRow)
{
    row *currentRow;
    node *currentNode;
    
    // Print the table.
    currentRow = firstRow;
    while(currentRow != NULL) {
        currentNode = currentRow->firstNode;
        while(currentNode != NULL) {
            printf("%i ", currentNode->value);
            currentNode = currentNode->neightborRight;
        }
        printf("\r\n");
        currentRow = currentRow->nextRow;
    }

    printf("\r\n");
    printf("\r\n");
        
    // Print the table.
    currentRow = firstRow;
    while(currentRow != NULL) {
        currentNode = currentRow->firstNode;
        while(currentNode != NULL) {
            printf("%i ", currentNode->distance);
            currentNode = currentNode->neightborRight;
        }
        printf("\r\n");
        currentRow = currentRow->nextRow;
    }
}

/**
 * Compute the longest path.
 * 
 * @param firstRow
 */
void Problem67::ComputePaths(row *firstRow)
{
    row *currentRow;
    node *currentNode, *childLeft, *childRight;
    
    int32_t computeDistance;
    
    // Get the first row and node.
    currentRow = firstRow;
    
    // Set the distance of the first node to the value.
    currentRow->firstNode->distance = currentRow->firstNode->value;    
    
    while(currentRow != NULL) {
        currentNode = currentRow->firstNode;
        while(currentNode != NULL) {
            childLeft = currentNode->childLeft;
            childRight = currentNode->childRight;
            
            if(childLeft != NULL) {
                computeDistance = currentNode->distance + childLeft->value;
                if(childLeft->distance == -1 || computeDistance > childLeft->distance) {
                    childLeft->distance = computeDistance;
                }
            }
            
            if(childRight != NULL) {
                computeDistance = currentNode->distance + childRight->value;
                if(childRight->distance == -1 || computeDistance > childRight->distance) {
                    childRight->distance = computeDistance;
                }
            }
            
            currentNode = currentNode->neightborRight;
        }
        
        currentRow = currentRow->nextRow;
    }
}

void Problem67::GetLargestSum(row* firstRow)
{
    row *currentRow;
    node *currentNode;
    int32_t largestSum = 0;
    
    // Get the last row.
    currentRow = firstRow;
    while(currentRow->nextRow != NULL) {
        currentRow = currentRow->nextRow;
    }
    
    // Iterate through all nodes.
    currentNode = currentRow->firstNode;
    while(currentNode != NULL) {
        if(currentNode->distance > largestSum) {
            largestSum = currentNode->distance;
        }
        
        currentNode = currentNode->neightborRight;
    }
    
    this->answer = largestSum;
}

void Problem67::GetAnswer()
{
    printf("Answer: %u\r\n", this->answer);
}

void Problem67::GetInputs()
{
    
}