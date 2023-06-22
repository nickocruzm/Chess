#include "Piece.h"

int main(){
    cout<<"\t TESTIING COLORS"<<endl;
    Piece pieceA(1);
    Piece pieceB(2);
    
    cout<<"\t PieceA"<<endl;
    cout<< "colorInt: " << pieceA.getColorInt() <<endl;
    cout<<"colorStr: "<< pieceA.getColorStr() <<endl;

    cout<<"\n"<<endl;

    cout<<"\t PieceB"<<endl;

    cout<<"colorInt: " << pieceB.getColorInt() <<endl;
    cout<<"colorStr: "<< pieceB.getColorStr() <<endl;

    cout<<"\n"<<endl;

    cout<<"\t TESTING PIECETYPE"<<endl;

    Piece pawn(1,1);
    cout<<pawn.getColorStr();
    cout<<" "<< pawn.getTypeStr()<<endl;
    Piece bishop(2,2);
    cout<<bishop.getColorStr();
    cout<<" "<< bishop.getTypeStr()<<endl;
    Piece knight(2,3);
    cout<<knight.getColorStr();
    cout<<" "<<knight.getTypeStr()<<endl;
    Piece Rook(1,4);
    cout<<Rook.getColorStr();
    cout<<" "<< Rook.getTypeStr()<<endl;

    Piece Queen(2,5);
    cout<< Queen.getColorStr();
    cout<<" "<<Queen.getTypeStr()<<endl;

    Piece King(1,6);
    cout<<King.getColorStr();
    cout<<" "<< King.getTypeStr()<<endl;

    cout<< "\t TESTING POSITION IN CONSTRUCTOR"<< endl;
    Piece A(2,3,4,5);
    cout<< " (2,3,4,5) => (Black, Knight, x:4, y:5)"<<endl;

    A.printColorStr();
    A.printTypeStr();
    A.printPosition();
}