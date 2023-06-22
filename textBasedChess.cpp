#include "GameManager.h"

using sf::Texture;

int main(){
    Texture chess_piece_texture;
    if (!chess_piece_texture.loadFromFile("assets/chess_pieces.png")) {
        std::cerr << "Failed to load image" << endl;
    }
    chess_piece_texture.setSmooth(true);

    GameManager GM(chess_piece_texture);
    
            //Checking if  game setup is valid

    // if(GM.white->isWhiteValidSet() && GM.black->isBlackValidSet()){
    //     cout<<"VALID SETUP"<<endl;

        
    //     GM.white->printWhiteTeam();
    //     cout<<"----------------------------"<<endl;
    //     GM.black->printBlackTeam();
    // }
    // else{
    //     cout<<"invalid set"<<endl;
    // }

            //Moving White Pawn 2 spaces forward

    GM.promptUserInput();

    // tuple<int,int> finalPos = GM.getUserInput();
    int x0 = get<0>(GM.usersMove[0]);
    int y0 = get<1>(GM.usersMove[0]);

    cout<<"...Getting piece to be moved..."<<endl;

    GM.getPiece(x0,y0);
    if (GM.currPiece != nullptr) {
        GM.currPiece->printPosition();
    }

    int xf = get<0>(GM.usersMove[1]);
    int yf = get<1>(GM.usersMove[1]);

    cout<<"...attempting to move piece..."<<endl;

    if (GM.currPiece != nullptr) {
        GM.currPiece->move(xf,yf);
    }
    
    cout<<"Piece moved"<<endl;
    
    cout<<"new position"<<endl;
    GM.currPiece->printPosition();


}