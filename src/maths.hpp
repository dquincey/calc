#pragma once
#include <string>
namespace maths {

bool is_between(int low, int high, int val);

int move_towards(int a, int b);
std::string format_double(double num);
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
} // namespace maths
