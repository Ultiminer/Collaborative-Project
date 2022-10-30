#ifndef GEOMETRY_H_
#define GEOMETRY_H_
#include "primitives.h"
#include "gcem.hpp"
constexpr fvec3d crossprod(const fvec3d& a, const fvec3d& b)
{
    return {a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.z};
}
constexpr float dotprod(const fvec3d& a, const fvec3d& b)
{
    return a.x*b.x+a.y*b.y+a.z*b.z;
}
constexpr fvec3d operator+(const fvec3d& a, const fvec3d& b)
{
    return {a.x+b.x,a.y+b.y,a.z+b.z};
}
constexpr fvec3d operator-(const fvec3d& a, const fvec3d& b)
{
    return {a.x-b.x,a.y-b.y,a.z-b.z};
}
constexpr fvec3d operator*(const fvec3d& a, const float b)
{
    return {a.x*b,a.y*b,a.z*b};
}
constexpr fvec3d operator/(const fvec3d& a, const float b)
{
    return {a.x/b,a.y/b,a.z/b};
}
constexpr float squaredist(const float x)
{
    return x*x;
}
constexpr float squaredist(const float x, const float y)
{
    const float d=x-y;
    return d*d;
}
constexpr float squaredist(const fvec3d& x)
{
    return dotprod(x,x);
}
constexpr float squaredist(const fvec3d& x,const fvec3d& y)
{
    const fvec3d& d=x-y;
    return dotprod(d,d);
}
constexpr float length(const fvec3d& x)
{
    return gcem::sqrt(squaredist(x));
}
constexpr fvec3d normalize(const fvec3d& x)
{
    return x*gcem::inv_sqrt(squaredist(x));
}


#endif