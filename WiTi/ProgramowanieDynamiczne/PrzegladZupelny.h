#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
#include <ctime>

#define N  20


void swap(int& a, int& b);

int Kara(int* P, int* W, int* D, int T[]);

void out(int T[], int* min, int* P, int* W, int* D, int rozw[]);

void permutacje(int T[N], int ix, int* min, int* P, int* W, int* D, int rozw[]); // ix = 0..N-1

void SolvePZ(int* pi, int* wi, int* di);