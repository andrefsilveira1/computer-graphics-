#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
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
    // P(t) = (1 - t) * A + t * B
    
    vector<double> I_axb = {(1 - u) * A[0] + u * B[0],
                            (1 - u) * A[1] + u * B[1],
                            (1 - u) * A[2] + u * B[2]};

    vector<double> I_cxd = {(1 - u) * C[0] + u * D[0],
                            (1 - u) * C[1] + u * D[1],
                            (1 - u) * C[2] + u * D[2]};

    vector<double> P = {(1 - v) * I_axb[0] + v * I_cxd[0],
                        (1 - v) * I_axb[1] + v * I_cxd[1],
                        (1 - v) * I_axb[2] + v * I_cxd[2]};

    return P;
}

int main() {
    const int width = 400;
    const int height = 200;
    vector<double> A = {255.0, 182.0, 193.0};  // Pink 
    vector<double> B = {128.0, 0.0, 128.0};    // Purple
    vector<double> C = {165.0, 42.0, 42.0};    // Brown 
    vector<double> D = {0.0, 0.0, 0.0};        // Black

    ofstream ppmFile("image.ppm");

    if (!ppmFile.is_open()) {
        cerr << "Error: Unable to open the file." << endl; // If the is no file, it will create it
        return 1;
    }

    headerWriter(ppmFile, width, height);
    // User this for generate ppm as default part 1

    // for (int y = height; y > 0; y--) {
    //     for (int x = 0; x < width; x++) {

    //         int red = x * 255 / width;
    //         int green = y * 255 / height;
    //         int blue = 51; 

    //         pixelWriter(ppmFile, red, green, blue);
    //     }
    // }

    // Generation with bilinear interpolation
    for (int y = height; y > 0; y--) {
        for (int x = 0; x < width; x++) {
            double u = static_cast<double>(x) / (width - 1);
            double v = static_cast<double>(y - 1) / (height - 1); 

            vector<double> color = interpolateColor(A, B, C, D, u, v);

            pixelWriter(ppmFile, static_cast<int>(color[0]), static_cast<int>(color[1]), static_cast<int>(color[2]));
        }
    }

    ppmFile.close();

    cout << "Image generated" << endl;

    return 0;
}
