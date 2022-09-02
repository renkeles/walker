#ifndef WALKER_H
#define WALKER_H

#include <vector>
#include "objectcoord.h"



class Walker
{

    ObjectCoord max;
    ObjectCoord start;
    ObjectCoord current;
    ObjectCoord next;
    ObjectCoord left;
    ObjectCoord right;
    ObjectCoord up;
    ObjectCoord down;

    int count = 0;
    bool installStartPoint();
    bool checkAndStep();
public:  
    Walker(int, int, int, int);
    std::vector<ObjectCoord> temp;
    std::vector<std::vector<int>> field;

    bool initField();
    bool printField();
    void run();
    int randGen(int);



};

#endif // WALKER_H
