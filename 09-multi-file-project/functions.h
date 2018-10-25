#pragma once

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void SortArray(double* arr, const int n);
double MultiplyElements(double* arr, const int n, int abs_max_addr);
int FindAbsoluteMaxAddr(double* arr, const int n);
int CountElements(double* arr, double c, const int n);