# “The Lime” Chess Game

**Authors**:<br>
Yen Hao Wang (Rick Wang): https://github.com/apo11o-M<br>
Nicholas Martinez (Nicko): https://github.com/NickoCruz101<br>
Derrason Towery: https://github.com/Dtowe002<br>
Maya Treves: https://github.com/mtgym2<br>

## Project Description
This is a Chess game with two players. There is a GUI for the chessboard, and the players will be entering the moves in the form of "b1 -> c3" in the command line to control the pieces.

The language of this project is C++, and the library to render the chess pieces' textures is the [SFML library](https://www.sfml-dev.org/).
We were planning to use Python and the Tkinter library at first, but not all of our group members are familiar with Python.

### Basic Concepts:
 - Front end: GUI’s, User Experience, ...
 - Back end: Data structure, Memory allocation, ...
 - Python, Tkinter library
 - C++, SFML library
 - Input Options
    1. chess board coordinates:   WHITE: [ (a-h), (1-8)] , BLACK [ (h-a), (8-1) ]<br>Example of terminal input: White(player name): b8
    2. mouse click drag pieces to desired space.
 - Output Options
    1. Have a window that shows the actual gameplay

### Phase II
#### Classes:
- Game (concrete):
  - Epic: User should be able to choose their moves and see game updates
  - User stories: 
    - Take user inputs
    - Output the pieces and boards
    - Record the historical moves
- Pieces (abstract):
  - Epic: User should be able to move each game piece
  - User stories:
    - Each piece has its own class that includes all commands and attributes
- Board (concrete):
  - Epic: User should have a clear depiction of the game board
  - User Stories:
   - Hold the unique location of each piece
- User Input:
  - Epic: Users should be able to control different aspects of the game with their keyboard
  - User stories:
    - As a user, I want to be able to choose which color I play as
    - As a user, I want to be able to control my chess pieces with my keyboard
- Objects (composite pattern):
  - Pawn (1)
  - Knight (4)
  - Bishop (4)
	- Queen (8)
	- King (10)

*Results will be updated throughout the game (based on piece values)

*(strategy pattern): implementing piece functionality
 
## Class Diagram
![image](https://user-images.githubusercontent.com/89518835/145036362-84267055-8d74-4c2c-8be1-ba7e1684d342.png)

## Screenshots
 > Screenshots of the input/output after running your application
![chess starting position](https://user-images.githubusercontent.com/89518835/145055572-d1670d39-c054-43f4-be5a-03f4157fe43e.png)
![chess prompt](https://user-images.githubusercontent.com/89518835/145055596-8bbf2944-35ba-4699-96e2-4e9e4c81167a.png)

## Installation/Usage
1. Clone the repository, be sure to clone the SFML submodule recursively.
2. Run `cmake .` in the root of the repo to generate the makefile.
3. Run `make` to compile the project, this may take a while.
4. Run the `./main` executable
5. The command line will prompt the user to input the coordinates to control the chess pieces, first the coordinate of the chess piece that you want to move, then the final destination of that chess piece.

## Testing
- Our project was tested through executing the game and validated by comparing the expected GUI output with the actual GUI output.
- Since we are using a GUI, we have a test in the main function where we declared a number of chess pieces with a specific color and coordinates, and then we visually check that every pieces are in the correct position and color.
- For the user input, we inputted different coordinates and check whether the program outputs the expected result. If the coordinates or the move is not valid (such as not on the board) it will output "invalid output". If the coordinates and the move are both valid, then the chess pieces will update its position on the board.