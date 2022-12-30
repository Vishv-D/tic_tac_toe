This C program plays a game of Tic-Tac-Toe between two players .
 The game is played on a 3x3 board represented by a 2D array of characters called "board" .

The program starts by introducing itself and prompting the user to enter the names of the two players .
 It then initializes the board by setting all elements in the board array to the space character (' ') .
 Each player is represented by a Player struct, which has two fields: a name and a symbol .
 The symbol field is initialized to 'X' for the first player and 'O' for the second player .

The program then enters a loop where each iteration represents a turn in the game .
 On each turn, the program first prints the current state of the board using the print_board() function .
 It then prompts the current player to enter a row and column where they want to place their symbol .
 If the move is invalid (eg. the player selects a row or column outside the range 1-3, or a position that is already occupied),
 the program prints an error message and continues to the next iteration of the loop .
 Otherwise, it updates the board array with the player's symbol and checks if the player has won the game or if the game is a draw .
 If either of these conditions are true, the program prints the final board state and a message indicating the outcome of the game, and then breaks out of the loop .
 If the game is not over, it switches to the other player's turn by updating the "player" variable .

The check_win() function checks if any player has won the game by checking all rows, columns, and diagonals of the board for three consecutive symbols belonging to the same player .
 If any of these conditions are met, it returns 1 (true) .
 Otherwise, it returns 0 (false) .
 The check_draw() function checks if the board is completely filled with symbols, in which case the game is a draw .
 It returns 1 (true) if the board is full, and 0 (false) otherwise .
 The reset_board() function sets all elements in the board array to the space character (' ') in order to start a new game .

