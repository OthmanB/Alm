#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Define a struct to hold grid data
struct GridData_Alm {
    int l;
    int Ntheta;
    int Ndelta;
    double resol_theta;
    double resol_delta;
    std::vector<double> theta;
    std::vector<double> delta;
    std::vector<std::vector<std::vector<double>>> Alm_grid;
};

// Define a struct to hold grid data for interpolation
struct GridData {
    std::vector<double> x;
    std::vector<double> y;
    std::vector<std::vector<double>> z;
    int n_rows;
    int n_cols;
};

// Faster retrieval, but fix structure limited to lmax=3
struct GridData_Alm_fast{
    bool error;
    GridData A10; // stores l=1, m=0
    GridData A11; // stores l=1, m=+/-1
    GridData A20; // stores l=2, m=0
    GridData A21; // stores l=2, m=+/-1
    GridData A22; // stores l=2, m=+/-2
    GridData A30; // stores l=3, m=0
    GridData A31; // stores l=3, m=+/-1
    GridData A32; // stores l=3, m=+/-2
    GridData A33; // stores l=3, m=+/-3    
};