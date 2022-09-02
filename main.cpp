#include <iostream>
#include "walker.h"
#include <locale.h>
#include <stdlib.h>
#include <time.h>

using namespace std;



int main()
{
    srand(time(NULL));
    Walker walker(4,4,0,0);
    walker.initField();
    //walker.printField();
    walker.run();

    return 0;
}
