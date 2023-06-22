#include "Bishop.h"

Bishop::Bishop(int color, int type, int x, int y, sf::Texture& texture) : Piece(color, type, x, y) {
    //White Bishops
    const tuple<int,int> DarkStartA = make_tuple(3,1);
    const tuple<int,int> LightStartA = make_tuple(6,1);

    //Black Bishops
    const tuple<int,int> LightStartB = make_tuple(3,8);
    const tuple<int,int> DarkStartB = make_tuple(6,8);

    if(this->startPosition == DarkStartA || this->startPosition == DarkStartB){
        this->isDarkSquared = true;
    }
    else if(this->startPosition == LightStartA || this->startPosition == LightStartB){
        this->isLightSquared = true;
    }
    else{
        cout<<"ERROR Bishop not found to be darkSquared or LightSquared"<<endl;
    }
    
    sprite.setTexture(texture);
    if (color == 1) {
        sprite.setTextureRect(sf::IntRect(682, 20, 300, 300));
    } else {
        sprite.setTextureRect(sf::IntRect(682, 351, 300, 300));
    }
    sprite.scale(0.38, 0.38);

};

void Bishop::move(int x, int y) {
    // if(isLegal(x,y)) {
    //     this->updatePosition(x,y);

    // };
}

bool Bishop::isLegal(int xf, int yf) {
    
}