#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "Piece.h"
#include "Pawn.h"

class Knight: public Piece{
    private:
        
    public:
        Knight(int color, int type, int x, int y, sf::Texture& texture);
        void move(int x, int y);
        bool isLegal(int xf, int yf);

};

#endif

