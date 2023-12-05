#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "connectfour.h""

// Main function where the above two functions are called.
int main() 
{
  welcomeScreen();
  //displayEmptyBoard();
  playGame();
  return 0;
}

// Function to print welcome screen and rules of game.
void welcomeScreen()
{
  printf(" CCCC   OOOO   N    N  N    N  EEEEE  CCCC  TTTTT       FFFFF  OOOO   U    U  RRRR\n");
  printf("C      O    O  N N  N  N N  N  EE    C        T         F     O    O  U    U  R   R\n");
  printf("C      O    O  N  N N  N  N N  EEEE  C        T         FFF   O    O  U    U  RRRR\n");
  printf("C      O    O  N   NN  N   NN  EE    C        T         F     O    O  U    U  R  R\n");
  printf(" CCCC   OOOO   N    N  N    N  EEEEE  CCCC    T         F      OOOO    UUUU   R   R\n\n");
  printf("CONNECT FOUR GAME RULES\n\n");
  printf("         1. The board is 6 rows and 7 columns.\n");
  printf("         2. The player with the yellow discs goes first.\n");
  printf("         3. Players drop 1 disc in the grid at a time.\n");
  printf("         4. Players alternate turns.\n");
  printf("         5. Once a player has four discs in a row vertically, horizontally, or diagonally, they have won the game!\n\n");
}

// Function to display an empty game board.
void displayEmptyBoard()
{
  printf("|-----------------------------------------|\n");
  printf("|  A  |  B  |  C  |  D  |  E  |  F  |  G  |\n");
  printf("|-----------------------------------------|\n");
  printf("|-----------------------------------------|\n");
  printf("|     |     |     |     |     |     |     |\n");
  printf("|-----|-----|-----|-----|-----|-----|-----|\n");
  printf("|     |     |     |     |     |     |     |\n");
  printf("|-----|-----|-----|-----|-----|-----|-----|\n");
  printf("|     |     |     |     |     |     |     |\n");
  printf("|-----|-----|-----|-----|-----|-----|-----|\n");
  printf("|     |     |     |     |     |     |     |\n");
  printf("|-----|-----|-----|-----|-----|-----|-----|\n");
  printf("|     |     |     |     |     |     |     |\n");
  printf("|-----|-----|-----|-----|-----|-----|-----|\n");
  printf("|     |     |     |     |     |     |     |\n");
  printf("|-----------------------------------------|\n");
}

// Function to start the gamplay cycle.
void playGame()
{
  char board[ROW][COL];
  Player yellow;
  Player red;
  int currentPlayer = YELLOW;
  int loop = ZERO;
  printf("Player Yellow, please enter your name\n");
  scanf("%s", yellow.playerName);
  yellow.playerName[0] = toupper(yellow.playerName[0]);
  printf("Player Red, please enter your name\n");
  scanf("%s", red.playerName);
  red.playerName[0] = toupper(red.playerName[0]);
  printf("%s and %s, let's play Connect Four!\n", yellow.playerName, red.playerName);
  initializeBoard(board);
  yellow.playerNum = YELLOW;
  red.playerNum = RED;
  yellow.numDisc = DISC;
  red.numDisc = DISC;
  yellow.playerChar = 'Y';
  red.playerChar = 'R';
  while(gameOver(board, yellow, red) == FALSE)
  {
    //displayEmptyBoard();
    displayBoard(board);
    if(currentPlayer == YELLOW)
    {
      makeMove(board, &yellow);
      currentPlayer = RED;

    }else if(currentPlayer == RED)
    {
      makeMove(board, &red);
      currentPlayer = YELLOW;
    }
    displayStats(yellow);
    displayStats(red);
    loop++;
  }
  displayBoard(board);
  printf("Game over!");
}

// Sets the board to all empty.
void initializeBoard(char board[ROW][COL])
{
  for(int i = 0; i < ROW; i++)
  {
    for(int j = 0; j < COL; j++)
    {
      board[i][j] = SPACE;
    }
  }
}

