#include "BigNumCalc.h"
#include <math.h>
#include <string>
using namespace std;

BigNumCalc::BigNumCalc() {}
list<int> BigNumCalc::buildBigNum(string numString){
  list<int> num;
  int length = numString.length();
  for (int i = 0; i < length; i++) {
    int digit = numString[i] - '0';
    num.push_back(digit);
  }
  return num;
}
list<int> BigNumCalc::add(list<int> num1, list<int> num2){
  unsigned long long int num = toInt(num1) + toInt(num2);
  return buildBigNum(to_string(num));
}
list<int> BigNumCalc::sub(list<int> num1, list<int> num2){
  unsigned long long int num = toInt(num1) - toInt(num2);
  return buildBigNum(to_string(num));
}
list<int> BigNumCalc::mul(list<int> num1, list<int> num2){
  unsigned long long int num = toInt(num1) * toInt(num2);
  return buildBigNum(to_string(num));
}

unsigned long long int BigNumCalc::toInt(list<int> numList) {
  unsigned long long int result = 0;
  int digits = numList.size();
  for (int i : numList) {
    result += pow (10, (digits-1)) * i;
    digits--;
  }
  return result;
}