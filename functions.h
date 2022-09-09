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