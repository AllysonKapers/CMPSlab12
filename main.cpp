// Allyson Moore
// Computer Science 1- Halverson
// December 6, 2019
// Lab 12: 2D-Array
// This program reads in a file containing tic tac toe boards,
// loads each board one at a time into a 2D-array, then runs through
// a series of loops and if statements to check for a winner. 
// The program also prints out each board to a file followed by 
// a statement checking if there is a winner.
#include<iostream>
#include<fstream>
using namespace std;

int main() {
	char board[3][3];
	char token[] = { 'X', 'O' };
	// Variable for storing winning token
  // add piece variable to hold what token we are checking
	char winner, piece;
	bool winnerFound;
	ifstream infile;
	infile.open("ticLab12.txt");
	ofstream outfile;
	outfile.open("output.txt");
	int numGames = 0;

  outfile << "Allyson Moore\n";
  outfile << "Computer Science 1 - Halverson\n";
  outfile << "Lab 12: 2D-Arrays\n\n";
	if (infile) {
		// Read in number of game boards
		infile >> numGames;
		for (int x = 0; x < numGames; x++) {
			// Read in values for a single board
			for (int row = 0; row < 3; row++) {
				for (int col = 0; col < 3; col++)
					infile >> board[row][col];
			}
			// Display the game board
			for (int row = 0; row < 3; row++) {
				for (int col = 0; col < 3; col++)
					outfile << board[row][col] << " ";
				// Go to next line for next row
				outfile << '\n';
			}
			
			// Reset the winnerFound variable to false
			// for each new game
			winnerFound = false;
			winner = '\0';

			// Step 6
			// Insert a loop to traverse the token array
			// and check for X first and then O
			// Go back and replace every occurrence of 'X' 
			// with token[index] (besides the initialization of token
			// Make sure your } is placed after step 5
			// 
      for(int t = 0; t < 2; t++)
      { piece = token[t];
        // Step 2 
        // Insert a loop here that will check each row for a winner
        for(int r = 0; r < 3; r++)
        {
          if(board[r][0] == piece && 
            board[r][1] == piece && 
            board[r][2] == piece)
          {   //changes variables to winners
              winner = piece;
              winnerFound = true;
          }
        } 




			// Step 3
			// Insert a loop to check each column for a winner
        for(int c = 0; c < 3; c++)
        { //checks columns instead of rows from last step
          if(board[0][c] == piece && 
            board[1][c] == piece && 
            board[2][c] == piece)
          {
              winner = piece;
              winnerFound = true;
          }
        } 


      //uses if statements for step 4 and 5 because they are specific
      //clauses to check against.
			// Step 4
			// Insert an if statement to check the major diagonal
      if(board[0][0] == piece &&
        board[1][1] == piece &&
        board[2][2] == piece)
      {
        winner = piece;
        winnerFound = true;
      }




			// Step 5
			// Insert an if statement to check the minor diagonal
      if(board[2][0] == piece &&
        board[1][1] == piece &&
        board[2][0] == piece)
      {
        winner = piece;
        winnerFound = true;
      }



    }

			if (winnerFound)
			{
        outfile << "Game won by " << winner << "\n\n";
      }
      
      // Step 7
      // Add an if statement here to check for no winner
      if(!winnerFound)
      {
        outfile << "There is no winner!\n\n";
      }


		} // end of loop that reads in a new card
	} // end of if(infile)
	else
		outfile << "Could not open input file.\n";
	outfile.close();
	//system("pause");
	return 0;
} // end of main