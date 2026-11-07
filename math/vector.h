/// @brief that class on P(x,y) on geomwtry
/// @tparam num that number of point
template<typename num = float>
struct Point
{
    ///that x,y
    num x,y ;
    Point(num x, num y){this->x =x ; this->y = y;}
};

//
template <typename num = float> 
struct Vector
{
    num x,y;
    //that like vector M0M1->
    Vector(num x, num y){this->x =x; this->y = y;}
    Vector(Point<num> M0,Point<num> M1):Vector<num>(M1.x-M0.x,M1.y-M0.y){}
    //
    Vector<num> operator+(Vector<num> v){return Vector<num>(x+v.x,y+v.y);}
    Vector<num> operator-(){return Vector<num>(-x,-y);}
    Vector<num> operator-(Vector<num> v){return operator+(-v);}
    //
    
};

