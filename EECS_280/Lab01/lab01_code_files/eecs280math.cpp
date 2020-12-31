#include "eecs280math.h"

double add(double x, double y) {
  return x + y;
}

double mult(double x, double y) {
  return x * y;
}

double power(double base, int exp) {
  double result = 1;
  for(int i = 0; i < exp; ++i) {
    result *= base;
  }
  return result;
}
