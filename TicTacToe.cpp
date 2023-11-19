/*Problem Statement: Tic Tac Toe
There should be numbers on the grid, starting from 1 to 9. 
Either X or O, any random symbol should start the game, and it should always alternate, 
i.e if I am playing and on pressing 1, a X appears, after this game concludes, 
the next time I play, an O should appear in the first move.

Finally, upon pressing the desired number on the grid, the X or O should be placed down. 
The winning condition is that either X or O should come thrice either in a row, column or diagonal 
after which, the given symbol will win. Good luck!*/
#include <iostream>

using namespace std;

char grid[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
char currentPlayer = 'X';

// Function to display the Tic Tac Toe grid
void displayGrid() 
{
    cout << "Tic Tac Toe Game:\n";
    for (int i=0;i<3;i++) 
	{
        for (int j=0;j<3;j++) 
		{
		    	cout<<"|"<<grid[i][j]<<"| ";

        }
        cout<<endl;
    }
}

// Function to check for a win
bool checkWin() 
{
    // Checking rows and columns
    for (int i=0;i<3;i++) 
	{
        if ((grid[i][0]==grid[i][1] && grid[i][1]==grid[i][2]) || (grid[0][i]==grid[1][i] && grid[1][i]==grid[2][i])) 
		{
            return true;
        }
    }

    // Checking diagonals
    if ((grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2]) || (grid[0][2]==grid[1][1] && grid[1][1]==grid[2][0])) 
	{
        return true;
    }

    return false;
}

// Function to check if the grid is full, thus a draw
bool checkTie() 
{
    for (int i=0;i<3;i++) 
	{
        for (int j=0;j<3;j++) 
		{
            if (grid[i][j]!='X' && grid[i][j]!='O') 
			{
                return false;
            }
        }
    }
    return true;
}

// Function to switch players
void switchPlayer() 
{
    currentPlayer=(currentPlayer=='X')?'O':'X';
}

// Function to make a move
void makeMove(int cell) 
{
    // Convert the cell number to grid coordinates
    int row= (cell-1)/3;
    int col= (cell-1)%3;

    // Check if the cell is valid if not already taken by X or O
    if (cell>=1 && cell<=9 && grid[row][col]!='X' && grid[row][col]!='O') 
	{
        grid[row][col] = currentPlayer;
        switchPlayer();
    } 
	else 
	{
        cout<<"Invalid move! Please try again.\n";
    }
}

int main() 
{
    int cell;
    bool gameWon=false;
	//Checking while winning or draw conditions not met
    while (!gameWon && !checkTie()) 
	{
        displayGrid();
		//Asking user for cell value to be converted into grid coordinates
        cout<<"Player "<<currentPlayer<<", enter a corresponding number(1-9): ";
        cin>>cell;

        makeMove(cell);

        gameWon=checkWin();
    }

    displayGrid();
	//If game won/draw
    if (gameWon) 
	{
        cout<<"Player "<<currentPlayer<<" wins!";
    } 
	else 
	{
        cout<<"It's a draw!";
    }

    return 0;
}
