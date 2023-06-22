#ifndef __BLACKTEAM_H__
#define __BLACKTEAM_H__

#include "Piece.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h" 
#include <SFML/Graphics.hpp>

class BlackTeam{
    protected:
        int turnNum = 0;
        int score = 0;
        string teamName;

    public:
        vector<Piece> set;
        
    public:
        BlackTeam();
        BlackTeam(sf::Texture&);

        void addPawns(sf::Texture&);
        void addBishops(sf::Texture&);
        void addKnights(sf::Texture&);
        void addRooks(sf::Texture&);
        void addKing(sf::Texture&);
        void addQueen(sf::Texture&);

        bool isValidSet();
        void printTeam();

};

#endif
