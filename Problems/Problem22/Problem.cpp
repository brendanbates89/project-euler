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

/*

 

*/

#include <cstring>
#include <stdio.h>
#include <iostream>
#include "../AbstractProblem.h"
#include "Problem.h"
#include <string>
#include <vector>

FACTORY(Problem22)

#define LESS    0
#define GREATER 1
#define EQUAL   2

Problem22::Problem22()
{
    this->ProblemName = new std::string("Names scores");
    this->ProblemNumber = 22;
}

void Problem22::Execute()
{
    std::vector<char*> names;
    uint32_t nameCount;
    
    nameCount = this->LoadNames(names);
    this->QuickSort(names, 0, nameCount-1);    
    this->answer = this->NameScores(names, nameCount);
}

uint32_t Problem22::LoadNames(std::vector<char*> &names)
{
    FILE *file;
    char* currentName = NULL;
    char buffer;
    uint8_t tempBuff[100] = { 0 };
    uint32_t nameCount = 0, currentNameSize = 1;
    
    file = fopen("../Files/Problem22-names.txt", "r");
    if(file == NULL) {
        perror("Error opening file.");
        return 0;
    }
    
    while(!feof(file) && nameCount < 50)
    {
        if(fread(&buffer, 1, 1, file) < 1)
        {
            break;
        }
            
        if(buffer == '\n') {
            // Push back name.
            currentName = (char*)malloc(currentNameSize);
            strncpy(currentName, (char*)tempBuff, currentNameSize);
            names.push_back(currentName);
            
            // New name.
            nameCount++;
            tempBuff[0] = '\0';
            currentNameSize = 1;
        } else if(buffer != '\r') {
            tempBuff[currentNameSize-1] = buffer;
            tempBuff[currentNameSize++] = '\0';
        }
    }
    
    return nameCount;
}

void Problem22::QuickSort(std::vector<char*> &names, uint32_t left, uint32_t right)
{
    uint32_t pivot;
    
    if(left < right) {
        pivot = left + ((right-left)/2);
        pivot = this->QuickSortPartition(names, left, right, pivot);
        this->QuickSort(names, left, pivot - 1);
        this->QuickSort(names, pivot + 1, right);
    }
}

uint32_t Problem22::QuickSortPartition(std::vector<char*> &names, uint32_t left, uint32_t right, uint32_t pivotIndex)
{
    char* swap;
    char* pivotValue;
    uint32_t storeIndex = left;
    
    pivotValue = names[pivotIndex];
    
    // Swap pivot and right.
    swap = names[right];
    names[right] = names[pivotIndex];
    names[pivotIndex] = swap;
        
    for(uint32_t i = left; i < right; i++) {
        if(this->CompareStrings(names[i], pivotValue) == LESS) {
            swap = names[i];
            names[i] = names[storeIndex];
            names[storeIndex] = swap;
            storeIndex++;
        }
    }
    
    swap = names[storeIndex];
    names[storeIndex] = names[right];
    names[right] = swap;
    
    return (storeIndex > 0 ? storeIndex : 1);
}

uint8_t Problem22::CompareStrings(char* string1, char* string2)
{    
    while(*string1 != '\0' && *string2 != '\0')
    {   
        if(*string1 < *string2) {
            return LESS;
        }
        
        if(*string1 > *string2) {
            return GREATER;
        }
        
        ++string1, ++string2;
    }
    
    if(*string1 == '\0' && *string2 != '\0') {
        return LESS;
    }
    
    if(*string1 != '\0' && *string2 == '\0') {
        return GREATER;
    }
    
    return EQUAL;
}

uint64_t Problem22::NameScores(std::vector<char*> &names, uint32_t nameCount)
{
    char* currentName;
    uint64_t currentScore, tempScore;
    
    currentScore = 0;
    
    for(uint32_t i = 0; i < nameCount; i++) {
        printf("%s\n", names[i]);
        currentName = names[i];
        tempScore = 0;
        while(*currentName != '\0') {
            tempScore += (*currentName - 'A') + 1;
            currentName++;
        }
        tempScore *= (i+1);
        currentScore += tempScore;
    }
    
    return currentScore;
}

void Problem22::GetAnswer()
{
    printf("Answer: %llu\n", this->answer);
}

void Problem22::GetInputs()
{
    
}