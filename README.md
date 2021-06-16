# integrate Alm~F(phi).|Ylm|^2
Small program for integrating Alm in C++ using Gaussian Legendre Quadrature


This code is for calculating Alm as defined in Gizon 2002, AN, 323, 251–253
It allows you to evaluate for any kind of assumed active region function F(phi) the induced perturbation. See specific cases of polar or equatorial active bands in Gizon, 2002.

# How to use
This version run a small test program contained in the main() of activity.cpp.
To run that test, use cmake to compile into a build directory:
       'mkdir build'
       'cd build'
       'cmake ..'
       'make'

This will generate an executable with parameters as per defined into the main() of activity.cpp
Note that this main is just for tests. A proper usage would require to include activity.cpp into a larger projet, after commenting the main().

Othman Benomar
