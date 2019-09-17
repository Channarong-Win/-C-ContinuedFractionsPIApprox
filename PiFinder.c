/*
*
*           PI Value Estimator Program (C Language)
*           Created by Channarong Thititanapak
*           Faculty of Engineering Mahidol University
*
*           References:
*           Generalized_continued_fraction        : https://en.wikipedia.org/wiki/Generalized_continued_fraction
*           PI Approx by using continuedFractions : https://en.wikipedia.org/wiki/Approximations_of_%CF%80
*
*/

#include <stdio.h>
#include <stdlib.h>

#define AM 1
#define BM 0
#define B0 1
#define b0 1

//
//
// From Ref. "Generalized_continued_fraction" we init a func. named "continuedFractionPI" follow by the "PI Approx by using continuedFractions" ref.
//
//          This Function compute a fraction of any numerator (A(n)) and Denominator (B(n)) The numerator (A(n)) and Denominator (B(n))
// are recursive relation that follow by the "PI Approx by using continuedFractions" ref. Have it's base case is
// (A(-1) = 1, A(0) = b0, B(0) = 1, B(-1) = 0). Both functions take n as a parameter to determine how many times it's need
// to do a continued fractions. This operation will continued recursively until n reach 1, at this state both func. will call A(0) and A(-1), B(0) and B(-1)
// then it will reach it's base case and stop the recursive.
//

double numerator(int n){
    //BASE CASE
    if(n == -1){
        return AM;
    }
    else if(n == 0){
        return b0;
    }
    //RECURSIVE CASE
    else{
        return ((((2*n) + 1) * numerator(n - 1)) + ((n * n) * numerator(n - 2)));
    }
}

double denominator(int n){
    //BASE CASE
    if(n == -1){
        return BM;
    }
    else if(n == 0){
        return B0;
    }
    //RECURSIVE CASE
    else{
        return ((((2*n) + 1) * denominator(n - 1)) + ((n * n) * denominator(n - 2)));
    }
}


double continuedFractionPI(int n){
    return 4/(numerator(n)/denominator(n));
}


int main(){

    double PI;
    int n;

    printf("Input Limit n: ");
    scanf("%d", &n);
    // we check is the input is out of bound or not
    if( n < 1 ){
        printf("Can not estimated value of PI.");
    }
    else{
        PI = continuedFractionPI(n);
        printf("Estimated value of PI is %.10f", PI);
    }

}
