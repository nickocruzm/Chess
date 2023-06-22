#include "Knight.h"

Knight::Knight(int color, int type, int x, int y, sf::Texture& texture):Piece(color, type, x, y){
    sprite.setTexture(texture);
    if (color == 1) {
        sprite.setTextureRect(sf::IntRect(1016, 20, 300, 300));
    } else {
        sprite.setTextureRect(sf::IntRect(1016, 351, 300, 300));
    }
    sprite.scale(0.38, 0.38);
}

void Knight::move(int x, int y){
    if(isLegal(x,y)){
        this->updatePosition(x,y);
    }
    else{
        cout<<"illegal move: "<< x <<", "<< y <<"Is not a valid move"<<endl;
    }
}

bool Knight::isLegal(int xf,int yf){
    int xi = get<0>(this->currPosition);
    int yi = get<1>(this->currPosition);

    int xDiff = abs( xf - xi );
    int yDiff = abs( yf - yi);

    //knights must move in the x or y direction 2 spaces 
    //and then in the x or y direction 1 space

    //Behavior of knight not taking into account other pieces and such
    if(xDiff == 2){
        if(yDiff == 1){
           return true; 
        }
        else{
            return false;
        }

    }else if (yDiff == 2){
        if(xDiff == 1){
            return true;
        }
        else{
            return false;
        }

    }else{
        cout<<"Knights don't move like that"<<endl;
        return false;
    }
}