#ifndef __PAWN_H__
#define __PAWN_H__

#include "Piece.h"

using namespace std;

class Pawn: public Piece{
    private:
        
    public:
        Pawn(int color, int type, int x, int y, sf::Texture& texture);
        void move(int x, int y) override;
        bool isLegal(int x, int y) override;

};

#endif
