#include <iostream>
#include <iomanip>
#include "bilinear_interpol.h"
//#include "Alm_interpol.h"

/*
void show_mat(GridData grid){
        int l=(grid.z.size()-1)/2;
        // Show the matrix for debug
        std::cout << std::setw(22);
        for (int i=0; i<grid.x.size(); i++){
            std::cout << grid.x[i] << std::setw(14);
        }
        std::cout << std::endl << std::setw(21) << "i=  ";
        for (int i=0; i<grid.x.size(); i++){
            std::cout << i << std::setw(14);
        }
        std::cout << std::endl;
        for (int j=0; j<grid.y.size(); j++){
            for (int i=0; i<grid.x.size(); i++){
                if (i==0){
                    std::cout << grid.y[j] << "  j=" << j << "  ";
                }
                std::cout << grid.z[j][i] << std::setw(14);
            }
            std::cout << std::endl;
        }
}
*/

// Use interpolation over precomputed grids to compute Alm
long double Alm_interp(const int l, const int m, const long double theta0, const long double delta, const std::string ftype, const std::string grid_dir){
	double r;
	try{
		// The expected file name is following the one at creation by GridMaker: 
		// (l=1, m=-1) --> A10.gz, (l=1, m=0) --> A11.gz etc...
		// The root directory of the grid is expected to contain subdirectories 
		// of the same name as the allowed ftype
		std::string file_gz = grid_dir + "/" + ftype + "/A" + std::to_string(l) + std::to_string(m+l) + ".gz";
		std::cout << "       File : " << file_gz << std::endl;
        // Load the correct grid
		GridData data = loadGridData(file_gz);
		//show_mat(data);
		// Interpolation
		double c = interpolate(data, theta0, delta);
		//std::cout << "Interpolated value at (" << theta0 << ", " << delta << ") = " << c << '\n';
		return c;
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << "\n";
		return -8888;
	}
	catch (...) {
		cerr << "Exception of unknown type!\n";
		return -9999;
	}
	return -9999;
}

/*
// A quick test
int main(int argc, char** argv){
    int l=3;
    int m=-1;
    double theta0=0.999816;
    double delta=0.233657;
    std::string ftype="gate";
    std::string grid_dir="/Users/obenomar/tmp/Alm/data/Alm_grids_CPP/2deg_grids/";
    std::cout << Alm_interp(l, m, theta0, delta, ftype, grid_dir) << std::endl;
}
*/