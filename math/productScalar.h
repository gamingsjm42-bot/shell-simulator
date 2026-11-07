//includes
#include "vector.h"
#include <cmath>
///
template <typename num= float>
num productScalar(Vector<num> v1,Vector<num> v2)
{
    return v1.x*v2.y + v2.x*v1.y;
}
//
template<typename num = float>
num abs(Vector<num> v){return std::sqrt(v.x*v.x + v.y*v.y);}
//
template< typename num=float>
num Angel(Vector<num> v1,Vector<num> v2)
{
    return std::asin(productScalar<num>(v1,v2)/abs<num>(v1)*abs<num>(v2));
}
//
template <typename num = float>
num Angel(Point<num> P1 ,Point<num> P2 , Point<num> P3)
{
    return Angel<num>(Vector<num>(P1,P2),Vector<num>(P1,P3));
}