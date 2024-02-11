#include "GameManager.h"
#include "Input.h"
#include <SFML/Graphics.hpp>

GameManager::GameManager(sf::Texture& texture) {
    this->white = new WhiteTeam(texture);
    this->black = new BlackTeam(texture);
}

void GameManager::InitialPrompt(){
    cout<<"Follow the instructions and enter the position of piece you want to move,"
    <<"then enter the position of where you would like to place that Piece." << endl;
}

void GameManager::promptUserInput(){       
    tuple<int,int> initialPosition;
    tuple<int,int> finalPosition;
    
    cout << "\n";
    if (this->currTurn == 1) {
        cout << "White's turn" << endl;
    } else {
        cout << "Black's turn" << endl;
    }

    Input I;
    I.move();

    get<0>(initialPosition) = I.initialX;
    get<1>(initialPosition) = I.initialY;
    get<0>(finalPosition) = I.finalX;
    get<1>(finalPosition) = I.finalY;
    
    this->usersMove.push_back(initialPosition);
    this->usersMove.push_back(finalPosition);
    
    // cout<<"( ";
    // cout << get<0>(initialPosition)<< " , ";
    // cout << get<1>(initialPosition)<< " ) -> ";

    // cout<<"( ";
    // cout << get<0>(finalPosition) << " , ";
    // cout << get<1>(finalPosition)<<" )"<< endl;

    ++count;
    TurnTracker();
}

tuple<int, int> GameManager::getUserInput() {
    return this->usersMove[1];

}

void GameManager::PrintUsersMove(){
    cout<<"( "<< get<0>(usersMove[0])<<", ";
    cout<<get<1>(usersMove[0]) << " )";

    cout<<" -> "<< "( "<< get<0>(usersMove[1]) <<" , "<< get<1>(usersMove[1]) << " )"<<endl;
}

bool GameManager::TurnTracker() {
    //true = white
    //false = black
    if (count / 2 == 0) {
        color = true;
    }
    else {
        color = false;
    }

    return color;
}

void GameManager::CapturePiece(){
    int xf = get<0>(usersMove[1]);
    int yf = get<1>(usersMove[1]);

    this->currPiece->move(xf, yf);

    this->enemyPtr->notInPlay();
}

void GameManager::movePiece(int x, int y){
    tuple<int,int> pos = make_tuple(x,y);
    if(isSpaceFree(pos)){
        this->currPiece->move(x,y);
    }
    
}

void GameManager::getPiece(int x, int y){
    tuple<int,int> coord = make_tuple(x,y);
    if(this->currTurn == 1){
        for(int i = 0; i < white->set.size(); i++){
            if(white->set[i].getPosition() == coord){
                currPiece = &white->set[i];
            }
        }
    }else{
        for(int i = 0; i < black->set.size(); i++){
            if(black->set[i].getPosition() == coord){
                currPiece = &black->set[i];
            }
        }
    }
}

bool GameManager::isSpaceFree(tuple<int,int> usersInput){
    for(int i = 0; i < white->set.size(); i++){
        if(white->set[i].getPosition() == usersInput){
            // cout<<"whitePiece found at ";
            // cout << "space. ("<< get<0>(usersInput) << " , " << get<1>(usersInput) << ") is not free" << endl;
            if(currTurn == 2){
                this->enemyFound = true;
                this->enemyPtr = &white->set[i];
            } else{
                this->enemyFound = false;
                this->enemyPtr = nullptr;
                return false;
            }
            return false;
        }
    }
    for(int i = 0; i < black->set.size(); i++){
        if(black->set[i].getPosition() == usersInput){
            // cout<<"Black Piece found at ";
            // cout << "space. ("<< get<0>(usersInput) << " , " << get<1>(usersInput) << ") is not free." << endl;
            if(currTurn == 1){
                this->enemyFound = true;
                this->enemyPtr = &black->set[i];
            } else{
                this->enemyFound = false;
                this->enemyPtr = nullptr;
                return false;
            }
            return false;
        }

    }
    return true; 
}








