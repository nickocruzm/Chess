#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__

#include "WhiteTeam.h"
#include "BlackTeam.h"
#include <SFML/Graphics.hpp>

class GameManager: public WhiteTeam, BlackTeam {
    protected:
        int Whitescore = 0;
        int Blackscore = 0;
        int count = 0;
        
        bool enemyFound = false;
        
        bool color = true;

    public:
        // 1 = white turn, 2 is black turn
        int currTurn = 1;

    public:
        WhiteTeam* white = nullptr;
        BlackTeam* black = nullptr;
        Piece* currPiece = nullptr;
        Piece* enemyPtr = nullptr;
        vector<tuple<int, int>> usersMove;
        
        GameManager(sf::Texture&);
        
        void InitialPrompt();

        tuple<int, int> getUserInput();
        void promptUserInput();

        void PrintUsersMove();

        bool TurnTracker();

        void CapturePiece();
        //void movePiece(tuple<int,int> );
        void movePiece(int , int);
        bool isSpaceFree(tuple<int,int> );
        //void getPiece(tuple<int,int>);
        void getPiece(int x, int y);

};

#endif
