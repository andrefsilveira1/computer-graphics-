#include <iostream>
#include <fstream>
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
