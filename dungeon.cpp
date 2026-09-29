#include <iostream>
using namespace std;


int playerX,playerY;
char dungeon [6][5] = {
    {'_','_','_','_','_'},
    {'|','P',' ',' ','|'},
    {'|',' ',' ',' ','|'},
    {'|',' ','E',' ','|'},
    {'|',' ',' ',' ','|'},
    {'#','#','#','#','#'}   
};

void showDungeon (){
    for (int i = 0; i < 6; i++){
        for (int j = 0; j< 5; j++){
            cout << dungeon[i][j];

        }
        cout << endl;
        }
    }
    

int main(){
    showDungeon();
}
