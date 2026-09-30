#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int playerX = 1;
int playerY = 1;
int gold =  0;
int currentRoom = 1;
char dungeon[6][7] = {
    {'#','#','#','#','#','#','#'},
    {'#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ','T',' ',' ','#'},
    {'#',' ',' ','X',' ',' ','#'},
    {'#',' ','X','E',' ',' ','#'},
    {'#','#','#','#','#','#','#'}
};

char room2[6][7] = {
    {'#','#','#','#','#','#','#'},
    {'#',' ','X',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ','#'},
    {'#','T',' ','X',' ',' ','#'},
    {'#',' ',' ','E',' ',' ','#'},
    {'#','#','#','#','#','#','#'}
};

char room3[6][7] = {
    {'#','#','#','#','#','#','#'},
    {'#','X',' ',' ',' ',' ','#'},
    {'#',' ','T','X',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ','E',' ',' ','#'},
    {'#','#','#','#','#','#','#'}
};


int bossX = 1;
int bossY = 1;
char bossRoom[6][7] = {
    {'#','#','#','#','#','#','#'},
    {'#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ','B',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ','#'},
    {'#','#','#','#','#','#','#'}
};

char getTile(int y, int x)
{
    if (currentRoom == 1)
        return dungeon[y][x];
    else if (currentRoom == 2)
        return room2[y][x];
    else if (currentRoom == 3)
        return room3[y][x];
    else
        return bossRoom[y][x];
}

void showDungeon()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (i == playerY && j == playerX)
            {
                cout << 'P';
            }
            else if (currentRoom==1)
            {
                cout << dungeon[i][j];
            } else if (currentRoom==2)
            {
               cout << room2[i][j];
            } else if (currentRoom==3)
            {
                cout << room3[i][j];
            }  else if (currentRoom==4)
            {
                cout << bossRoom[i][j];
            }
            
            
            
        }

        cout << endl;
    }
}

void movePlayer()
{
    char input = _getch();

    int newX = playerX;
    int newY = playerY;

    if (input == 'w')
    {
        newY--;
    }
    else if (input == 'a')
    {
        newX--;
    }
    else if (input == 's')
    {
        newY++;
    }
    else if (input == 'd')
    {
        newX++;
    }
    else if (input == 'q')
    {
        exit(0);
    }

    
    if (getTile(newY,newX) == '#')
    {
        return;
    }

    playerX = newX;
    playerY = newY;
}

void checkTile()
{
    char tile = getTile(playerY, playerX);

    if (tile == 'E')
    {
        cout << "Kamu berhasil keluar dari room!" << endl;
        system("pause");

        if (currentRoom < 4)
        {
            currentRoom++;
            playerX = 1;
            playerY = 1;
        }
    }

    if (tile == 'X')
    {
        cout << "Musuh ditemukan!" << endl;
        system("pause");

        // Nanti panggil Battle()
    }

    if (tile == 'T')
    {
        cout << "Kamu dapat 50 Gold!" << endl;
        gold += 50;

        // Hapus treasure dari room aktif
        if (currentRoom == 1)
            dungeon[playerY][playerX] = ' ';
        else if (currentRoom == 2)
            room2[playerY][playerX] = ' ';
        else if (currentRoom == 3)
            room3[playerY][playerX] = ' ';

        system("pause");
    }

    if (tile == 'B')
    {
        cout << "================================" << endl;
        cout << "        BOSS DITEMUKAN!" << endl;
        cout << "================================" << endl;

        system("pause");

        // Nanti panggil Battle Boss
    }
}

bool randomEnemy()
{
    int chance = rand() % 100 +1;
    if (chance <= 20)
    {
        return true;
    }

    return false;
}

int main()
{
    while (true)
    {
        system("cls");

        showDungeon();
        cout << "Gold: " << gold << endl;
        movePlayer();
        if (randomEnemy())
        {
        cout << "Musuh muncul!" << endl;
        system("pause");

        // fungsi battle danen disini
        }

        checkTile();
    }
}