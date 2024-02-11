#ifndef __PIECE_H__
#define __PIECE_H__

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

//Abstract Piece class
class Piece{
    protected:
        // type: 1 is Pawn, 2 is Bishop, 3 is Knight, 4 is Rook, 5 is Queen, 6 is King
        int typeInt = 0;
        string typeStr;

        //color, 1 is white, 2 is black
        int colorInt;
        string colorStr;
        
        //alive?
        bool inPlay;
        
        // The sprite object for this piece.
        sf::Sprite sprite;

    public:
        tuple<int,int> startPosition = make_tuple(0, 0);
        tuple<int , int> currPosition = make_tuple(0, 0); 
        
        Piece(int color); //passes in color of piece as int
        Piece(int type, int color);
        Piece(int color, int type, int x, int y);

        virtual ~Piece();

        int getColorInt();
        string getColorStr();
        int getTypeInt();
        string getTypeStr();
        tuple<int, int> getPosition();

        void printPosition();
        void printColorStr();
        void printTypeStr();

        string colorToString();
        string typeToString();

        void updatePosition(int x, int y);
        void notInPlay();

        bool getInPlay();

        // Draw the sprite onto the window
        void drawSprite(sf::RenderWindow& window);

        virtual void move(int x, int y);
        virtual bool isLegal(int x, int y);


        

};

#endif