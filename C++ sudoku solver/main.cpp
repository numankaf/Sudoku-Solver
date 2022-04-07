#include <iostream>
#include <fstream>

using namespace std;
#define BOARD_SIZE 9

bool isInTheRow(int** board,int number,int row){
    for(int i=0;i<BOARD_SIZE;i++){
        if(board[row][i]==number){
            return true;
        }
    }
    return false;
}

bool isInTheColumn(int** board,int number,int column){
    for(int i=0;i<BOARD_SIZE;i++){
        if(board[i][column]==number){
            return true;
        }
    }
    return false;
}

bool isInTheSquare(int** board,int number,int row,int column){
    int locRow=row-row%3;
    int locCol=column-column%3;
    for(int i=locRow;i<locRow+3;i++){
        for(int j=locCol;j<locCol+3;j++){
            if(board[i][j]==number){
                return true;
            }
        }
    }
    return false;
}

bool isPlaceble(int** board,int number,int row,int column){
    return !isInTheColumn(board,number,column) &&
            !isInTheRow(board,number,row) && !isInTheSquare(board,number,row,column);
}

bool sudoku(int** board){
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            if(board[i][j]==0  ){  // 0 means it is blank
                for(int numberToPlace=1;numberToPlace<BOARD_SIZE+1;numberToPlace++){
                    if(isPlaceble(board,numberToPlace,i,j)){
                        board[i][j]=numberToPlace;
                        if(sudoku(board)){ //recursively call it
                            return true;
                        }
                        else{
                            board[i][j]=0; //if false try another number
                        }
                    }

                }
                return false;
            }
        }
    }
    return true;
}

void printTheBoard(int** board){
    for(int i=0;i<BOARD_SIZE;i++){
        if(i%3==0){
            cout<<"-------------------------\n";
        }
        for(int j=0;j<BOARD_SIZE;j++){
            if(j%3==0){
                cout<<"| ";
            }
            cout<<board[i][j]<<" ";

        }

        cout<<"|"<<endl;
    }
    cout<<"-------------------------\n";
}

int main(){
    //2d array creation

    int** board=new int*[BOARD_SIZE];
    for(int i=0;i<BOARD_SIZE;i++){
        board[i]=new int[BOARD_SIZE];
    }
    //array created


    //input from txt if you want
    /*
    ifstream cinn;
    cinn.open("input.txt");
    int k;
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            cinn>>k;
            board[i][j]=k;
        }
    }
    */


   //console input and board initialization
    int k;
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            cin>>k;
            board[i][j]=k;
        }
    }


    cout<<"SUDOKU BOARD BEFORE IT IS SOLVED"<<endl;
    printTheBoard(board);


    cout<<"\nSUDOKU BOARD AFTER IT IS SOLVED\n"<<endl;
    sudoku(board);
    printTheBoard(board);

}
