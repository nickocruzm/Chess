#ifndef __WHITETEAM_H__
#define __WHITETEAM_H__

#include "Piece.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h" 
#include <SFML/Graphics.hpp>

class WhiteTeam{
    protected:
        int turnNum = 0;
        int score = 0;
        string teamName;
    
    public:
        vector<Piece> set;

    public:
        WhiteTeam();
        WhiteTeam(sf::Texture&);
        //WhiteTeam(string name):GameManager(*this){};
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