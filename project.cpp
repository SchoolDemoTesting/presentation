#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

//declaring constants

//declaring function prototypes
//welcome function
void welcome();

//function to get + error check number of rounds they would like to play
int getRounds();

//function to find target number
int getTarget();

//function to ask how many dice user would like to roll
int getRoll();

//function to get user score and computer score
int getScore(int rolls);

//function to decide who wins ech round
bool pointDecider(int com, int user, int target, int &compoints, int &userpoints);

//function to display final results
int displayresults(float p1, float computer);

//function to ask if the player would like to play again


int main()
{
   //bool to hold whether or not the user would like to play again
   bool restart;
   //call the welcome function
   welcome();
   //start of game. will repeat if user decided they would like to play again
   do
   {
      //seed the rand function
      srand(time(NULL));
      //user total points
      int userpts = 0;
      //compute total points
      int compts = 0;

      //ask how many rounds they would like to play--odd integer value
      cout << "How many rounds would you like to play?\n";
      int rounds = getRounds();

      //begin loop. repeat however many times user selected
      for (int round = 0; round < rounds; round++)
      {
         //target value
         int target;
         //user value
         int userRoll;
         //computer value
         int computerRoll;
         target = getTarget();
         cout << "YOUR TARGET IS: " << target << "\n";
         bool whoisCloser;
         do
         {
            //how many dice would user like to roll?
            int userRolls = getRoll();
            //what is the sum of those rolls?
            userRoll = getScore(userRolls);

            cout << "You rolled: " << userRoll << "\n";

            //how many dice would the computer like to roll
            int computerRolls = target/4;
            cout << "\nComputer chose to role: " << computerRolls << " dice\n";
            //what is the sum of those rolls?
            computerRoll = getScore(computerRolls);

            cout << "Computer rolled: " << computerRoll << "\n";

            //call function to decide who won this round
            whoisCloser = pointDecider(computerRoll, userRoll, target, compts, userpts);
          } while (whoisCloser == (false));
          cout << "Your new score is: " << userpts << "\n";
          cout << "Computer's new score is: " << compts << "\n\n";
         }//end of for loop
         //display final results
         if (userpts > compts)
         {
            cout << "Congratulations: You win!\n";
         } else
         {
            cout << "You lost!\n";
         }
         //ask if they would like to play again

         cout << "Would you like to play again? (y/n)\n";
        
         //keep track of whether or not they enter valid data;
         bool validity = false;
         //hold their answer
         string answer;
         do
         {
            cin >> answer;
            if ((answer == "Y") || (answer== "y")) //restart program
            {
               restart = true;
               validity = true;

            } else if ((answer == "N") || (answer == "n"))
            {
               restart = false;
               return 0;
            } else //it was not a valid response
            {
               cout << "ERROR. Valid responses include Y, y, N, n,\n";
               cout << "Please enter a valid response\n";
               validity = false;
            }
         } while (validity == (false));

   } while (restart == (true));
}
































































































































