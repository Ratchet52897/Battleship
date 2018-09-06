#include <iostream>
#include <string>
#include "battleship_class.cpp"
using namespace std;

void setname(battleship*, int);
void playgame(battleship*, int);
int play();
void position_ships(battleship*, int);

int main(void)
{
    int player_count = 2;
    battleship player[2];
    battleship *player_pointer = player;

    setname(player_pointer, player_count);

    do{

        playgame(player_pointer, player_count);

    }while (play());

}

void setname(battleship *player, int size)
{

    string name;    
    
    for(int x = 0; x < size; x++)
    {
        cout << "Enter Player[" << x + 1 << "] name: ";
        getline(cin, name);
        
        while(name.empty() || !isalpha(name.at(0)))
        {
            if(name.empty())
            {
                cout << "\nError: Name cannot be empty\n";
                cout << "Enter Player[" << x + 1 << "] name: ";
            }
            else
            {
                cout << "\nError: Name must start with a letter\n";
                cout << "Enter Player[" << x + 1 << "] name: ";
            }
            getline(cin, name);
        }

        player[x].setplayername(name);
        cout << endl;
    }
    
    system("cls");
    
}

void playgame(battleship *player, int player_count)
{
    position_ships(player, player_count);
}

int play()
{
    return 0;
}

void position_ships(battleship *player, int player_count)
{
    for(int x = 0; x < player_count; x++)
    {
        cout << player[!x].getplayername() << " look away while";
        cout << player[x].getplayername() << " positions their ships";
    }

    getchar();
}