// Displays the board's state using the 2D array.
void displayBoard(char board[ROW][COL])
{
  printf("|-----------------------------------------|\n");
  printf("|  A  |  B  |  C  |  D  |  E  |  F  |  G  |\n");
  printf("|-----------------------------------------|\n");
  printf("|-----------------------------------------|\n");
  for(int i = 0; i < ROW; i++)
  {
    printf("|");
    for(int j = 0; j < COL; j++)
    {
      printf("  %c  |", board[i][j]);
    }
    printf("\n");
    if(i != ROW - 1)
    {
      printf("|-----|-----|-----|-----|-----|-----|-----|\n");
    }else{
      printf("|-----------------------------------------|\n");
    }
  }
}

// Ask for tplayer to make move function.
void makeMove(char board[ROW][COL], Player *player)
{
  char move[TWO];
  int valid = FALSE;
  while(valid == FALSE)
  {
    printf("%s, enter the column to place disc (e.g. B)\n", player->playerName);
    scanf("%s", move);
    int length = strlen(move);
    if (length == ONE && getMoveCol(move) != INVALID && isColFull(move, board) == FALSE) 
    {
      printf("%s, you entered: %c\n", player->playerName, toupper(move[0]));
      valid = TRUE;
      updateBoard(move, board, player);
    }else{
      printf("%s, you entered: %s\n", player->playerName, move);
      valid = FALSE;
      printf("Invalid move, try again\n");
    }
  }
}

// Function that returns the index of the column for the 2D board array using ASCII values or returns INVALID.
int getMoveCol(char move[2]) 
{
  char upperMove = toupper(move[0]);
  if (upperMove >= 'A' && upperMove <= 'G') 
  {
    return upperMove - 'A';
  }
  return INVALID;
}

// Function to display each field of the Player struct.
void displayStats(Player player)
{
  printf("****** %s's Statistics ******\n", player.playerName);
  printf("Player number: %d\n", player.playerNum);
  printf("Player character: %c\n", player.playerChar);
  printf("Player discs: %d\n", player.numDisc);
  printf("\n");
}

// Function to check if the column is full.
int isColFull(char move[2], char board[ROW][COL]) 
{
  int col = getMoveCol(move);
  if(col != INVALID) 
  {
    for(int i = 0; i < ROW; i++) 
    {
      if(board[i][col] == ' ')
      {
        return FALSE;
      }
    }
  }
  return TRUE;
}

// Function to update the game board.
void updateBoard(char move[2], char board[ROW][COL], Player *player)
{
  int col = getMoveCol(move);
  for(int i = ROW - 1; i >= 0; i--)
  {
    if(board[i][col] == SPACE)
    {
      board[i][col] = player->playerChar;
      break;
    }
  }
  player->numDisc--;
}

// Function to end the game.
int gameOver(char board[ROW][COL], Player yellow, Player red)
{
  if(yellow.numDisc == ZERO || red.numDisc == ZERO || checkWin(board) == TRUE)
  {
    return TRUE;
  }
  return FALSE;
}

// Function to check if someone has won.
int checkWin(char board[ROW][COL])
{
  // Check horizontal locations for win
  for (int r = 0; r < ROW; r++) 
  {
    for (int c = 0; c < COL - 3; c++) 
    {
      if (board[r][c] != SPACE && board[r][c] == board[r][c+1] && board[r][c] == board[r][c+2] && board[r][c] == board[r][c+3])
      {
        return TRUE;
      }
    }
  }

  // Check vertical locations for win.
  for (int r = 0; r < ROW - 3; r++) 
  {
    for (int c = 0; c < COL; c++) 
    {
      if (board[r][c] != SPACE && board[r][c] == board[r+1][c] && board[r][c] == board[r+2][c] && board[r][c] == board[r+3][c])
      {
        return TRUE;
      }
    }
  }

  // Check positively sloped diagonals
  for (int r = 0; r < ROW - 3; r++) 
  {
    for (int c = 0; c < COL - 3; c++) 
    {
      if (board[r][c] != SPACE && board[r][c] == board[r+1][c+1] && board[r][c] == board[r+2][c+2] && board[r][c] == board[r+3][c+3])
      {
        return TRUE;
      }
    }
  }

  // Check negatively sloped diagonals
  for (int r = 3; r < ROW; r++) 
  {
    for (int c = 0; c < COL - 3; c++)
    {
      if (board[r][c] != SPACE && board[r][c] == board[r-1][c+1] && board[r][c] == board[r-2][c+2] && board[r][c] == board[r-3][c+3])
      {
        return TRUE;
      }
    }
  }
  return FALSE;
}
