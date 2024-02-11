#ifndef __QUEEN_H__
#define __QUEEN_H__

#include "Piece.h"

using namespace std; 

class Queen : public Piece{
    private:
       
    public:
        Queen(int color, int type, int x, int y, sf::Texture& texture);
        void move(int x, int y) override;
        bool isLegal(int x, int y) override;

};

#endif

