#include<iostream>

using namespace std;

char board[3][3]={ {'1', '2', '3'}, {'4', '5', '6'},{'7', '8', '9'}};

char current_marker;
int current_player;


void DrawBoard(){
    cout<<" "<<board[0][0]<< " | "<<board[0][1]<< " | "<<board[0][2]<<endl;
    cout<< "-----------\n";
    cout<<" "<<board[1][0]<< " | "<<board[1][1]<< " | "<<board[1][2]<<endl;
    cout<< "-----------\n";
    cout<<" "<<board[2][0]<< " | "<<board[2][1]<< " | "<<board[2][2]<<endl;

}

bool placeMarker(int slot){
    int row,column;
    if(slot%3==0){
        row=(slot/3)-1;
        }

        else{
            row=slot/3;
           }

    if(slot%3==0){
        column=2;
    }
    else{
        column=(slot%3)-1;
    }
   // cout<<row<<" , "<<column<<endl;
    if(board[row][column]!='X'&& board[row][column]!='0' )
    { board[row][column]=current_marker;
    return true;
    }
    else 
    return false;
} 
int  winner(){
    for(int i=0;i<3;i++){
        //ROW
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]) return current_player;
        //COLUMN
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]) return current_player;


    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]) return current_player;
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]) return current_player;

    return 0;

}

void swap_player_and_marker(){
    if(current_marker=='X') current_marker='O';
    else current_marker='X';

    if(current_player==1) current_player=2;
    else current_player=1;
}

void game()
{
    cout<<"Player one, choose Your marker : ";
    char marker_p1;
    cin>>marker_p1;

    current_player=1;
    current_marker=marker_p1;
    DrawBoard();

    int player_won;
 
    for(int i= 0; i< 9; i++){
        cout<<"It's player" <<current_player<<"'s turn,Enter your slot: ";
        int slot;
        cin>>slot;
        if(slot<1 || slot>9){
            cout<<"That slot is invalid! Try another slot!";
            i--;
            continue;
        }
        if(!placeMarker(slot)){cout<<"That slot is occupied! Try another slot!";
        i--;
        continue;}
        placeMarker(slot);
        player_won=winner();
        if(player_won==1){ cout<<"Player one won! Congratulation!"; break;}
        if(player_won==2) { cout<<"Player Two won! Congratulation!"; break;}
        swap_player_and_marker();
        DrawBoard();
        }
        if(player_won==0)cout<<"That is a tie game!";
}

int main(){
    cout<<"Tic Tac Toe Game made by NEHA PANDEY"<<endl;
    //placeMarker(7);
    //DrawBoard();
    //cout<<"\n\n";
    //current_marker='X';
   // placeMarker(9);
    game();
    //DrawBoard();
    return 0;
}