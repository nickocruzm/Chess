#include "Piece.h"

//constructors
Piece::Piece(int color){
    this->colorInt = color;
    this->colorStr = colorToString();
    this->inPlay = true;
}

Piece::Piece(int color, int type){
    this->typeInt = type;
    this->typeStr = typeToString();

    this->colorInt = color;
    this->colorStr = colorToString();
    
    this->inPlay = true;
}

Piece::Piece(int color, int type, int x, int y){
    this->typeInt = type;
    this->typeStr = typeToString();
    
    this->colorInt = color;
    this->colorStr = colorToString();

    this->startPosition = make_tuple(x,y);
    this->currPosition = make_tuple(x,y);

    this->inPlay = true;
}

Piece::~Piece() {

}

//Accessors
int Piece::getColorInt(){
    return(this->colorInt);
}
string Piece::getColorStr(){
    return(this->colorStr);
}
int Piece::getTypeInt(){
    return this->typeInt;
}
string Piece::getTypeStr(){
    return this->typeStr;
}

tuple<int,int> Piece::getPosition(){
    return this->currPosition;
}

//out statements
void Piece::printPosition(){
    tuple<int,int> pos = this->getPosition();
    cout<<"( "<< get<0>(pos)<< " , "<<get<1>(pos)<<" )"<<endl;
}

void Piece::printColorStr(){
    cout<<this->getColorStr()<<" ";
}

void Piece::printTypeStr(){
    cout<<this->getTypeStr()<<" ";
}


//Mutators
void Piece::updatePosition(int x, int y){
    this->currPosition = make_tuple(x,y);
}

void Piece::notInPlay(){
    this->inPlay = false;
}

bool Piece::getInPlay() {
    return inPlay;
}

//Translators
string Piece::colorToString(){
    if(this->colorInt == 1){
        return("White");
    }
    else if(this->colorInt == 2){
        return("Black");
    }
    else{
        return ("Use random number generator to randomly select white or black");
    }
}

string Piece::typeToString(){
    
    int t = this->getTypeInt();

    switch(t){
        case 1:
            return("Pawn");
        case 2:
            return("Bishop");
        case 3:
            return("Knight");
        case 4:
            return("Rook");
        case 5:
           return("Queen");
        case 6:
            return("King");

        default:
            return("ALIEN PIECE");
    }
}

void Piece::drawSprite(sf::RenderWindow& window) {
    int x_coord = get<0>(currPosition);
    int y_coord = get<1>(currPosition);
    y_coord = abs(y_coord - 8);
    sprite.setPosition((x_coord - 1) * 120 + 2, y_coord * 120 + 1);
    sprite.move(120, 120);
    window.draw(sprite);
}

void Piece::move(int x, int y) {
    this->currPosition = make_tuple(x, y);
}

bool Piece::isLegal(int xf, int yf) {

    if(xf > 8 || xf < 1 || yf > 8 || yf < 1){
        cout<<"sill goose thats invalid input ;)"<<endl;
        return false;
    }
    else{
        int xi = get<0>(this->currPosition);
        int yi = get<1>(this->currPosition);

        int xDiff = abs( xf - xi );
        int yDiff = abs( yf - yi);

        switch(this->typeInt){
            //pawn
            case 1: {
                cout<<"looks like you are trying to move a pawn."<<endl;
                cout<<"...checking if input is legal for a pawn... <3 "<<endl;
                if(yDiff >= 3|| xDiff > 1 ){
                    cout<<"Exceeded the max limit a pawn can move forward"<<endl;
                    return false;
                }
                else if(yDiff== 2){
                    if(this->startPosition == this->currPosition){
                        cout<<"alright alright you can move 2 spaces forward #PawnsForLife"<<endl;
                        return true;
                    }else{
                        cout<<"YOU HIGH? you cant move a pawn two spaces forward unless it is in the startingPosition"<<endl;
                        cout<<"TRY AGAIN!"<<endl;
                        return false;
                    }
                }else if(yDiff == 1){
                    cout<<"...Checking your lame move..."<<endl;
                    if(xDiff == 1){
                        cout<<"OH you trying to capture A PIECE?!"<<endl;
                        cout<<"we don't have a capture func YET! so ill let you do it..."<< endl;
                        cout<<"SIKE!!!! MY BOY RICK MADE CAPTURE SO ILL LET HIM DECIDE YOUR FATE!"<<endl;
                        return true;
                    }
                    else{
                        cout<<"weakkkk only trying to move a pawn one space forward."<<endl;
                        return true;
                    }
                }
            } break;
            //Bishop
            case 2: {
                if (yDiff == 0) {
                    return false;
                }
                int slope = xDiff/yDiff;
                cout<<"OHHH big boy/girl trying to move a bishop???"<<endl;
                cout<<"...we will see about that..."<<endl;


                if(slope == 1){
                    return true;
                }else{
                    return false;
                }
            } break;                
            //Knight
            case 3: {
                if (xDiff == 0) {
                    return false;
                }
                double slope = (yDiff / xDiff);
                if(slope == 2.0 || slope == 0.5){
                    return true;
                }
                else if(xDiff == 2 || yDiff == 2)
                {
                    if(xDiff == 2 && yDiff == 2){
                        return false;
                    }
                    else if(xDiff == 2){

                        //Wait... think more about this condition later... (xi == 2? or xi == 1?)
                        if(xi == 7 || xi == 2){
                            cout<<"your move is out of bounds"<<endl;
                            return false;
                        }
                        //More behavior to implement later
                        else{
                            return true;
                        }


                    }
                    else{
                        cout<<"havent implemented whatever wild behavior you are trying..."<<endl;
                        return true;
                    }

                }
                else{
                    return false;
                }
            } break;
            //Rook
            case 4: {
                if(xDiff != 0 && yDiff != 0){
                    cout<<"ew thats illegal dude"<<endl;
                    return false;
                }
                else if(xDiff == 0 && yDiff != 0){
                    cout<<"moving Rook vertically..."<<endl;

                    return true;
                }
                else if(yDiff == 0 && xDiff != 0){
                    cout<<"moving Rook Horizontally..."<<endl;

                    return true;
                }
                else{
                    return false;
                }
            } break;
            //Queen
            case 5: {
                cout<<"Queen can do anything #QueenShit "<<endl;
                return true;
            } break;
            //King
            case 6: {
                if(xDiff > 1 || yDiff > 1){
                    return false;
                }else{
                    return true;
                }
            } break;
                
        }


    }
    
}