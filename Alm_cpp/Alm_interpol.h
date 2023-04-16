#pragma once 
#include <iostream>
#include <iomanip>
#include "bilinear_interpol.h"

// Use interplation over precomputed grids to compute Alm
long double Alm_interp(const int l, const int m, const long double theta0, const long double delta, const std::string ftype, const std::string grid_dir);