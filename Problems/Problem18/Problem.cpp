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

/*

By starting at the top of the triangle below and moving to adjacent numbers on 
 * the row below,the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is,3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

NOTE: As there are only 16384 routes,it is possible to solve this problem by 
 * trying every route. However,Problem 67,is the same challenge with a 
 * triangle containing one-hundred rows; it cannot be solved by brute force,
 * and requires a clever method! ;o)

*/

#include <cstring>
#include <stdio.h>
#include "../AbstractProblem.h"
#include "Problem.h"

#define GRAPH_ROWS 4

FACTORY(Problem18)

Problem18::Problem18()
{
    this->ProblemName = new std::string("Maximum path sum I");
    this->ProblemNumber = 18;
}

void Problem18::Execute()
{    
    row *firstRow;
        
    uint8_t data[] = {
        75,95,64,17,47,82,18,35,87,10,20,4,
        82,47,65,19,1,23,75,3,34,88,2,77,
        73,7,63,67,99,65,4,28,6,16,70,92,
        41,41,26,56,83,40,80,70,33,41,48,72,
        33,47,32,37,16,94,29,53,71,44,65,25,
        43,91,52,97,51,14,70,11,33,28,77,73,
        17,78,39,68,17,57,91,71,52,38,17,14,
        91,43,58,50,27,29,48,63,66,4,68,89,
        53,67,30,73,16,69,87,40,31,4,62,98,
        27,23,9,70,98,73,93,38,53,60,4,23
    };
    
    firstRow = this->BuildTree(15);
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
row* Problem18::BuildTree(uint32_t size)
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
void Problem18::InsertData(row *grid, uint8_t *data)
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
void Problem18::BuildLinks(row* firstRow)
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
node* Problem18::GetRowIndex(row* row, uint8_t index)
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
void Problem18::PrintTree(row *firstRow)
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
void Problem18::ComputePaths(row *firstRow)
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

void Problem18::GetLargestSum(row* firstRow)
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

void Problem18::GetAnswer()
{
    printf("Answer: %u\r\n", this->answer);
}

void Problem18::GetInputs()
{
    
}