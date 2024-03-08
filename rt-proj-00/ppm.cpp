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

Color interpolateColor(const Color& A, const Color& B, const Color& C, const Color& D, double u, double v) {
    // Interpolate between A and B with parameter u to get Xb
    Color Xb = { round((1.0 - u) * A.red + u * B.red),
                 round((1.0 - u) * A.green + u * B.green),
                 round((1.0 - u) * A.blue + u * B.blue) };

    // Interpolate between C and D with parameter u to get Xt
    Color Xt = { round((1.0 - u) * C.red + u * D.red),
                 round((1.0 - u) * C.green + u * D.green),
                 round((1.0 - u) * C.blue + u * D.blue) };

    // Interpolate between Xb and Xt with parameter v to get the final color I
    Color I = { round((1.0 - v) * Xb.red + v * Xt.red),
                round((1.0 - v) * Xb.green + v * Xt.green),
                round((1.0 - v) * Xb.blue + v * Xt.blue) };

    return I;
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
