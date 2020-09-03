#include <iostream>
#include "game.h"

game::game()
{
    for(int i = 0; i < size; i++)
    {
        field[i] = space;
    }
}

void game::chooseSide()
{
    std::cout << "Choose side \'x\' or \'o\' : " << std::endl;
    while(player != 'x' && player != 'o')
    {
        std::cin >> player;
        if(player != 'x' || player != 'o')
        {
            std::cout << "Enter correct symbol \'x\' or \'o\' !" << std::endl;
        }

        if(player == 'x')
        {
            AI = 'o';
        }
        else if(player == 'o')
        {
            AI = 'x';
        }
    }
}

void game::makeMove()
{
    int position = 0;
    std::cout << "Enter position on the desk(1 - 9): ";
    while(std::cin >> position)
    {
        if(position > 0 && position <= 9 && field[position - 1] == space)
        {
            field[position - 1] = player;
            break;
        }
        else
        {
            std::cout << "Wrong position!" << std::endl;
        }
    }
}

char game::check()
{
    char draw = 'd';
    int count = 0;

    for(int i = 0, j = 0; i < comboNum; i++)
    {
        if(field[combinations[i][j]] == player && field[combinations[i][j + 1]] == player && field[combinations[i][j + 2]] == player)
        {
            winner = player;
        }
        else if(field[combinations[i][j]] == AI && field[combinations[i][j + 1]] == AI && field[combinations[i][j + 2]] == AI)
        {
            winner = AI;
        }
    }

    for(int i = 0; i < size; i++)
    {
        if(field[i] != space)
        {
            count++;
        }
    }
    if(winner != player && winner != AI && count == 9)
    {
        winner = draw;
    }
    return winner;
}

void game::AIMove()
{
    for(int i = 0, j = 0; i < comboNum; i++)
    {
        if(field[combinations[i][j]] == AI && field[combinations[i][j + 1]] == AI && field[combinations[i][j + 2]] == space)
        {
            field[combinations[i][j + 2]] = AI; 
            return;
        }
        else if(field[combinations[i][j]] == AI && field[combinations[i][j + 1]] == space && field[combinations[i][j + 2]] == AI )
        {
            field[combinations[i][j + 1]] = AI;
            return;
        }
        else if(field[combinations[i][j]] == space && field[combinations[i][j + 1]] == AI && field[combinations[i][j + 2]] == AI)
        {
            field[combinations[i][j]] = AI;
            return;
        }

        if(field[combinations[i][j]] == player && field[combinations[i][j + 1]] == player && field[combinations[i][j + 2]] == space)
        {
            field[combinations[i][j + 2]] = AI;
            return;
        }
        else if(field[combinations[i][j]] == player && field[combinations[i][j + 1]] == space && field[combinations[i][j + 2]] == player )
        {
            field[combinations[i][j + 1]] = AI;
            return;
        }
        else if(field[combinations[i][j]] == space && field[combinations[i][j + 1]] == player && field[combinations[i][j + 2]] == player)
        {
            field[combinations[i][j]] = AI;
            return;
        }
    }

    if(field[4] == space)
    {
        field[4] = AI;
        return;
    }
    else
    {
        for(int i = 0; i < size; i++)
        {
            if(field[i] == space)
            {
                field[i] = AI;
                return;
            } 
        }
    }
}

void game::message()
{
	    std::cout << "\n        111111111111111111111           " << std::endl;
        std::cout << "      111111             111111         " << std::endl;
        std::cout << "     11111                 111111       " << std::endl;
        std::cout << "    1111                     11111      " << std::endl;
        std::cout << "   1111                       11111     " << std::endl;
        std::cout << "  1111     1111       1111      111     " << std::endl;
        std::cout << "  111     111111     111111     1111    " << std::endl;
        std::cout << " 1111     111111     111111      111    " << std::endl;
        std::cout << " 111       1111       1111       1111   " << std::endl;
        std::cout << " 111                              111   " << std::endl;
    
    if(winner == 'd')
    {
        std::cout << " 111            DRAW              111   " << std::endl;
        std::cout << " 111                              111   " << std::endl;
        std::cout << " 111                              111   " << std::endl;
        std::cout << " 1111      111111111111111       111    " << std::endl;
        std::cout << "  111      111111111111111      1111    " << std::endl;
        std::cout << "  1111                         1111     " << std::endl;
        std::cout << "   1111                       1111      " << std::endl;      
    }
    else if(winner == player)
    {
        std::cout << " 111             WIN              111   " << std::endl;
        std::cout << " 111                              111   " << std::endl;
        std::cout << " 111                              111   " << std::endl;
        std::cout << " 1111    111             111     1111   " << std::endl;
        std::cout << " 1111     11111       11111      1111   " << std::endl;
        std::cout << "  1111       11111111111       1111     " << std::endl;
        std::cout << "   1111         11111         1111      " << std::endl;
        std::cout << "    1111                    11111       " << std::endl;                    
    }
    else if(winner == AI)
    {
        std::cout << " 111             LOSE             111   " << std::endl;
        std::cout << " 111                              111   " << std::endl;
        std::cout << " 111            11111            1111   " << std::endl;
        std::cout << " 1111        11111111111         111    " << std::endl;
        std::cout << "  111      11111     11111      1111    " << std::endl;
        std::cout << "  1111    111           111    1111     " << std::endl;
        std::cout << "   1111   11             11   1111      " << std::endl;
        std::cout << "    1111                    11111       " << std::endl;
    }
        std::cout << "    1111                    11111       " << std::endl;
        std::cout << "     111111111111111111111111111        " << std::endl;
}

void game::show()
{
    system("cls");
    std::cout << field[0] << " | " << field[1] << " | " << field[2] << std::endl;
    std::cout << field[3] << " | " << field[4] << " | " << field[5] << std::endl;
    std::cout << field[6] << " | " << field[7] << " | " << field[8] << std::endl;
}

char game::GetPlayerSide()
{
    return player;
}