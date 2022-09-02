#include "walker.h"
#include <algorithm>
#include <iostream>
#include <iomanip>


Walker::Walker(int newRow, int newCol, int newY, int newX)
{   
    max.setY(newRow);
    max.setX(newCol);
    start.setY(newY);
    start.setX(newX);

}

bool Walker::installStartPoint()
{
    if((start.getY() >= 0 && start.getY() < max.getY()) && (start.getX() >= 0 && start.getX() < max.getX()))
    {
        field[start.getY()][start.getX()] = ++count;
        current.setY(start.getY());
        current.setX(start.getX());
        return true;
    }else
    {
        std::cout << "Error: new coord = 0;0" << std::endl;
        field[0][0] = ++count;
        current.setY(0);
        current.setX(0);
        return false;
    }
    return false;
}

bool Walker::checkAndStep()
{
    //check left and right cells
    if(current.getY() >=0 && current.getY() < max.getY())
    {
        //check left cell
        if(current.getX() - 1 >= 0 && current.getX() - 1 < max.getX())
        {
            if(field[current.getY()][current.getX() - 1] == 0)
            {
                left.setY(current.getY());
                left.setX(current.getX() - 1);
                temp.push_back(left);
            }
        }

        //check right cell
        if(current.getX() + 1 >= 0 && current.getX() + 1 < max.getX())
        {
            if(field[current.getY()][current.getX() + 1] == 0)
            {
                right.setY(current.getY());
                right.setX(current.getX() + 1);
                temp.push_back(right);
            }
        }
    }

    //chect up and down cell
    if(current.getX() >= 0 && current.getX() < max.getX())
    {
        //check up cell
        if(current.getY() - 1 >= 0 && current.getY() - 1 < max.getY())
        {
            if(field[current.getY() - 1][current.getX()] == 0)
            {
                up.setY(current.getY() - 1);
                up.setX(current.getY());
                temp.push_back(up);
            }
        }

        //check down cell
        if(current.getY() + 1 >= 0 && current.getY() + 1 < max.getY())
        {
            if(field[current.getY() + 1][current.getX()] == 0)
            {
                down.setY(current.getY() + 1);
                down.setX(current.getX());
                temp.push_back(down);
            }
        }
    }

    next = temp[randGen(temp.size())];

    field[next.getY()][next.getX()] = ++count;

    current = next;
    next.print("Next");
    printField();
    temp.clear();

    return false;
}

bool Walker::initField()
{
    for(int i = 0; i < max.getY(); ++i)
    {
        std::vector<int> temp;
        for(int j = 0; j < max.getX(); ++j)
        {
            temp.push_back(0);
        }
        field.push_back(temp);
    }

    Walker::installStartPoint();
    return false;
}

bool Walker::printField()
{

    std::for_each(field.begin(), field.end(), [](std::vector<int>& ivec)
        {
            std::for_each(ivec.begin(), ivec.end(), [](int i)
            {
                std::cout << std::left << std::setw(5) << i;
            });
            std::cout << std::endl;
        });
    std::cout << std::endl;
    return false;
}

void Walker::run()
{
        for(int i = 0; i < 4; ++i)
        {
            checkAndStep();
        }


}

int Walker::randGen(int max)
{
    int randgen = rand() % max;
    std::cout << "max = " << max << " ";
    std::cout << "randgen = "<< randgen << " ";
    std::cout << std::endl;
    return randgen;
}


