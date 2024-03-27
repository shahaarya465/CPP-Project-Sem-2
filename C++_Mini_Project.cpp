#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define ROCK 1
#define PAPER 2
#define SCISSORS 3

int rand_num()
{
    return rand() % 10 + 1;
}

void playCasino() 
{
    long long amount_money;
    cout << "Enter Deposit amount to play game: $";
    cin >> amount_money;
    while (true) 
    {
        long long betting_amount;
        if (amount_money == 0) 
        {
            cout << "Sorry, you have lost all your money. Your balance now is $0." << endl;
            return;
        }
        cout << "Enter betting amount: ";
        cin >> betting_amount;
        if (betting_amount > amount_money) 
        {
            cout << "You don't have enough money." << endl;
            continue;
        }
        cout << "Guess a number between 1 and 10: ";
        int n;
        cin >> n;
        if (n > 10 || n <= 0) 
        {
            cout << "Wrong number, try again." << endl;
            continue;
        } else 
        {
            int r = rand_num();
            if (r == n) 
            {
                amount_money += (betting_amount * 10);
                cout << "Winner! Your balance now is $" << amount_money << endl;
            } else 
            {
                amount_money -= betting_amount;
                cout << "Loser! Your balance now is $" << amount_money << endl;
                cout << "The Number was: " << r << endl;
            }
        }
    }
}


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
