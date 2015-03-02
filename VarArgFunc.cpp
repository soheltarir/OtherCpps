/**
 * @file VarArgFunc.cpp
 * @brief Functions with Variable Argument Lists:
 *         To use a function with variable number of arguments, or more precisely, a function without a set number of arguments, you would use the cstdarg header file. There are four parts needed: va_list, which stores the list of arguments, va_start, which initializes the list, va_arg, which returns the next argument in the list, and va_end, which cleans up the variable argument list. Whenever a function is declared to have an indeterminate number of arguments, in place of the last argument you should place an ellipsis (which looks like '...'), so, int a_function ( int x, ... ); would tell the compiler the function should accept however many arguments that the programmer uses, as long as it is equal to at least one, the one being the first, x. 
 * @author Sohel Tarir
 * @version 1.0
 * @date 2014-09-18
 */
#include <cstdarg>
#include <iostream>

using namespace std;

// this function will take the number of values to average
// followed by all of the numbers to average
double average ( int num, ... )
{
  va_list arguments;                     // A place to store the list of arguments
  double sum = 0;

  va_start ( arguments, num );           // Initializing arguments to store all values after num
  for ( int x = 0; x < num; x++ )        // Loop until all numbers are added
    sum += va_arg ( arguments, double ); // Adds the next value in argument list to sum.
  va_end ( arguments );                  // Cleans up the list

  return sum / num;                      // Returns the average
}
int main()
{
    // this computes the average of 13.2, 22.3 and 4.5 (3 indicates the number of values to average)
  cout<< average ( 3, 12.2, 22.3, 4.5 ) <<endl;
    // here it computes the average of the 5 values 3.3, 2.2, 1.1, 5.5 and 3.3
  cout<< average ( 5, 3.3, 2.2, 1.1, 5.5, 3.3 ) <<endl;
}
