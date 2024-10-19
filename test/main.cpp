#include <iostream>
#include "core.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{

    point2d<int> point;
    point.x = 10;
    point.y = 15;

    vector2d<int> test1;
    printVector2d(test1, std::cout);

    vector2d<int> test2(30, 4);
    printVector2d(test2, std::cout);

    vector2d<int> test3(point);
    printVector2d(test3, std::cout);
    return 0;
}
