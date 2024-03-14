struct Pixel {
    std::tuple<int, int, int> color; // RGB color tuple
    float depth; // Depth of the pixel
};


using Coordinate = std::pair<int, int>;
using PixelMatrix = std::map<Coordinate, Pixel>;