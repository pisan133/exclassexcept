/**
 * Based on http://www.alcula.com/calculators/rpn/
 *
 */

#ifndef HPCALC_CALC_H
#define HPCALC_CALC_H

#include <stack>

using namespace std;

class Calc {

 public:
  Calc();
  void enter(double number);
  void enter(const string &op);
  void enter(string arr[], int n);
  void reset();
  double getDisplay() const;
  string getStack() const;
 private:
  stack<double> mystack;
};

#endif // HPCALC_CALC_H
