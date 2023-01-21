#include <iostream>
using namespace std;

string p1, p2;
char toggle = 'X';
int row, col;
int position;
bool draw = false;

char input[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void displayFormat()
{
    cout << endl;
    cout << " " << input[0][0] << " |"
         << " " << input[0][1] << " |"
         << " " << input[0][2] << "   " << endl;
    cout << "---|---|---" << endl;
    cout << " " << input[1][0] << " |"
         << " " << input[1][1] << " |"
         << " " << input[1][2] << "   " << endl;
    cout << "---|---|---" << endl;
    cout << " " << input[2][0] << " |"
         << " " << input[2][1] << " |"
         << " " << input[2][2] << "   " << endl;
    cout << "---|---|---" << endl;
}
void playerInput()
{
    if (toggle == 'X')
    {
        cout << p1 << " enter the digit where you want to place 'X' : ";
        cin >> position;
    }
    if (toggle == 'O')
    {
        cout << p2 << " enter the digit where you want to place 'O' : ";
        cin >> position;
    }

    if (position == 1)
    {
        row = 0;
        col = 0;
    }
    if (position == 2)
    {
        row = 0;
        col = 1;
    }
    if (position == 3)
    {
        row = 0;
        col = 2;
    }
    if (position == 4)
    {
        row = 1;
        col = 0;
    }
    if (position == 5)
    {
        row = 1;
        col = 1;
    }
    if (position == 6)
    {
        row = 1;
        col = 2;
    }
    if (position == 7)
    {
        row = 2;
        col = 0;
    }
   if (position == 8)
    {
        row = 2;
        col = 1;
    }
    if (position== 9)
    {
        row = 2;
        col = 2;
    }
    else if (position < 1 || position > 9)
    {
        cout << "Enter a valid Input!!!" << endl;
        playerInput();
        }
    if (toggle == 'X' && input[row][col] != 'X' && input[row][col] != 'O')
    {
        input[row][col] = 'X';
        toggle = 'O';
    }
    else if (toggle == 'O' && input[row][col] != 'O' && input[row][col] != 'X')
    {
        input[row][col] = 'O';
        toggle = 'X';
    }
    else
    {
        cout << "No empty space on that position." << endl;
        playerInput();
    }
    displayFormat();
}

bool Win()
{
    for (int i = 0; i < 3; i++)
    {
        if ((input[i][0] == input[i][1] && input[i][0] == input[i][2]) || (input[0][i] == input[1][i] && input[0][i] == input[2][i]))
            return true;
    }
    if ((input[0][0] == input[1][1] && input[0][0] == input[2][2]) || (input[0][2] == input[1][1] && input[0][2] == input[2][0]))
        return true;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (input[i][j] != 'X' && input[i][j] != 'O')
                return false;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (input[i][j] == 'X' || input[i][j] == 'O')
                {
                draw=true;
                return true;
        }}
    }
    
}

int main()
{
    cout << "Enter the Name of Player 1 : ";
    cin >> p1;
    cout << "Enter the Name of Player 2 : ";
    cin >> p2;

    cout << p1 << " will start first.";

        displayFormat();

    while (!Win())
    {
        playerInput();
        Win();
    }

    if (toggle == 'X' && draw == false)
    {
        cout << p2 << " Wins!!!" << endl;
    }
    else if (toggle == 'O' && draw == false)
    {
        cout << p1 << " Wins!!!" << endl;
    }
    else if(draw==true)
        cout << "Game Draw" << endl;
    return 0;
}