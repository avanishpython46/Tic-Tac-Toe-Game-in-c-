#include <bits/stdc++.h>
using namespace std;

void print_board(string arr[]){
    for (int i=0;i<9;i++){
        if ((i + 1) % 3 == 0){
            cout << "       " << arr[i] << "";
            cout << "\n";
        }
        else{
            cout << "       " << arr[i] << "";

        }
    }
    }

bool isEmptyBoard(string arr[]){
    int c = 0;
    for (int i=0;i<9;i++){
        if (arr[i] != "__")
            c++;
    }
    return c!=9;
}

string update_board(string arr[],int pos,char val)
{
    if (arr[pos-1] != "__")
        return "Cannot Place it s already occupied";
    arr[pos-1] = val;
    return "";
}


string check_winning(string arr[]){
    //check all the rows
    {
        if (arr[0] != "__" && arr[1] != "__" && arr[2] != "__"){
        if (arr[0] == arr[1] && arr[1] == arr[2] && arr[0] == arr[2])
            return arr[0];}
        else if (arr[3] != "__" && arr[4] != "__" && arr[5] != "__"){
        if (arr[3] == arr[4] && arr[4] == arr[5] && arr[3] == arr[5])
            return arr[3];}
        else if (arr[6] != "__" && arr[7] != "__" && arr[8] != "__"){
        if (arr[6] == arr[7] && arr[7] == arr[8] && arr[6] == arr[8])
            return arr[6];}

    }
    //check all the vertical columns
    {
        if (arr[0] != "__" && arr[3] != "__" && arr[6] !="__"){
        if (arr[0] == arr[3] && arr[3]  == arr[6] && arr[0] == arr[6])
            return arr[0];}
        else if (arr[1] != "__" && arr[4] != "__" && arr[7] != "__"){
            if (arr[1] == arr[4] && arr[4] == arr[7] && arr[1] == arr[7])
            return arr[1];}
        else if (arr[2] != "__" && arr[5] != "__" && arr[8] != "__"){
        if (arr[2] == arr[5] && arr[5] == arr[8] && arr[2] == arr[8])
            return arr[2];}


    }
    //check all the diagonals
    {
        if (arr[0] != "__" && arr[4] != "__" && arr[8] != "__"){
        if (arr[0] == arr[4] && arr[4] == arr[8] && arr[0] == arr[8])
            return arr[0];}
        if (arr[2] != "__" && arr[4] != "__" && arr[6] != "__"){
        if (arr[2] == arr[4] && arr[4] == arr[6] && arr[2] == arr[6])
            return arr[2];}
    }
    return "";

}
int main(){
    cout << "***Welcome to Tic - Tac - Toe game***" << "\n";
    string arr[] = {"__","__","__",
                    "__","__","__",
                    "__","__","__"};
    cout << "\n";
    print_board(arr);
    cout << "\n";
    string name1,name2;
    cout << "Enter First Player Name : \n";
    cin >> name1;
    cout << "Enter Second Player Name : \n";
    cin >> name2;
    cout << "\n";
    cout << "Welcome " << name1 << " & " << name2 << "\n";
    char p1 = 'O';
    char p2 = 'X';
    cout << endl;
    cout << name1 << " your character is " << p1 << "\n";
    cout<<endl;
    cout << name2 << " your character is " << p2 << "\n";
    cout <<endl;
    bool tie = true;
    while (isEmptyBoard(arr)){
        int pos1,pos2;
        cout << name1 << " enter the position you want to place your character between 1..9"  << '\n';
        cin >> pos1;
        string s = update_board(arr,pos1,p1);
        string winner = check_winning(arr);
        if (!winner.empty())
        {
            if (winner == "O"){
                cout << name1 << " Congratulations you won!" << "\n";
                tie = false;
                print_board(arr);break;}
            else{
                cout << name2 << " Congratulations you won!" << "\n";
                tie = false;
                print_board(arr);break;}
        }
        cout << name2 << " enter the position you want to place your character between 1..9" << '\n';
        cin >> pos2;
        string s1 = update_board(arr,pos2,p2);
        cout << s1 << "\n";
        string w = check_winning(arr);
        if (!w.empty())
        {
            if (winner == "O"){
                cout << name1 << " Congratulations you won!" << "\n";tie = false;
                print_board(arr);
                break;}
            else{
                cout << name2 << " Congratulations you won!" << "\n"; tie = false;
                print_board(arr);break;}
        }
        cout << "\n";
        print_board(arr);
        cout << "\n";
    }
    if (tie){
        cout << "Match Tied Congrats both played well !" << "\n";
    }
    return 0;
}
