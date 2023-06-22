#include "King.h"

King::King(int color, int type, int x, int y, sf::Texture& texture) : Piece(color, type, x, y) {
    sprite.setTexture(texture);
    if (color == 1) {
        sprite.setTextureRect(sf::IntRect(16, 20, 300, 300));
    }
    else {
        sprite.setTextureRect(sf::IntRect(16, 351, 300, 300));
    }
    sprite.scale(0.38, 0.38);

}

void King::move(int x, int y) {
    if (isLegal(x, y)) {
        this->updatePosition(x, y);
    }
}

bool King::isLegal(int xf, int yf) {
    //inital position(current position)
    int xi = get<0>(this->currPosition);
    int yi = get<1>(this->currPosition);
        
    //difference between (currPos - nextPos)
    int xDiff = abs(xf - xi);
    int yDiff = abs(yf - yi);

    //check if space is available??

    if (xf <= 0 && xf > 8 || yf <= 0 && yf > 8) {   //checking chessboard parameters
        cout << "Illegal Move" << endl;
        return false;
    }
    else if (xDiff > 1 || yDiff > 1) {  //specific for King movement rules
        cout << "Illegal Move" << endl;
        return false;
    }
    else { 
        return true;
    }

    return false;

}



