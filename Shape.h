#ifndef SHAPE_H
#define SHAPE_H
#include <string>

class Coordinate
{
    unsigned int x, y;
    public:
};

class Shape
{
    
    std::string Name;
    int angleCount;
    Coordinate coordinate;
    public:
    Shape();
    ~Shape();
};

/*
Type "NULL" if value is unknown. 
3 unknown values instantly error 
Triangle ./main [Theta Angle] [adj] [opp] [hyp] 
Circle ./main [Circumference] [Radius] [Area] 
Polygon ./main [csv file] contains [interrior angle 1] [Side length 1] [interior angle n] [side length n] 
polygon may be changed 
    
Triangle    
./main [Theta Angle] [adj] [opp] [hyp] 
Circle      
./main [Circumference] [Radius] [Area]
Polygon     
./main [Side count] [txt file] []

*/
class Circle : public Shape
{

    float circumference, radius, perimeter;

public:
    int getCircumference();
    int getradius();
    int getPerimeter();
};

class Triangle : public Shape
{
    
    unsigned int theta, adjacent, opposite, hypotenuse;

    public:
    Triangle();
    ~Triangle();
};

class Polygon : public Shape
{
    public:
    Polygon();
    ~Polygon();
    //angle count and array of points to be connected
    Polygon(int angleCount, Coordinate*[]);
};

#endif
