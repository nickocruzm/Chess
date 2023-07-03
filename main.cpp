#include <iostream>
#include <SFML/Graphics.hpp>
#include "Chessboard.h"
#include "Piece.h"

#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Rook.h"
#include "Input.h"
#include "GameManager.h"


using std::vector;


int main() {
    std::cout << "Program Start.." << std::endl;

    // the width and height of the window
    const int width = 1200;
    const int height = 1200;

    sf::RenderWindow window;
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    window.create(sf::VideoMode({1024, 768}, desktop.bitsPerPixel), "SFML window");
    window.setFramerateLimit(60);

    // load the background texture for chessboard
    sf::Texture light_green_bg;
    if (!light_green_bg.loadFromFile("assets/light_green_bg.png")) {
        std::cerr << "Failed to load image \"light_green_bg.png\"" << std::endl;
    }
    sf::Texture dark_green_bg;
    if (!dark_green_bg.loadFromFile("assets/dark_green_bg.png")) {
        std::cerr << "Failed to load image \"dark_green_bg.png\"" << std::endl;
    }
    Chessboard board(light_green_bg, dark_green_bg);


    // load the texture for the chess pieces 
    sf::Texture chess_piece_texture;
    if (!chess_piece_texture.loadFromFile("assets/chess_pieces.png")) {
        std::cerr << "Failed to load image" << std::endl;
    }
    chess_piece_texture.setSmooth(true);

    // Create the game manager
    GameManager GM = GameManager(chess_piece_texture);
    GM.InitialPrompt();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case (sf::Event::Closed):
                window.close();
                break;
            default:
                break;
            }
        }

        // Render the chess pieces and the chess board.
        window.clear(sf::Color(49, 46, 43)); // dark dark background
        board.renderBoard(window);
        for (unsigned int i = 0; i < GM.white->set.size(); i++) {
            if (GM.white->set.at(i).getInPlay()) {
                GM.white->set.at(i).drawSprite(window);
            }
        }
        for (unsigned int i = 0; i < GM.black->set.size(); i++) {
            if (GM.black->set.at(i).getInPlay()) {
                GM.black->set.at(i).drawSprite(window);
            }
        }
        window.display();
        
        // Get the user input, the piece position and it's destination
        GM.usersMove.clear();
        GM.promptUserInput();
        int x0 = get<0>(GM.usersMove[0]);
        int y0 = get<1>(GM.usersMove[0]);

        // If the chess piece exist at the target/starting position
        GM.getPiece(x0,y0);
        if (GM.currPiece != nullptr) {
            int xf = get<0>(GM.usersMove[1]);
            int yf = get<1>(GM.usersMove[1]);

            // check if the move for that piece is legal or not
            if (GM.currPiece->isLegal(xf, yf) && GM.currPiece->getColorInt() == GM.currTurn) {
                if (GM.isSpaceFree(GM.usersMove[1])) {
                    // empty space at the destination, move the piece there
                    GM.currPiece->move(xf,yf);
                } else {
                    // enemy piece at destination, capture the piece there
                    GM.CapturePiece();
                }
                // switch turns from white to black, or black to white
                if (GM.currTurn == 1) {
                    GM.currTurn = 2; 
                } else { 
                    GM.currTurn = 1; 
                }
            } else {
                cout << "The move is not legal, please enter the coordinates again." << endl;
            }

        } else {
            cout << "No chess piece at this location, please enter the coordinates again." << endl;
        }

    }
    
    cout << "..Finished\n" << endl;
    return EXIT_SUCCESS;

}
