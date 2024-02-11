#ifndef __ROOK_H__
#define __ROOK_H__

#include "Piece.h"

using namespace std;

class Rook : public Piece {
    private:

    public:
        Rook(int color, int type, int x, int y, sf::Texture& texture);
        void move(int x, int y) override;
        bool isLegal(int x, int y) override;

};

#endif