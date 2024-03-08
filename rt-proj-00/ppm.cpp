#include <iostream>
#include <fstream>
#include "include/ppm.hpp"

using namespace std;

void headerWriter(ofstream &file, int width, int height) {
    file << "P3\n";         // P3 indicates plain text format
    file << width << " " << height << "\n";
    file << "255\n";        // Maximum color value
}

// Function to write pixel values to the PPM file
void pixelWriter(ofstream &file, int red, int green, int blue) {
    file << red << " " << green << " " << blue << "\n";
}

int main() {
    const int width = 400;
    const int height = 200;

    ofstream ppmFile("image.ppm");

    if (!ppmFile.is_open()) {
        cerr << "Error: Unable to open the file." << endl;
        return 1;
    }

    headerWriter(ppmFile, width, height);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // Gradient based on pixel coordinates
            int red = x * 255 / width;
            int green = y * 255 / height;
            int blue = 51;  // Constant blue value

            pixelWriter(ppmFile, red, green, blue);
        }
    }

    ppmFile.close();

    cout << "PPM image generated successfully." << endl;

    return 0;
}
