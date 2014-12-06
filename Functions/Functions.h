/* 
 * Project Euler Implementation
 *
 * Author:  Brendan Bates
 * Website: http://www.brendan-bates.com
 * Email:   me@brendan-bates.com
 * License: Apache License, Version 2.0 (See LICENSE file for details)
 *
 * Various functions which may be reused in various places.
 */
#ifndef FUNCTIONS_H
#define	FUNCTIONS_H

#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <stdint.h>

// Prime Root Structure
typedef struct prime_root {
    uint64_t number;
    uint64_t power;
} prime_root_t;

class Functions {
    
private:    
    void AddPrimeFactor(uint64_t factor, std::vector<prime_root_t>* vector);
    
public:
    virtual ~Functions() {}
    virtual void GetInput(uint32_t* input, uint32_t defaultValue, const char* name);
    virtual void GetInput(uint64_t* input, uint64_t defaultValue, const char* name);
    virtual void GetInput(char* input, char defaultValue, const char* name);
    virtual bool IsPrime(uint64_t number);
    virtual void GetPrimeFactors(uint64_t number, std::vector<prime_root_t>*);
    virtual uint8_t* GetPrimeSieve(uint32_t limit);
    virtual uint32_t CountFactors(uint64_t number);
    virtual void GetFactors(uint64_t number, std::vector<uint32_t>* factors);
    
};

#endif	/* FUNCTIONS_H */

