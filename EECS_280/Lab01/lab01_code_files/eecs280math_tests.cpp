#include <cassert>
#include <iostream>
#include <iomanip>
#include "eecs280math.h"

using namespace std;

void add_test_basic() {
  double a = 0.1;
  double b = 0.2;
  double expected_sum = 0.3;
  double actual_sum = add(a, b);

  cout << "expected_sum: " << expected_sum << endl;
  cout << "actual_sum: " << actual_sum << endl;

  assert(expected_sum == actual_sum);
}


int main() {
  add_test_basic();
}
