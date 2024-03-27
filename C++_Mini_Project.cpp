#include <iostream>
#include <cstdlib>
int main()
{
    srand(time(0));
    int choice;
    cout<<"Welcome to the Game Menu!" << endl;
    cout<<"1. Play Casino Game" << endl;
    cout<<"2. Play Rock-Paper-Scissors Game" << endl;
    cout<<"Enter 1 for Casino Game and 2 for Rock-Paper-Scissors Game: ";
    cin>>choice;
    switch (choice)
        {
            case 1:
                playCasino();
                break;
            case 2:
                playRockPaperScissors();
                break;
            default:
                cout<<"Invalid choice! Exiting..." << endl;
                break;
        }
    return 0;
}
