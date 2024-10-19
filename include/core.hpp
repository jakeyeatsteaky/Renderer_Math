#ifndef CORE_HPP
#define CORE_HPP

#include <ostream>

template <typename T>
struct point2d
{
    T x;
    T y;
};

template <typename T>
class vector2d
{
public:
    inline vector2d() : x(0), y(0) {}

    vector2d(T x, T y) : x(x), y(y) {}
    vector2d(point2d<T> point) : x(point.x), y(point.y) {}

    template<typename D>
    friend void printVector2d(const vector2d<D>& vec, std::ostream& out);

private:
   T x;
   T y; 
};

template <typename T>
void printVector2d(const vector2d<T>& vec, std::ostream& out)
{
    out << "(" << vec.x << ", " << vec.y << ")" << std::endl;
}

#endif // end core_hpp
