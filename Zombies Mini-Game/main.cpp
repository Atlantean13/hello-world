// /*\Atlantis/*\
                                    /* Welcome to The Zombie Busters: Cleaning of Paradise Island from Zombie Infection ,*/

#include "Header.h"
#include <iostream>
int main()
{
    Derick w1;
    Chichonne w2;
    Grid x;
    x.printMap();
    x.printVisibleMap();
    int zombieCount=5;  // Sentinel value. The number of zombies aren't fixed to 5. Used only to enter the loop.
    int startingPlayer = 0;
    while ((startingPlayer != 1) & (startingPlayer != 2))
    {
        cout << "Select your Character! (1)Derick (2)Chichonne:";
        cin >> startingPlayer;
        if ((startingPlayer != 1) & (startingPlayer != 2))
        {
            cout << "Please enter enter 1 or 2!" << endl;
        }
    }
    while (zombieCount > 0)
    {
        if (startingPlayer == 1)
        {
            if (w1.getAlive() == 1)
            {
                cout << "           Derick's Turn              " << endl;
                zombieCount = x.moveMethod('D', w1);
                w1.printwarrior();
                startingPlayer = 2;
            }
        }
        if (startingPlayer == 2)
        {
            if (w2.getAlive() == 1)
            {
                cout << "           Chichonne's Turn              " << endl;
                zombieCount = x.moveMethod('C', w2);
                w2.printwarrior();
                startingPlayer = 1;
            }
        }         
    }
    cout << "All zombies are defeated!" << endl << " Statistics " << endl << "Players survived :" << endl ;
    if (w1.getAlive() == 1) 
    { 
        cout << "Derick" << endl;
        w1.printwarrior();
    }
    if (w2.getAlive() == 1) 
    { 
        cout << "Chichonne" << endl; 
        w2.printwarrior();
    }

    return 0;
}