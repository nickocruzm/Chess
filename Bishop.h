#ifndef __BISHOP_H__
#define __BISHOP_H__

#include "Piece.h"

class Bishop : public Piece {
    private:
        bool isLightSquared = false;
        bool isDarkSquared = false;

    public:
        Bishop(int color, int type, int x, int y, sf::Texture& texture);
        void move(int x, int y) override;
        bool isLegal(int x, int y) override;
};

#endif