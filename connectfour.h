// Macros to make code more readable.
#define NAME 20
#define YELLOW 1
#define RED 2
#define ZERO 0
#define FOUR 4
#define ROW 6
#define COL 7
#define ONE 1
#define TWO 2
#define SPACE ' '
#define TRUE 1
#define FALSE 0
#define INVALID -1
#define DISC 21

// Struct to store all the player's information.
typedef struct Player{
int playerNum;
char playerName[NAME];
int numDisc;
char playerChar;
}Player;

// Function protypes.
void welcomeScreen();
void displayEmptyBoard();
void playGame();
void initializeBoard(char board[ROW][COL]);
void displayBoard(char board[ROW][COL]);
void makeMove(char board[ROW][COL], Player *player);
int getMoveCol(char move[2]);
void displayStats(Player player);
int isColFull(char move[2], char board[ROW][COL]);
void updateBoard(char move[2], char board[ROW][COL], Player *player);
int gameOver(char board[ROW][COL], Player yellow, Player red); 
int checkWin(char board[ROW][COL]);
