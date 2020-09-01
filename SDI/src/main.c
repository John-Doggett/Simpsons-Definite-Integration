#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tinyexpr.h"

// arguments: double increment, double lowerbound, double upperbound, string expression
int main(int argc, char *argv[])
{
    if(argc != 5){
        printf("Incorrect arguments! Please use: double increment, double lowerbound, double upperbound, string expression");
        return 0;
    }
    char *ptr = 0;

    double increment = strtod(argv[1], &ptr);

    double lowerBound = strtod(argv[2], &ptr);

    double upperBound = strtod(argv[3], &ptr);

    double range = upperBound - lowerBound;
    double subdivisions = range/increment;
    if(fmod(subdivisions, 1.00) != 0.00){ //increment must evenly divide range
        subdivisions = ceil(subdivisions) / 1.00;
    }
    if(subdivisions < 5.0){ //must be at least 5 subdivisions for simpsons rule
        subdivisions = 5.0;
    }
    if( (int) ceil(subdivisions) % 2 != 1){ //must have odd number of subdivisions for simpsons rule
        subdivisions += 1.0;
    }
    increment = range / subdivisions;

    double x = lowerBound;
    te_variable vars[] = {{"x", &x}};
    te_expr *expression = te_compile(argv[4], vars, 1, 0);
    double output = 0;
    for(int a = 1; a <=  (int) subdivisions; a++ ){

        if(a == 1 || a == (int) subdivisions){
            output+=te_eval(expression);
        }
        else if(a % 2 == 0){
            output+=4*te_eval(expression);
        }
        else{
            output+=2*te_eval(expression);
        }
        x+= increment;
    }
    output = output * (increment / 3);
    
   
    printf("%f", output);
    
    free(expression);
    free(argv);
    return 0;
}
