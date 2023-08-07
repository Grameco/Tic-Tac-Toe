#include<iostream>
using namespace std;

char box[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

void game() {
    cout << "   " << "  |   " << "  |  " << endl;
    cout << "  " << box[0] << "  |  " << box[1] << "  |  " << box[2] << endl;
    cout << "   " << "  |   " << "  |  " << endl;
    cout << "-----------------" << endl;
    cout << "   " << "  |   " << "  |  " << endl;
    cout << "  " << box[3] << "  |  " << box[4] << "  |  " << box[5] << endl;
    cout << "   " << "  |   " << "  |  " << endl;
    cout << "-----------------" << endl;
    cout << "   " << "  |   " << "  |  " << endl;
    cout << "  " << box[6] << "  |  " << box[7] << "  |  " << box[8] << endl; 
    cout << "   " << "  |   " << "  |  " << endl;
}

int result() {
    if ((box[0] == box[1] && box[1] == box[2]) || (box[3] == box[4] && box[4] == box[5]) || (box[6] == box[7] && box[7] == box[8]) ||  //rows
        (box[0] == box[3] && box[3] == box[6]) || (box[1] == box[4] && box[4] == box[7]) || (box[2] == box[5] && box[5] == box[8]) ||  //columns
        (box[0] == box[4] && box[4] == box[8]) || (box[2] == box[4] && box[4] == box[6])) {                                            //diagonals
        return 1; // win cases
    }
    
    else if (box[0] != '1' && box[1] != '2' && box[2] != '3' && box[3] != '4' && box[4] != '5' && box[5] != '6' && box[6] != '7' && box[7] != '8' && box[8] != '9') {
        return 0;  // game over, all boxes changed
    }
    
    return -1;  // game neither ends nor someone wins
}

void run_game() {
    int i, choice, player = 1;
    char sign;
    string player1, player2, x;

    cout << endl << endl << "\t\tTIC TAC TOE" << endl << endl;
    cout << "Enter name of Player 1: ";
    cin >> player1;
    cout << "Enter name of Player 2: ";
    cin >> player2;
    cout << player1 << " --> 'X' " << endl;
    cout << player2 << "--> 'O' " << endl << endl;

    do{
        cout << "\n\n";
        game();
        player = ( player % 2 ) ? 1 : 2;
        if( player == 1 ) cout << endl << player1 << " please enter your box: ";
        else cout << endl << player2 << " please enter your box: ";

        cin >> choice;

        sign = ( player == 1 ) ? 'X' : 'O';

        if( choice == 1 && box[0] == '1' ) box[0] = sign;
        else if( choice == 2 && box[1] == '2' ) box[1] = sign;
        else if( choice == 3 && box[2] == '3' ) box[2] = sign;
        else if( choice == 4 && box[3] == '4' ) box[3] = sign;
        else if( choice == 5 && box[4] == '5' ) box[4] = sign;
        else if( choice == 6 && box[5] == '6' ) box[5] = sign;
        else if( choice == 7 && box[6] == '7' ) box[6] = sign;
        else if( choice == 8 && box[7] == '8' ) box[7] = sign;
        else if( choice == 9 && box[8] == '9' ) box[8] = sign;
        else {
            cout << "Invalid move." << endl;
            player--;
        }

        i = result();
        player++;

    } while( i == -1 );

    player--;
    x = ( player == 1 ) ? player1 : player2;

    game();
    if( i == 1 ) cout << "CONGRATULATIONS!! \n" << x << " WINS" << endl;
    else cout << "GAME DRAW!!" << endl;
}

int main() {
    char c;
    do{
        run_game();
        cout << "Press 'C' to continue and 0 to exit: ";
        cin >> c;
        for( int i = 0; i < 9; i++ ) box[i] = i + '1';
    } while( c == 'C' || c == 'c' );
    
    return 0;
}