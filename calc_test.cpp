/**
 * Testing the RPN calculator
 */

#include <cassert>
#include <string>
#include <iostream>
#include "calc.h"

using namespace std;

bool closeEnough(double a, double b, double epsilon = 0.000001) {
  if (a > b)
    return (a - b) < epsilon;
  else
    return (b - a) < epsilon;
}

void test1() {
  cout << "Start test1" << endl;
  Calc cc;
  cc.enter(2.5);
  cc.enter(3.5);
  string result = "[3.5 2.5]";
  assert(cc.getStack() == result);
  cc.enter(20);
  result = "[20 3.5 2.5]";
  assert(cc.getStack() == result);
  double t1 = cc.getDisplay();
  assert(closeEnough(t1, 20));
  cc.enter("+");
  t1 = cc.getDisplay();
  assert(closeEnough(t1, 23.5));
  cc.enter("*");
  t1 = cc.getDisplay();
  assert(closeEnough(t1, 58.75));
  cc.reset();
  result = "[]";
  assert(cc.getStack() == result);
  string inputs[]{"15", "7", "1", "1", "+", "-",
                  "/", "3", "*", "2", "1", "1", "+", "+", "-"};
  int len = 15;
  cc.enter(inputs, len);
  t1 = cc.getDisplay();
  assert(closeEnough(t1, 5));
  cout << "End test1" << endl;
}

void testAll() {
  test1();
}
