#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

// function prototypes
void instructions();
int beginGame(int playedBoard[]);
void displayBoard(int board[][3]);
bool testWinner(int, int, int[]);


int main(){

    int board0[4][3] = { 38, 11, 83,
                         15, 6, 33,
                         10, 2, 20,
                         86, NULL, 95};
   
    int board1[4][3] = { 28, 10, 55,
                         89, 17, 98,
                         22, 4, 31,
                         69, NULL, 78};

    int board2[4][3] = { 90, 9, 45,
                         66, 12, 48,
                         34, 7, 70,
                         44, NULL, 26};


    int ansBoard[3] = {14, 15, 8};      //stores the answer for each board
    int playedBoard[3] = {NULL};        //keeps track of which boards have been played
    int ans;                            //will store the users answer
    int wins = 0;                       //Will store the number of times the user wins
    int guessCount = 0;                 //How many guesses the user has made
    int boardNum;                       //Stores the current board in use
    bool winner;                        //Will be true or false depending on if the user wins



    instructions();
        
    // loop while the users wins are > 3
    do{
        boardNum = beginGame(playedBoard);   

        // loop while(winner != true and guessCount < 3)
        do{

            // this will display a different game board based on boardNum
            switch(boardNum){

                case 0:
                    displayBoard(board0);
                    break;
                case 1:
                    displayBoard(board1);
                    break;
                case 2:
                    displayBoard(board2);
                    break;

            }

            cout << "Please enter your guess...Or press 0 to exit\n";
                cin >> ans;

            // input validation
            while(ans < 0){

                cout << "Please enter a valid answer... must be greater than 0\n";
                cout << "Or press 0 to exit";
                    cin >> ans;
            }

            if(ans == 0){

                cout << "Thank you for playing...have a nice day!";
                return 0;
            }

            winner = testWinner(ans, boardNum, ansBoard);

            if(winner){
                
                // this will keep track of how many wins the user has
               
                playedBoard[boardNum] = 1;
                wins +=1;

                if(wins == 3){
                    
                    cout << "*** You are the gussing game Champion!!! Congragulations!!! ***\n";
                    return 0;
                }

                cout << "Do you wish to play again? Please enter 0 if you wish to exit\n";
                cout << "Otherwise enter any other number to continue.\n";
                    cin >> ans;

                if(ans == 0){

                    cout << "Thank you for playing, Hope you have a great day!\n";
                    return 0;
                }            
            }
            else{

                // this adds for each guess made
                guessCount += 1;
            }


        }while(winner != true && guessCount < 3);

        if(guessCount == 3){

            cout << "I'm sorry you're out of guesses...\n";
            cout << "If you wish to exit please enter 0... otherwise enter any number to continue.\n";
                cin >> ans;

                if(ans == 0){
                    
                    cout << "Thank you for playing, Hope you have a great day!\n";
                    return 0;
                }
        }

    }while(wins < 3);

    

    return 0;
}

    


// will choose a random board for the 
// beg. or restart of the game 
int beginGame(int playedBoard[]){

    int randomNum;
    int maxValue = 2;
    int minValue = 0;


    do{
            // Generate random word between 0-2 
           randomNum = (rand() % (maxValue - minValue + 1)) + minValue;

            // check to see if this board has not been played
           if(playedBoard[randomNum] == NULL)
              return randomNum;
   
    }while(playedBoard[randomNum] != NULL);
}
// this function is passed the current game board and 
// displays the playing board
void displayBoard(int board[][3]){             

    const int row = 4;
    const int column = 3;

// remember to display ? look for the NULL value
// These for loops will print out the game board

    for(int x = 0; x < row; x++)
    {
        for(int y = 0; y < column; y++)
        {
            if(board[x][y] == NULL)
                cout << setw(8) << "?";             //This will print unknown value in the board
            else
                cout << setw(8) << board[x][y];
        }   
        cout << endl << endl;      
    }
}

// this function is passed the user's input, the board number and the answer array
bool testWinner(int ans, int boardNum, int ansBoard[]){

    if(ans == ansBoard[boardNum]){
    
         // if they answered correctly output nice job...and return true
         cout << "You are the number guessing Champion!!!\n\n";
         return true;
    }
    // else output incorrect...and return false
    else{
        cout << "I'm sorry that answer was incorrect... :(\n\n";
        return false;
    }
}

// this function outputs a description of the game
void instructions(){


    cout << "***************************************************************************************\n";
    cout << "                           MISSING NUMBERS GAME                                        \n";
    cout << "                             A fun brain game...                                       \n";
    cout << "                                                                                       \n";
    cout << "           Please Enter a whole number to guess the missing number...                  \n";
    cout << "                  Program Developed by: Raffy                         \n";
    cout << "***************************************************************************************\n\n";


}