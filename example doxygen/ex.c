/**
* \file example-doxygen.h
* \brief Math functions used by the program
*/

#ifndef __MATHUTILS_H_
#define __MATHUTILS_H_

/**
* \struct pair
* \brief structure which contains a pair of integers
*/
  typedef struct{
    int first; /*!< First member of the pair. */
    int second; /*!< Second member of the pair. */
  }

/**
* \fn int isPrime(unsigned)
* \Check if a number is a prime number
* \param a        Number to check
* \return TRUE if prime, else FALSE
*/

  int isPrime( unsigned a);

/**
* \fn int GCD(int, int)
* \brief Compute the GCD of two numbers
*
* \param a First number.
* \param b Second number.
* \ return 
*/
