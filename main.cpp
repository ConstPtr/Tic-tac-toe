#include <iostream>
#include "game.h"

int main()
{
    game g1;
    int status = 0;
    g1.chooseSide();
    g1.show();
    if(g1.GetPlayerSide() == 'o')
    {
        status = 1;
    }
    
    while(g1.check() != 'x' && g1.check() != 'o' && g1.check() != 'd')
    {
        if(status == 0)
        {
            g1.makeMove();
            status = 1;
        }
        else if(status == 1)
        {
            g1.AIMove();
            status = 0;
        }
        g1.show();
    }
    g1.show();
    g1.message();

    return EXIT_SUCCESS;
}