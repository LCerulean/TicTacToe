#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

std::string player = "";
std::string computer = "Computer";
char p_mark; // X or O (player)
char c_mark; // X or O (computer)
char mark; // X or O (who's turn)
std::string turn = player; //player makes first move

bool game_over = false;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
std::vector<int> used_spaces;

void begin(){
    //get player name and choice of X/O
  std::cout << "Welcome to Tic-Tac-Toe!\nWhat is your name? ";
  std::cin >> player;
  std::cout << "Nice to meet you " << player << "! Would you like to be 'X' or 'O'? ";
  //getting player mark choice
  while (p_mark != 'X' && p_mark != 'O'){
    std::cin >> p_mark;
    p_mark = (char) toupper(p_mark);
    if (p_mark != 'X' && p_mark != 'O'){
      std::cout << "Sorry, you have to choose X or O. ";
    }
  }
  //assigning computer mark
  if (p_mark == 'X'){
    c_mark = 'O';
  }
  else {
    c_mark = 'X';
  }
  std::cout << "Great!  I'll be " << c_mark << " then.\n\nLet's play!\nYou can go first, which space do you want? \n";
}

void display(){
  //actual display of board
  std::cout << "     |     |    \n";
  std::cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
  std::cout << "_____|_____|_____\n";
  std::cout << "     |     |     \n";
  std::cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
  std::cout << "_____|_____|_____\n";
  std::cout << "     |     |     \n";
  std::cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
  std::cout << "     |     |     \n";
  }


void take_turn(){
  int choice = 0;
  int row;
  int col;

  //gets choice and determins if it is a valid move
  bool valid_move = false;
  while (valid_move == false){
    //if computer's turn:
    if (turn == computer){
      //random choice
      choice = rand() % 9 + 1;
    }
    //if player's turn:
    else {
      while (choice < 1 || choice > 9){
        std::cin >> choice; 
        if (choice < 1 || choice > 9){
          std::cout << "Sorry, " << choice << " is not a valid answer. You must pick a number between 1 and 9.\n";
        }
      }
    }
    //checks if choice is valid
    if(std::find(used_spaces.begin(), used_spaces.end(), choice) != used_spaces.end()) {
      if (turn == player){
      std::cout << "Sorry, " << choice << " is not an available space.\n";
      }
    } 
    else {
      valid_move = true;
    }
  }
  
  //puts mark on board space
  if (choice == 1){
    board[0][0] = mark;
  }
  else if (choice == 2){
    board[0][1] = mark;
  }
  else if (choice == 3){
    board[0][2] = mark;
  }
  else if (choice == 4){
    board[1][0] = mark;
  }
  else if (choice == 5){
    board[1][1] = mark;
  }
  else if (choice == 6){
    board[1][2] = mark;
  }
  else if (choice == 7){
    board[2][0] = mark;
  }
  else if (choice == 8){
    board[2][1] = mark;
  }
  else if (choice == 9){
    board[2][2] = mark;
  }
  //adding the used choice to used_spaces
  used_spaces.push_back(choice);
}

void is_game_over(){
  for (int i = 0; i < 3; i++){
    if (board[i][0] == board[i][1] && board[i][0] == board[i][2]){
      game_over = true;
    }
    else if (board[0][i] == board[1][i] && board[0][i] == board[2][i]){
      game_over = true;
    }
  }
  if (game_over == false){
    if (board[0][0] == board[1][1] && board [0][0] == board[2][2]){
    game_over = true;
    }
    else if (board[0][2] == board[1][1] && board [0][2] == board[2][0]){
      game_over = true;
    }
  }

  //game over messages
  if (game_over == true){
    std::cout << "Game over!\n" << turn << " won the game!\n";
    display(); //here to display final move
  }
  else if (used_spaces.size() == 9){
    game_over = true;
    std::cout << "Game over!\nIt's a tie!\n";
    display(); //here to display final move
  }
}

void play_game(){
  mark = p_mark; //first turn is player's
  turn = player;
  while (game_over != true){
    //output's who's turn it is.
    std::cout << turn << "'s turn.\n";
    //display of board
    display();

    take_turn();

    is_game_over();

    //switching turns if game is not over
    if (game_over != true){
      if (turn == player){
        turn = computer;
        mark = c_mark;
      }
      else if (turn == computer){
        turn = player;
        mark = p_mark;
      }
    }
  }
}
