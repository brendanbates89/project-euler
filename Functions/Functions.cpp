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

#include "Functions.h"
#include <cstring>
#include <cstdlib>
#include <vector>
#include <math.h>
#include <stdio.h>

void Functions::GetInput(uint32_t* input, uint32_t defaultValue, const char* name)
{
    int32_t temp = 0;
    
    printf("Enter %s (default is %u): ", name, defaultValue);
    scanf("%u", &temp);
    
    if(temp != 0) {
        *input = temp;
    } else
    {
        *input = defaultValue;
    }
}

void Functions::GetInput(char* input, char defaultValue, const char* name)
{
    char temp = 0;
    
    printf("Enter %s (default is %c): ", name, defaultValue);
    scanf("%c", &temp);
    
    if(temp != '\n') {
        *input = temp;
    } else
    {
        *input = defaultValue;
    }
}

void Functions::GetInput(uint64_t* input, uint64_t defaultValue, const char* name)
{
    int64_t temp = 0;
    
    printf("Enter %s (default is %llu): ", name, defaultValue);
    scanf("%llu", &temp);
    
    if(temp != 0) {
        *input = temp;
    } else
    {
        *input = defaultValue;
    }
}

/**
 * Determines if the given 64-bit integer is a prime number.
 * 
 * @param number
 * @return 
 */
bool Functions::IsPrime(uint64_t number)
{    
    if(number == 2) {
        return true;
    }
    else if(number < 2 || number % 2 == 0)
    {
        return false;
    }
    
    for(uint64_t i=3; (i*i)<=number; i+=2){
        if(number % i == 0 ) return false;
    }
    
    return true;
}

void Functions::GetFactors(uint64_t number, std::vector<uint32_t>* factors)
{
    uint64_t end, factor;
    
    // Add 1 and itself.
    factors->push_back(1);
    factors->push_back(number);
        
    // Check for 1.
    if(number == 1) {
        return;
    }
    
    factor = 2;
    end = (uint64_t)round(sqrt(number));
    
    while(factor <= end) {
        if(number % factor == 0) {
            // If this is a factor, add this and the inverse.
            factors->push_back(factor);
            factors->push_back(number / factor);
        }
        
        factor++;
    }
}

uint32_t Functions::CountFactors(uint64_t number)
{    
    uint64_t end, factor;
    uint32_t sum;
        
    // Check for 1.
    if(number == 1) {
        return 1;
    }
    
    sum = 2;
    factor = 2;
    end = (uint64_t)round(sqrt(number));
    
    while(factor <= end) {
        if(number % factor == 0) {
            sum += 2;
        }
        
        factor++;
    }
    
    return sum;
}

/**
 * Recursive algorithm which retrieves the prime factors of a given number.
 * It returns the values into a given vector of prime_root structures.
 * 
 * @param number
 * @param 
 */
void Functions::GetPrimeFactors(uint64_t number, std::vector<prime_root_t>* vector)
{
    uint64_t end, factor, temp;
    
    factor = 2;
    end = (int)round(sqrt(number));
    
    while(factor <= end) {
        // First, check if the number is in fact a factor, and that it's prime.
        if(number % factor == 0 && this->IsPrime(factor)) {            
            this->AddPrimeFactor(factor, vector);

            // Get the symmetrical factor.
            temp = number / factor;

            // Check if the matching factor is a prime.  If it is, then it can
            // be added to the vector of primes and we're done.  Otherwise,
            // recursively call on the non
            if(this->IsPrime(temp)) {
                // It's a prime!  We can add it to the vector.
                this->AddPrimeFactor(temp, vector);
            } else
            {
                // Nope; let's find the prime factor of the other term by
                // recursively calling the function.
                this->GetPrimeFactors(temp, vector);
            }
            
            // Since this particular number is a prime, we can return.
            return;
        } else
        {
            factor++;
        }
    }
    
    // At this point, if no factors are found, return the number.
    this->AddPrimeFactor(number, vector);
}

void Functions::AddPrimeFactor(uint64_t factor, std::vector<prime_root_t>* vector)
{
    prime_root_t newVector;
    bool match = false;
    
    for(std::vector<prime_root_t>::iterator it = vector->begin(); it != vector->end(); ++it)
    {
        // Found factor, increase the power.
        if(it->number == factor) {
            match = true;
            it->power++;
        }
    }
    
    if(!match) {
        newVector.number = factor;
        newVector.power = 1;
        vector->push_back(newVector);
    }
}

extern "C" {
        Functions* factory()
        {
        return new Functions();
        }
}

/**
 * Returns a list of primes using the Sieve of Eratosthenes.  All primes
 * in the array will be set to 0, all non-prime indexes set to 1.
 * 
 * @param limit
 * @param sieve
 */
uint8_t* Functions::GetPrimeSieve(uint32_t limit)
{
    uint32_t i, bound, item=0;
    uint64_t approx;
    uint8_t* sieve;
    
    // Get the approximation.  We will be using the n*ln(n) method to
    // approximate the prime one above.  Then we will multiply this by
    // two to guarentee the prime is in our set.
    approx = 2*((limit+1) * log(limit+1));
    
    // Create the sieve.  1 byte per number.  Fill it will all 0's.
    sieve = (uint8_t*)malloc(approx);
    memset(sieve, 0, approx);
    
    // Set 0 and 1 index to '1'.  These can be considered primes.
    sieve[0] = 1;
    sieve[1] = 1;
    
    // Perform the sieve.
    for(item = 1;item < (uint32_t)(ceil(sqrt(approx)));item++)
    {
        if(sieve[item] == 1) {
            continue;
        }
        
        bound = (uint32_t)(approx/item);
        for(i = 2;i<bound;i++) {
            sieve[i*item] = 1;
        }
    }
    
    return sieve;
}