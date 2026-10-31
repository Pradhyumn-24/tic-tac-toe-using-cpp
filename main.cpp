#include <bits/stdc++.h>
using namespace std;

int slotToIndexI(int slot){
    switch(slot){
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 2;
        default:
            cout << "Error encountered in slot switch.." << endl;
    }
    return -1;
}

int slotToIndexJ(int slot){
    switch(slot){
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 2;
        default:
            cout << "Error encountered in slot switch.." << endl;
    }
    return -1;
}

int winCondition(char grid[][3]) {
    // rows
    if (grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2]) return 1;
    if (grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2]) return 1;
    if (grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2]) return 1;

    // columns
    if (grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0]) return 1;
    if (grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1]) return 1;
    if (grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2]) return 1;

    // diagonals
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) return 1;
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) return 1;

    // else
    return 0;
}


int main() {
    int won = 0;
    string lastPlayer = "odd";
    
    // setting up the matrix
    char grid[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    

    // initialising player-1 name
    string player1, player2;
    cout << "Enter player-1 name: ";
    getline(cin, player1);


    // assigning characters to both players
    char char1, char2;
    cout << player1 << ", choose either O or X : ";
    cin >> char1;
    cin.ignore();  //removes leftover \n from above cin
    char2 = (char1 == 'O') ? 'X' : 'O';
    cout << endl;


    // initialising player-2 name
    cout << "Enter player-2 name: ";
    getline(cin, player2);  
    cout << player2 << ", you will use " << char2 << "\n\n";


    // starting the game loop
    cout << "Let's play...\n\n"; 
    for (int i = 1; i < 10; i++) {
        

        // print current matrix
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cout << grid[j][k] << " ";
            }
            cout << "\n";
        }
        cout << endl;

        // prompting the player for choosing their slot
        if (i % 2 != 0) {   // player 1
            int slot;
            cout << player1 << ", choose a slot no. for your move: ";
            cin >> slot;
            grid[slotToIndexI(slot)][slotToIndexJ(slot)] = char1;
        } 
        
        else {    //player2
            int slot;
            cout << player2 << ", choose a slot no. for your move: ";
            cin >> slot;
            grid[slotToIndexI(slot)][slotToIndexJ(slot)] = char2;
        }


        // checking the winning condition
        if (winCondition(grid)) {   // true
            if (i % 2 == 0) {
                lastPlayer = "even";
            }
            won++;
            system("cls");      // added later -> clears terminal screen
            break;
        }

        // // endlines
        // cout << "\n\n\n\n\n\n";
        // cout << "\033[2J\033[1;1H";
        system("cls");          // clears terminal screen
    }


    // determine won or draw
    string winner = (lastPlayer == "odd") ? player1 : player2;
    if (won) {
        cout << "\nCongratulations " << winner << "! you won!!\n\n";
    }
    else {
        cout << "It's a draw :(\n\n";
    }


    // print matrix for final time
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
            cout << grid[j][k] << " ";
        }
        cout << endl;
    }

    
    return 0;
}