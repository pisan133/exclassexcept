//
// Created by Yusuf Pisan on 2/14/19.
//

#include <iostream>
#include <sstream>
#include <stdexcept>
#include "calc.h"

using namespace std;

// Can also define trivial constructors using "default"
// Calc::Calc() = default
Calc::Calc() {
  // nothing to do
}

void Calc::enter(double number) {
  mystack.push(number);
}

void Calc::enter(const string &op) {
  if (mystack.size() < 2)
    throw out_of_range("Not enough items on stack");
  double t1 = mystack.top();
  mystack.pop();
  double t2 = mystack.top();
  mystack.pop();
  if (op == "+")
    mystack.push(t2 + t1);
  else if (op == "-")
    mystack.push(t2 - t1);
  else if (op == "/")
    mystack.push(t2 / t1);
  else if (op == "*")
    mystack.push(t2 * t1);
  else
    throw invalid_argument("Unknown symbol");
}

void Calc::enter(string op[], int n) {
  for (int i = 0; i < n; ++i) {
    try {
      double number = stod(op[i]);
      enter(number);
    } catch (exception &exc) {
      enter(op[i]);
    }
  }
}

void Calc::reset() {
  while (!mystack.empty())
    mystack.pop();
}

double Calc::getDisplay() const {
  if (mystack.empty()) {
    throw out_of_range("Cannot display top element in empty stack");
  }
  return mystack.top();
}

string Calc::getStack() const {
  stringstream out;
  stack<double> other;
  other = mystack;
  out << "[";
  if (!other.empty()) {
    out << other.top();
    other.pop();
  }
  while (!other.empty()) {
    out << " " << other.top();
    other.pop();
  }
  out << "]";
  return out.str();
}
