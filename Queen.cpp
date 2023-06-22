#include "Queen.h"

Queen::Queen(int color, int type, int x, int y, sf::Texture& texture) : Piece(color, type, x, y) {
    sprite.setTexture(texture);
    if (color == 1) {
        sprite.setTextureRect(sf::IntRect(350, 20, 300, 300));
    }
    else {
        sprite.setTextureRect(sf::IntRect(350, 351, 300, 300));
    }
    sprite.scale(0.38, 0.38);

}

void Queen::move(int x, int y) {
    if (isLegal(x, y)) {
        this->updatePosition(x, y);
    }
}

bool Queen::isLegal(int xf, int yf) {
    //inital position(current position)
    int xi = get<0>(this->currPosition);
    int yi = get<1>(this->currPosition);
    
    //difference between (currPos - nextPos)
    int xDiff = abs(xf - xi);
    int yDiff = abs(yf - yi);

    if (xf <= 0 && xf > 8 || yf <= 0 && yf > 8) {   //checking chessboard parameters
        cout << "Illegal Move" << endl;
        return false;
    }
    /*else if () {  
        cout << "Illegal Move" << endl;
        return false;
    }*/
    else if (xf == 0) {   //specific for Queen movement rules
        return true;
    }
    else if (yf == 0) {
        return true;
    }
    else {
        if (xDiff != yDiff) {
            cout << "Illegal Move" << endl;
            return false;
        }
    }

    return false;
}

