#include "objectcoord.h"

int ObjectCoord::getX() const
{
    return x;
}

void ObjectCoord::setX(int newX)
{
    x = newX;
}

int ObjectCoord::getY() const
{
    return y;
}

void ObjectCoord::setY(int newY)
{
    y = newY;
}

bool ObjectCoord::getCheck() const
{
    return check;
}

void ObjectCoord::setCheck(bool newCheck)
{
    check = newCheck;
}

void ObjectCoord::print(std::string s)
{
    std::cout << s << " y: " << y << " x: " << x << std::endl;
}

ObjectCoord ObjectCoord::operator=(ObjectCoord &ob)
{
    x = ob.getX();
    y = ob.getY();

    return *this;
}

ObjectCoord::ObjectCoord()
{

}

bool operator== (const ObjectCoord &ob1, const ObjectCoord &ob2)
{
    return (ob1.getX() == ob2.getX() &&
            ob1.getY() == ob2.getY());
}

bool operator!= (const ObjectCoord &ob1, const ObjectCoord &ob2)
{
    return !(ob1 == ob2);
}
