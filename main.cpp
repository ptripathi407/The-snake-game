#include <iostream>
#include <ctime>

#include <conio.h>

#include "Snake.h"
#include "Food.h"

#define WIDTH 50
#define HEIGHT 25
using namespace std;

//struct COORD(int x,y);

Snake snake({WIDTH/2, HEIGHT/2}, 1);
Food food;

int x=10, y=10;

void board()
{
    COORD snake_pos = snake.get_pos();
    COORD food_pos = food.get_pos();

    for(int i=0;i< HEIGHT;i++)
    {
        cout<<"\t\t\t\t#";
        for(int j=0;j<WIDTH-2;j++)
        {
          if(i==0 || i==HEIGHT-1)cout<<'#';
          else if(i==snake_pos.Y && j == snake_pos.X) cout << '0';
          else if(i== food_pos.Y && j== food_pos.X) cout<< '*';
          else cout<<' ';
        }
        cout<<"#\n";
    }
}
int main()
{
    srand(time(NULL));

    bool game_over = false;
    while(!game_over)
    {
       board();

       if(kbhit())    //by library conio.h usage of keyboard
       {
           switch(getch())
           {
               case 'w':snake.change_dir('u');break;
               case 'a':snake.change_dir('l');break;
               case 's':snake.change_dir('d');break;
               case 'd':snake.change_dir('r');break;
           }
       }
       snake.move_snake();

       if(snake.eaten(food.get_pos()))
       {
           food.gen_food();
           snake.grow();
       }

       if(snake.collided())
        {
            game_over=true;
            cout<<"GAME OVER";
        }



       SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0,0}); //by lib windows.h and cstdlib access to coordinates
    }
    board();

}
