# 2048_game
This project is a console-based implementation of the popular game 2048, written in C++. The goal is to combine numbered tiles on a 4x4 grid to reach the 2048 tile.

How to Play

.Objective: Combine tiles to reach the 2048 tile.
.Controls:
  .w: Move up
  .s: Move down
  .a: Move left
  .d: Move right
  .n: Start a new game
  .q: Quit the game
At the start, two tiles with the number 2 are placed randomly on the board. Use the controls to move the tiles. When two tiles with the same number collide, they merge into one with their sum. After each move, a new tile with the number 2 is added to a random empty spot. The game ends when no more moves are possible.

Code Overview

Board and Directions
The game board is a 4x4 array, and movement directions are defined using arrays for down, right, up, and left moves.

Key Functions
1.)generateUnoccupiedPosition: Finds a random empty spot on the board.
2.)addPiece: Adds a new tile (2) to the board.
3.)newGame: Initializes the board and adds two tiles.
4.)printUI: Displays the board and controls.
5.)canDoMove: Checks if a move is possible.
6.)applyMove: Executes a move and adds a new tile if the move was valid.
Main Function
The main function initializes the game, processes user input, and controls the game loop. It maps user commands to directions, starts a new game, and applies moves based on user input.

Summary

This 2048 game in C++ showcases basic game development concepts such as board management, random number generation, user input handling, and game logic implementation. It serves as a great example of how to create a simple yet engaging console game.
