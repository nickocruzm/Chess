#include "WhiteTeam.h"

WhiteTeam::WhiteTeam() {}

WhiteTeam::WhiteTeam(sf::Texture& texture){
    addPawns(texture);
    addKnights(texture);
    addBishops(texture);
    addRooks(texture);
    addQueen(texture);
    addKing(texture);
}


void WhiteTeam::addPawns(sf::Texture& texture){
    for(int i = 1; i <= 8; i++){
        Pawn pawn(1, 1, i, 2, texture);
        set.push_back(pawn);
    }
}

void WhiteTeam::addKnights(sf::Texture& texture){
    Knight knight1 (1, 3, 2, 1, texture);
    Knight knight2 (1, 3, 7, 1, texture);

    set.push_back(knight1);
    set.push_back(knight2);

}

void WhiteTeam::addBishops(sf::Texture& texture){
    Bishop DarkBishop(1, 2, 3, 1, texture);
    Bishop LightBishop(1, 2, 6, 1, texture);

    set.push_back(DarkBishop);
    set.push_back(LightBishop);
}

void WhiteTeam::addRooks(sf::Texture& texture) {
    Rook rook1 (1, 4, 1, 1, texture);
    Rook rook2 (1, 4, 8, 1, texture);

    set.push_back(rook1);
    set.push_back(rook2);
}

void WhiteTeam::addKing(sf::Texture& texture) {
    King king(1, 6, 5, 1, texture);

    set.push_back(king);
}

void WhiteTeam::addQueen(sf::Texture& texture) {
    Queen queen(1, 5, 4, 1, texture);

    set.push_back(queen);
}


bool WhiteTeam::isValidSet(){
    int PawnCount = 0;
    int BishopCount = 0;
    int KnightCount = 0;
    int RookCount = 0;
    int QueenCount = 0;
    int KingCount = 0;

    for(int i = 0; i < set.size(); i++) {
        int type = set[i].getTypeInt();

        if(type == 1) {
            PawnCount += 1;
        }
        else if(type == 2) {
            BishopCount += 1;
        }
        else if(type == 3) {
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
            cout << "unknown type found" << endl;
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

void WhiteTeam::printTeam(){
    for(int i = 0; i < this->set.size(); i++){
        set[i].printColorStr();
        cout<<" ";
        set[i].printTypeStr();
        cout<< " ";
        set[i].printPosition();
        cout<<endl;
    }
}

