#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3
#define MAX_NAME_LEN 50

typedef struct {
char name[MAX_NAME_LEN];
char symbol;
} Player;

char board[ROWS][COLS];
Player players[2];

void print_board() {
printf("\n %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
printf(" -----------\n");
printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
printf(" -----------\n");
printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int check_win() {
// check rows
for (int i = 0; i < ROWS; i++) {
if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
return 1;
}
}

// check columns
for (int i = 0; i < COLS; i++) {
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
        return 1;
    }
}

// check diagonals
if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return 1;
}
if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return 1;
}

return 0;
}

int check_draw() {
for (int i = 0; i < ROWS; i++) {
for (int j = 0; j < COLS; j++) {
if (board[i][j] == ' ') {
return 0;
}
}
}
return 1;
}

void reset_board() {
for (int i = 0; i < ROWS; i++) {
for (int j = 0; j < COLS; j++) {
board[i][j] = ' ';
}
}
}

int main() {
printf("Welcome to Tic-Tac-Toe!\n");
printf("Enter the names of the players: ");
scanf("%s %s", players[0].name, players[1].name);


if (strcmp(players[0].name, players[1].name) == 0) {
    printf("Error: Players must have different names.\n");
    return 1;
}

reset_board();
players[0].symbol = 'X';
players[1].symbol = 'O';

int player = 0;
int row, col;
while (1) {
    print_board();
    printf("%s's turn. Enter row and column (1-3): ", players[player].name);
    scanf("%d %d", &row, &col);

    if (row < 1 || row > 3 || col < 1 || col > 3) {
        printf("Invalid move.\n");
        continue;
    }

    row--;
    col--;
    if (board[row][col] != ' ') {
        printf("That space is already taken.\n");
        continue;
    }

    board[row][col] = players[player].symbol;
    if (check_win()) {
        print_board();
        printf("%s wins!\n", players[player].name);
        break;
    }
    if (check_draw()) {
        print_board();
        printf("It's a draw!\n");
        break;
    }
    player = (player + 1) % 2;
}

return 0;
}

