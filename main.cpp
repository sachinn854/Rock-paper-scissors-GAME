#include <algorithm> // For std::transform
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

int AutoGenerate() {
  int RandomNumber = rand();
  RandomNumber = RandomNumber % 3;
  return RandomNumber;
}

string toLowercase(string str) {
  for (size_t i = 0; i < str.length(); ++i) {
    str[i] = tolower(str[i]);
  }
  return str;
}

string finalOutput(string UserInput, string AutoGenerateInput) {
  UserInput = toLowercase(UserInput);
  AutoGenerateInput = toLowercase(AutoGenerateInput);

  if (UserInput == AutoGenerateInput) {
    return "Game is a tie!";
  }

  if (UserInput == "rock") {
    if (AutoGenerateInput == "scissor")
      return "You Win!";
    else if (AutoGenerateInput == "paper")
      return "You lose :(";
  } else if (UserInput == "paper") {
    if (AutoGenerateInput == "rock")
      return "You Win!";
    else if (AutoGenerateInput == "scissor")
      return "You lose :(";
  } else if (UserInput == "scissor") {
    if (AutoGenerateInput == "paper")
      return "You Win!";
    else if (AutoGenerateInput == "rock")
      return "You lose :(";
  }

  return "Invalid Input";
}

int main() {

  srand(static_cast<unsigned int>(time(0)));

  int Auto = AutoGenerate();
  string AutoInput;
  switch (Auto) {
  case 0:
    AutoInput = "Rock";
    break;
  case 1:
    AutoInput = "Paper";
    break;
  case 2:
    AutoInput = "Scissor";
    break;
  }

  string UserInput;
  cout << "Welcome to the Game!" << endl;
  cout << "Enter your choice (Rock, Paper, Scissor): ";
  cin >> UserInput;

  // Convert the user input to lowercase for uniformity
  std::transform(UserInput.begin(), UserInput.end(), UserInput.begin(),
                 ::tolower);

  cout << "Your choice is: " << UserInput << endl;
  cout << "Auto-generated choice is: " << AutoInput << endl;

  string result = finalOutput(UserInput, AutoInput);

  cout << result << endl;

  cout << endl;
  while (1) {
    int a;
    cout << "If you want to play again so Enter 1 otherwise 0" << endl;
    cin >> a;
    switch (a) {
    case 1:
      main();
      cout << endl;
      break;
    case 0:
      cout << "Thanks For Playing" << endl;
      exit(1);
      break;
    default:
      cout << "Invalid Input Enter again" << endl;
      ;
    }
  }
  return 0;
}

