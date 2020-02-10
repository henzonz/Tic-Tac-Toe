//
//  main.cpp
//  AsmtTwo
//
//  Created by Henzon Zambrano on 3/9/19.
//  Copyright © 2019 Henzon Zambrano. All rights reserved.
//

#include <iostream>
using namespace std;

bool isWon(char, char[][3]);
bool isDraw(char[][3]);
void displayBoard(char[][3]); //done
void makeAMove(char[][3], char); //done

int main() {
    //
    //    PLEASE DO NOT CHANGE function main
    //
    char board[3][3] = { { ' ', ' ', ' ' },
        { ' ', ' ', ' ' },
        { ' ', ' ', ' ' } };
    displayBoard(board);
    
    
    while (true) {
        // The first player makes a move
        makeAMove(board, 'X');
        displayBoard(board);
        if (isWon('X', board)) {
            cout << "X player won" << endl;
            exit(0);
        }
        else if (isDraw(board)) {
            cout << "No winner" << endl;
            exit(0);
        }
        
        // The second player makes a move
        makeAMove(board, 'O');
        displayBoard(board);
        
        if (isWon('O', board)) {
            cout << "O player won" << endl;
            exit(0);
        }
        else if (isDraw(board)) {
            cout << "No winner" << endl;
            exit(0);
        }
    }
    return 0;
}
void displayBoard(char board [][3]){
    for (int i = 0; i < 3; i++){            //row
        cout << "-------------" << endl;
        for (int j = 0; j < 3; j++){        //col
            cout << "| " << board[i][j] << " ";
            }
        cout << "|\n";
    }
    cout << "-------------\n" << endl;
}
void makeAMove(char board [][3], char mark){
    int rowMark, colMark;
    cout << "Enter a row (0, 1, 2) for player " << mark << "   :";
        cin >> rowMark;
        cout << "Enter a column (0, 1, 2) for player " << mark << ":";
        cin >> colMark;
    if(board[rowMark][colMark] == 'X' || board[rowMark][colMark] == 'O' ){
        cout << "This cell is already occupied. Try a different cell" << endl;
        makeAMove(board, mark);
    }else{
        while(board[rowMark][colMark] == ' '){
            for (int i = 0; i <= rowMark; i++){
                for (int j = 0; j <= colMark; j++){
                    if (board[rowMark][colMark] == board[i][j] && board[i][j] == ' ' ) {
                        board[rowMark][colMark] = mark;
                    }
                }
            }
            }
    }
    }
bool isWon (char mark, char board [][3]){
    for (int i = 0; i < 3; i++){
        if((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) ||
           (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark) ||
           (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||   //diag
           (board[2][0] == mark && board[1][1] == mark && board[0][2] == mark) ){   //diag
            return true;
        }
    }
    return false;
}
bool isDraw(char board[][3]){
    int markCounter = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (board[i][j] == 'X' || board[i][j] == 'O')
                markCounter++;
        }
    }
    if(markCounter != 9){
        return false;
    }else{}
    if(!isWon('X', board) && !isWon ('O', board)){
        return true;
    }
    return false;
}



