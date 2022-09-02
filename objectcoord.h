#ifndef OBJECTCOORD_H
#define OBJECTCOORD_H
#include <vector>
#include <iostream>
#include <string>

class ObjectCoord
{
    int x = 0;
    int y = 0;
    bool check = false;


public:
    ObjectCoord();

    int getX() const;
    void setX(int newX);
    int getY() const;
    void setY(int newY);
    bool getCheck() const;
    void setCheck(bool newCheck);
    void print(std::string s = "");

    ObjectCoord operator= (ObjectCoord &ob);

    friend bool operator== (const ObjectCoord &ob1, const ObjectCoord &ob2);
    friend bool operator!= (const ObjectCoord &ob1, const ObjectCoord &ob2);
};

#endif // OBJECTCOORD_H
