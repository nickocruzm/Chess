#ifndef __KING_H__
#define __KING_H__

#include "Piece.h"

using namespace std;

class King : public Piece{
    private:
        
    public:
	    King(int color, int type, int x, int y, sf::Texture& texture);
	    void move(int x, int y) override;
	    bool isLegal(int x, int y) override;

};

#endif