# Simpsons-Definite-Integration
A simple C script to do definite integration using <a href="https://en.wikipedia.org/wiki/Simpson%27s_ruler">Simpson's Rule</a>

Uses <a href="https://github.com/codeplea/tinyexpr">tinyexpr</a>, a library that converts strings into math expressions.

Run the script with following arguments (increment, lowerBound, upperBound, expression)
<br>Increment: a decimal number which represents the size of each simpsons rule increment. 
<br>Lower Bound: a decimal number which represents the lower bound of the definite integral.
<br>Upper Bound: a decimal number which represents the upper bound of the definite integral.
<br>Expression: A string which represents the mathmatical formula, must use only a X as a variable. Do not include spaces in this expression, you may use stand math.h library functions like sqrt(). 

<br>Will print out a decimal approximation of the integral.

Example arguments (.001, 0, 5, x^2)
Output: 41.641677

This script will check to make sure you enter only 4 arguments, if you don't it will output:
<br>Incorrect arguments! Please use: double increment, double lowerbound, double upperbound, string expression

This script will not check to make sure the arguments are correct data types.
