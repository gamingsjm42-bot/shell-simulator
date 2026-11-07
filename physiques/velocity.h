#include <cmath>
#include <iostream>
//set variables
const float g= 9.81 ,pi =3.14;
/// set Vx Vy 
float Vx(float t,double V0,float angel){return V0 * std::cos(angel) ;}
float Vy(float t ,float V0,float angel){return (-g*t)+(V0*std::sin(angel));}