#ifndef PPM_GEN
#define PPM_GEN

#include <iostream>
#include <fstream>

using namespace std;

void headerWriter(ofstream &file, int width, int height);
void pixelWriter(ofstream &file, int red, int green, int blue);

#endif // PPM_GEN
