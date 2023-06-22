#include "BlackTeam.h"

BlackTeam::BlackTeam() {}

BlackTeam::BlackTeam(sf::Texture& texture){
    addPawns(texture);
    addBishops(texture);
    addKnights(texture);
    addRooks(texture);
    addQueen(texture);
    addKing(texture);
}

void BlackTeam::addPawns(sf::Texture& texture){
    for(int i = 1; i <= 8; i++){
        Pawn pawn(2, 1, i, 7, texture);
        set.push_back(pawn);
    }
}

void BlackTeam::addKnights(sf::Texture& texture){
    Knight knight1 (2, 3, 2, 8, texture);
    Knight knight2 (2, 3, 7, 8, texture);

    set.push_back(knight1);
    set.push_back(knight2);

}

void BlackTeam::addBishops(sf::Texture& texture) {
    Bishop DarkBishop(2, 2, 3, 8, texture);
    Bishop LightBishop(2, 2, 6, 8, texture);

    set.push_back(DarkBishop);
    set.push_back(LightBishop);
}

void BlackTeam::addRooks(sf::Texture& texture) {
    Rook rook1(2, 4, 1, 8, texture);
    Rook rook2(2, 4, 8, 8, texture);

    set.push_back(rook1);
    set.push_back(rook2);
}

void BlackTeam::addKing(sf::Texture& texture) {
    King king(2, 6, 5, 8, texture);

    set.push_back(king);
}

void BlackTeam::addQueen(sf::Texture& texture) {
    Queen queen(2, 5, 4, 8, texture);

    set.push_back(queen);
}

bool BlackTeam::isValidSet(){
    int PawnCount = 0;
    int BishopCount = 0;
    int KnightCount = 0;
    int RookCount = 0;
    int QueenCount = 0;
    int KingCount = 0;

    for(int i = 0; i < set.size(); i++){
        int type = set[i].getTypeInt();

        if (type == 1) {
            PawnCount += 1;
        }
        else if (type == 2) {
            BishopCount += 1;
        }
        else if (type == 3) {
            KnightCount += 1;
        }
        else if (type == 4) {
            RookCount += 1;
        }
        else if (type == 5) {
            QueenCount += 1;
        }
        else if (type == 6) {
            KingCount += 1;
        }
        else {
            cout<<"unknown type found"<<endl;
        }
    }

    cout << "PawnCount: " << PawnCount << endl;
    cout << "BishopCount: " << BishopCount << endl;
    cout << "KnightCount: " << KnightCount << endl;
    cout << "RookCount: " << RookCount << endl;
    cout << "QueenCount: " << QueenCount << endl;
    cout << "KingCount: " << KingCount << endl;

    bool check1 = (PawnCount == 8);
    bool check2 = (BishopCount == 2);
    bool check3 = (KnightCount == 2);
    bool check4 = (RookCount == 2);
    bool check5 = (QueenCount == 1);
    bool check6 = (KingCount == 1);

    if(check1 && check2 && check3 && check4 && check5 && check6){
        return true;
    }
    return false;
}

void BlackTeam::printTeam(){
    for(int i = 0; i < this->set.size(); i++){
        set[i].printColorStr();
        cout<<" ";
        set[i].printTypeStr();
        cout<< " ";
        set[i].printPosition();
        cout<<endl;
    }
}