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

void playRockPaperScissors() 
{
    again:
    int player_throw = 0;
    int ai_throw = 0;
    bool draw = false;
    do {
        cout << "Select your throw." << endl;
        cout << "1 for Rock" << endl;
        cout << "2 for Paper" << endl;
        cout << "3 for Scissors" << endl;
        cout << "Selection: ";
        cin >> player_throw;
        cout << endl;
        ai_throw = rand() % 3 + 1;
        if (ai_throw == ROCK) 
        {
            cout << "AI throws ROCK." << endl;
        } 
        else if (ai_throw == PAPER) 
        {
            cout << "AI throws PAPER." << endl;
        } 
        else if (ai_throw == SCISSORS) 
        {
            cout << "AI throws SCISSORS." << endl;
        }
        draw = false;
        if (player_throw == ai_throw) 
        {
            draw = true;
            cout << "Draw! Play again!" << endl;
        } 
        else if (player_throw == ROCK && ai_throw == SCISSORS) 
        {
            cout << "ROCK beats SCISSORS! YOU WIN." << endl;
        } 
        else if (player_throw == ROCK && ai_throw == PAPER)
         {
            cout << "PAPER beats ROCK! YOU LOSE." << endl;
        } 
        else if (player_throw == PAPER && ai_throw == ROCK) 
        {
            cout << "PAPER beats ROCK! YOU WIN." << endl;
        } 
        else if (player_throw == PAPER && ai_throw == SCISSORS) 
        {
            cout << "SCISSORS beats PAPER! YOU LOSE." << endl;
        } 
        else if (player_throw == SCISSORS && ai_throw == PAPER) 
        {
            cout << "SCISSORS beats PAPER! YOU WIN." << endl;
        } 
        else if (player_throw == SCISSORS && ai_throw == ROCK) 
        {
            cout << "ROCK beats SCISSORS! YOU LOSE." << endl;
        }
        cout << endl;
    } while (draw);
     goto again;
}

int main()
{
    srand(time(0));
    int choice;
    cout<<"Welcome!" << endl;
    cout<<"Select a Game from the Menu to play:" << endl;
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
