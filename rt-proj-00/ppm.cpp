#include <iostream>
#include <fstream>
#include <cmath>
#include "include/ppm.hpp"

using namespace std;

void headerWriter(ofstream &file, int width, int height) {
    file << "P3\n";
    file << width << " " << height << "\n";
    file << "255\n"; 
}

void pixelWriter(ofstream &file, int red, int green, int blue) {
    file << red << " " << green << " " << blue << "\n";
}

vector<double> interpolateColor(const vector<double>& A, const vector<double>& B,const vector<double>& C, const vector<double>& D, double u, double v) {
    // P(t) = (1 - t)*A + t * B
    
    vector<double> I_axb = {(1 - u) * A[0] + u * B[0],
                            (1 - u) * A[1] + u * B[1],
                            (1 - u) * A[2] + u * B[2]};

    vector<double> I_cxd = {(1 - u) * C[0] + u * D[0],
                            (1 - u) * C[1] + u * D[1],
                            (1 - u) * C[2] + u * D[2]};

    vector<double> P = {(1 - v) * I_axb[0] + v * I_cxd[0],
                        (1 - v) * I_axb[1] + v * I_cxd[1],
                        (1 - v) * I_axb[2] + v * I_cxd[2]};

    // for (auto& component : P) {
    //     component = round(component);
    // }

    return P;
}

int main() {
    const int width = 400;
    const int height = 200;

    ofstream ppmFile("image.ppm");

    if (!ppmFile.is_open()) {
        cerr << "Error: Unable to open the file." << endl; // If the is no file, it will create it
        return 1;
    }

    headerWriter(ppmFile, width, height);

    for (int y = height; y > 0; y--) {
        for (int x = 0; x < width; x++) {

            int red = x * 255 / width;
            int green = y * 255 / height;
            int blue = 51; 

            pixelWriter(ppmFile, red, green, blue);
        }
    }

    ppmFile.close();

    cout << "Image generated" << endl;

    return 0;
}
