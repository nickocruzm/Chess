
#include "Pawn.h"

using namespace std;

Pawn::Pawn(int color,int type, int x, int y, sf::Texture& texture) : Piece(color,type,x,y) {
    sprite.setTexture(texture);
    if (color == 1) {
        sprite.setTextureRect(sf::IntRect(1679, 20, 300, 300));
    } else {
        sprite.setTextureRect(sf::IntRect(1677, 351, 300, 300));
    }
    sprite.scale(0.38, 0.38);
}

void Pawn::move(int x, int y) {
    if(isLegal(x,y)) {
        this->updatePosition(x,y);
    };
}

//TO DO: implement a way to check if spaces are available.
bool Pawn::isLegal(int xf,int yf)
{
    //initial Position(current Position)
    int xi = get<0>(this->currPosition);
    int yi = get<1>(this->currPosition);

    //differnce between (currPos - nextPos)
    int xDiff = abs( xf - xi );
    int yDiff = abs( yf - yi);
    


    if(xf < xi || yf < yi){// This condition must be changed for black pieces 
    //since black pieces are moving to positions 
    //that are always less than the previous position
        //white pawns start (col(i), row (2) )
        //black pawns start (col (i), row (7) )
        
        //Moving White Pawn forward (i,2) -> (i,3)
        //Moving a Black pawn forward (i,7) -> (i,6)

    //We can place a condition to check for piece color before implementing the cases


        cout<<"Illegal move: Pawn can't move backWards"<<endl;
        return false;
    }
    else if(xDiff >= 2 || yDiff >= 3)
    {
        cout<<"Illegal Move";
        return false;
    }else{
        //First check if space is available
            //if it is proceed with  following conditions
            //If space is not available determine if it is an enemy or friendly piece
                //if it is friendly piece then move cannot be made.

        if(xDiff == 0)
        { //pawn is NOT trying to capture a piece
            
            if(yDiff == 2)
            {
                if(this->startPosition == this->currPosition)
                {
                    return true;
                }
                else{
                    cout<<"ILLEGAL MOVE: Pawn can only move 2 spaces if it is the Starting Position"<<endl;
                    return false;
                }
            }
        }
        else if(xDiff == 1)
        {//Pawn is attempting to capture a piece
            
            if(yDiff > 1)
            {
                //Enemy is too far for a pawn to capture
                return false;
            }
            else{
                return true;
            }
        }

        else{
            cout<<"UNACCOUNTED FOR BEHAVIOR"<<endl;
            cout<<"Current Position ";
            this->printPosition();
            cout<<" -> (" << xf<< "," << yf<< " )"<<endl;
            return false;
        }
    }
    return false;
}
