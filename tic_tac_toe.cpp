#include<bits/stdc++.h>
using namespace std;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char currentmarker;
int currentplayer;

void drawboard(){
    cout<<"\n "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<"\n";
    cout<<"---+---+---\n";
    cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<"\n";
    cout<<"---+---+---\n";
    cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<"\n";
    
}
bool placemarker(int slot){
    int row,col;
    col=(slot-1)%3;
    row=(slot-1)/3;
    if(board[row][col]!='X'&&board[row][col]!='O') {
        board[row][col]=currentmarker;
        return true;
    }
    return false;

}

int winner(){
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1]&&board[i][1]==board[i][2])
            return currentplayer;
        if(board[0][i]==board[1][i]&&board[1][i]==board[2][i])
            return currentplayer;
    }
    if(board[0][0]==board[1][1]&&board[1][1]==board[2][2])
        return currentplayer;
    if(board[0][2]==board[1][1]&&board[1][1]==board[2][0])
        return currentplayer; 
    return 0;  
}

void swap_p_m(){
    if(currentplayer==1) currentplayer=2;
    else currentplayer=1;
    if(currentmarker=='X') currentmarker='O';
    else currentmarker='X';
}

void game(){
    cout<<"Player 1, chosse your marker :";
    char marker_p1;
    cin>>marker_p1;
    currentplayer=1;
    currentmarker=marker_p1;
    drawboard();
    int pw;
    for(int i=0;i<9;i++){
        cout<<"It's player "<<currentplayer<<"'s turn: Enter you Slot: ";
        int slot;
        cin>>slot;
        if(slot<1||slot>9){
            i--;
            cout<<"The value of slot you entered is out of range please enter a valod value between 1 and 9\n";
            continue;
        }
        if(!placemarker(slot)){
            i--;
            cout<<"This slot is occupied, you can try for another slot\n";
            continue;
        }
        drawboard();
        pw=winner();
        if(pw==1) {
            cout<<"Player 1 won, Congratulations!!!\n "; 
            break;
        }
        if(pw==2) {
            cout<<"Player 2 won, Congratulations!!!\n "; 
            break;
        }
        swap_p_m();
        
    }
    if(pw==0)
        cout<<"This was a time game, Try Again!!! ";
}

int main(){

    game();
    cout<<"\n";
}
