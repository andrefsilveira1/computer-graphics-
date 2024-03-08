#ifndef IMAGE_GEN
#define IMAGE_GEN

#include <iostream>
#include <fstream>

struct Color {
    int r;
    int g;
    int b;
};

void headerWriter(std::ofstream &file, int width, int height);
void pixelWriter(std::ofstream &file, const Color& color);
Color interpolateColor(const Color& A, const Color& B, const Color& C, const Color& D, double u, double v);

#endif // IMAGE_GEN
