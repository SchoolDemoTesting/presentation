//welcome function which displays the rules if the user wants
void welcome()
{
   string answer;
   bool validity = false;
   cout << "Welcome to the dice game. Would you like to read the rules? (y/n)\n";
   do
   {
       cin >> answer;
       if ((answer == "Y") || (answer== "y")) //display rules
       {
          validity = true;
          cout << "You will first be asked how many rounds you would like to play \n";
          cout << "(Must be odd number). Three dice will be rolled, this will be your \n";
          cout << "target number. You will then be asked how many dice you would like to \n";
          cout << "roll, with the goal being to get as close to the target number as \n";
          cout << "possible without going over.\n";
       } else if ((answer == "N") || (answer == "n"))
       {
         return;
       } else //it was not a valid response
       {
          cout << "ERROR. Valid responses include Y, y, N, n,\n";
          cout << "Please enter a valid response\n";
          validity = false;
       }
   } while (validity == (false));
}

int getRounds()
{
   bool validity = false; //when this is true, getRounds succeeded in getting rounds
   int rounds;
   //error check rounds to be sure its an int, a num, and even

   do
   {
      cin >> rounds;
      if (cin.fail()) //if cin could not read the number
      {
         cout << "That was not a integer.\nPlease try again.\n";
         //clear the input buffer
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
      } else if (rounds % 2 == 0)
      {
         cout << "Sorry, that was an even number.\nPlease try again.\n";
         validity = false;
      } else
      {
        validity = true;
      }
   } while (validity == (false));
   return rounds;

}

//function will roll three dice, and add them up
//function will return target value (int between 3 and 18)
int getTarget()
{
   int rollOne = (rand() % 6) + 1;
   cout << "Dice landed on: " << rollOne << endl;
   int rollTwo = (rand() % 6) + 1;
   cout << "Dice landed on: " << rollTwo << endl;
   int rollThree = (rand() % 6) + 1;
   cout << "Dice landed on: " << rollThree << endl;

   //return the sum of the three rolls
   int sum = rollOne + rollTwo + rollThree;
   return sum;
}

int getRoll()
{

   //variable to hold user input, the amount of dice they would like to role
   int input;
   //variable to hold whether the entered value was valid
   bool validity;
   do
   {
      cout << "How many dice would you like to roll?\n";
      cin >> input;
      if (cin.fail())
      {
         cout << "That was not an integer, please try again.\n";
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         validity = false;
      } else if (input <= 0)
      {
         cout << "Cannot role a negative number of dice. Please try again.\n";
         validity = false;
      } else
      {
         validity = true;
      }
   } while (validity == false);

   return input;
}

//function to role the user specified amount of dice and add them up
int getScore(int rolls)
{
   //sum of the numbers the sidce landed on
   int score = 0;
   for (int roll = 0; roll < rolls; roll++)
   {
     int outcome = (rand() % 6) + 1;
     score = score + outcome;
     cout << "Dice landed on: " << outcome << "\n";
   }
   return score;
}

//function to decide who wins each round
//return false if round needs to restart, true if not
bool pointDecider(int com, int user, int target, int &compoints, int &userpoints)
{
   //variable to hold who is closer to the target
   int comValue = target - com;
   int userValue = target - user;
   
   //tests to go though each potential situation
   if ((com > target) && (user > target))
   {
     cout << "You and the computer both went over, round will restart\n";
     return false;
   } else if (com > target)
   {
     cout << "The computer went over the target, you win this round.\n\n";
     userpoints++;
   } else if (user > target)
   {
     cout << "You went over the target, computer wins this round.\n\n";
     compoints++;
   } else if (user == com) //its a tie
   {
      cout << "You tied, round will restart.\n";
      return false;
   } else if (comValue < userValue) //computer is closer
   {
      cout << "The computer is closer, you lose this round.\n\n";
      compoints++;
   } else if (userValue < comValue) //user is closer
   {
     cout << "You are closer, you win this round.\n\n";
     userpoints++;
   } else
   {
     return false;
   }
   return true;
}
