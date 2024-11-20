// mymath.cpp
#include <iostream>
#include "mymath.h"

using namespace N;



void Mymath::do_something(){
  std::cout << "Testing\n"; 
}
int Mymath::factorial(int num){
  /*
   * if num = 0, return 1
   * if num > 0, return num*factorial(num-1)
   */

  if (num < 0){
    throw std::invalid_argument("Cannot get a factorial of a negative number");
  }
  if (num == 0){
    return 1;
  }
  else{
    return num*factorial(num-1);
  }
}

double Mymath::power(double num, double exponent){
  /*
   * Uses the repeated squaring to get the power working 
   * if odd exponent then exp = (exp - 1)/2
   * if even then exp = exp / 2
   *
   * Another way to get power is by using log rules
   * Use this for decimal exponents
   * a^x == b <-> xln(a) == ln(b) <-> e^(xln(a)) == b
   *
   * Then with i = 0 to inf use e^n = (n^i_1)/i_1! + (n^i_2)/i_2! + (n^i_3)/i_3! + ...
   */
  int exp;
  if ( (int) exponent == exponent ){
    exp = (int) exponent;
  }
  else {
    throw std::invalid_argument("Floating point exponents are not allowed yet");
  }
  if (exponent < 0){
    return power(1/num, -exponent);
  } 
  else if (exponent == 0) {
    return 1;
  }
  else if (exp % 2 == 0) {
    return power(num * num, exponent / 2); 
  }
  else if (exp % 2 == 1) {
    return num * power(num * num, (exponent - 1) / 2);
  }
  return 0;
}

double Mymath::natlog(double num){
  /*
   * for x > 0
   * inner_num = ( ( x - 1 ) / ( x + 1 ) )
   * z = i * 2 - 1
   * ln x = 2 * ( ( (1/z_1) * (inner_num) ^z_1 ) + ( (1/z_2) * (inner_num) ^z_2 ) + ... )
   * run until i = 20
   * */
  
  if (num <= 0) {
    throw std::invalid_argument("Number <= 0");
  }

  double inner_num = (num-1)/(num+1);
  double z;
  double result = 0;
  for ( int i = 1; i <= 20; i++ ) {
    z = (i*2)-1;
    result += (1/z) * power(inner_num, z); 
  }
  return result*2;
}

double Mymath::logx(double num, double subscript){

  /*
   * for x > 0
   * log10(x) = ln(x)/ln(10) */

  if (num <= 0 || subscript <= 0) {
    throw std::invalid_argument("input number <= 0");
  }

  return natlog(num)/natlog(subscript);

}

double Mymath::gradient_est(double guess, int exponent){
  return exponent * power(guess, exponent-1);
}

double Mymath::nroot(double num, double exponent) {

  /* 
   * Use a nearby guess g = (num/exponent)
   * put g to the power of the exponent and subtract it by the num
   * then estimate the gradient with exponent * g^(exponent-1)
   * then subract the gradient from g and use that as the new guess
   *
   * Finds to the nearest 10000ths place
   */

  double guess, guess_power, difference, gradient, correction;
  
  guess = num / exponent;
  for (int i = 0; i < 25; i++){
    guess_power = power(guess, exponent);
    if (guess_power == num){
      break;
    }
    difference = guess_power - num;
    gradient = gradient_est(guess, exponent);
    correction = difference / gradient;
    guess = guess - correction; 
  }
  return guess;
}
