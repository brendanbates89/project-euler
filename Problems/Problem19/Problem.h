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
 * PROBLEM #19 
 *********************/

#ifndef PROBLEM19_H
#define	PROBLEM19_H

#include "../AbstractProblem.h"
#include <cstring>

#define JAN 1
#define FEB 2
#define MAR 3
#define APR 4
#define MAY 5
#define JUN 6
#define JUL 7
#define AUG 8
#define SEP 9
#define OCT 10
#define NOV 11
#define DEC 12

#define SUN 1
#define MON 2
#define TUE 3
#define WED 4
#define THU 5
#define FRI 6
#define SAT 7

class Problem19 : public AbstractProblem
{
private:
    uint8_t answer;
    uint8_t GetDaysInMonth(uint8_t month, uint32_t year);
    uint32_t GetDaysInYear(uint32_t year);
    uint8_t GetDayOfWeek(uint8_t day, uint8_t month, uint32_t year);
public:
    Problem19();
    virtual void Execute();
    virtual void GetInputs();
    virtual void GetAnswer();
};

#endif	/* PROBLEM19_H */

