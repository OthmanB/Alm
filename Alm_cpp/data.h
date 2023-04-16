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