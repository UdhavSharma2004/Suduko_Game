#include <iostream>
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

class game
{
public:
    vector<vector<int>> gameboard;
    string person_name;
    int size = 9;
    game()
    {
        cout << "Please enter you name::";
        cin >> person_name;
        cout << "\nWelcome! " << person_name << " to Suduko Game.\n";
        inputofgame();
    }
    void inputofgame()
    {
        cout << "\n Please Enter the values in the boxes as per instructed \n1. Fill value ranging between 1 and " << size << " only.\n2. For empty boxes fill 0 .\n3. Fill the value in boxes carefully in order to avoid wrong answer.\n";
        for (int i = 0; i < size; i++)
        {
            vector<int> v(size);
            for (int j = 0; j < size; j++)
            {
                cout << "\nValue at box (" << i + 1 << "," << j + 1 << "):";
                cin >> v[j];
            }
            gameboard.push_back(v);
        }
        cout << "Initial ";
        boardprinter();
        boardsolver();
    }
    void boardprinter()
    {
        cout << "Suduko Board Position :-\n";
        for (int i = 0; i <= 4 * size; i++)
        {
            cout << "-";
        }
        cout << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "| ";
            for (int j = 0; j < size; j++)
            {
                cout << gameboard[i][j] << " | ";
            }
            cout << endl;
            for (int i = 0; i <= 4 * size; i++)
            {
                cout << "-";
            }
            cout << endl;
        }
    }
    void boardsolver()
    {
        cout << "\nBoard is now being solved.\n";
        loading();
        bool ans = solve(gameboard);
        if (!ans)
        {
            cout << "You have entered wrong values in boxes try to figure it out and try again.";
        }
        else
        {
            cout << "Nearly completed.";
            loading();
            cout << "Game is solved you can check the solution below:-\n";
            boardprinter();
        }
    }
    bool solve(vector<vector<int>> &gameboard)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (gameboard[i][j] == 0)
                {
                    for (int val = 1; val <= 9; val++)
                    {
                        if (checker(i, j, val))
                        {
                            gameboard[i][j] = val;
                            bool nextsolution = solve(gameboard);
                            if (!nextsolution)
                            {
                                gameboard[i][j] = 0;
                            }
                            else
                            {
                                return true;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool checker(int row, int col, int val)
    {
        for (int i = 0; i < size; i++)
        {
            if (gameboard[row][i] == val)
            {
                return false;
            }
            if (gameboard[i][col] == val)
            {
                return false;
            }
            if (gameboard[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
            {
                return false;
            }
        }
        return true;
    }
    void loading()
    {
        int i = 5;
        while (i != 0)
        {
            Sleep(1000);
            cout << "* ";
            i--;
        }
        cout << endl;
    }
    ~game()
    {
        cout << "Thanks for playing " << person_name << ". this game is going to end!!\n";
        loading();
    }
};
int main()
{
    do
    {
        game gameplay;
        cout << "Want to play again (yes,no) :";
        string choice;
        cin >> choice;
        if (choice == "no")
            break;
    } while (true);
}