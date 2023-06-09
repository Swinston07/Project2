/*
 * File:   main.cpp
 * Author: Sterling Winston  2459130 & Joseph Halman 2821276
 * Created on May 23, 2023, 5:27 PM
 *
 * Purpose: Using functions to initialize dice , sort dice, and confirm
 * if player is liar.
 */

 //System Libraries
#include <iostream> // Input/Output library
#include <iomanip> // Format library
#include <cmath>  // Math library
#include <fstream>
#include <cstdlib>
#include <ctime> // Random number generator
using namespace std;

//User Libraries

//Global Constants - Math/Physics/Chemistry/Conversions ONLY!!! 
const int DICE = 3;

//Function Prototypes
void intlDce(int[][DICE], const int PLYRS, fstream&); // Initialize Dice
void prntDce(int[][DICE], const int PLYRS); // Print Dice
void swap(int&, int&); // Swap Function
void srtDce(int[][DICE], int PLYRS); // Sort Dice

//Execution Begins Here
int main(int argc, char** argv){
    //Setting Random Number Seed Here
    srand(static_cast<int>(time(0)));

    //Declare All Variables Here
    const int      PLYRS = 2;
    const int      SIZE = 6;
    int            die[PLYRS][DICE],
                   die1,die2,
                   die3,die4,
                   die5, die6,  /* number of dice in game(3 per player)
                                                      * */
                   call1,       // number of dice player1 is guessing.
                   call2,       // face of the dice the player1 is guessing.
                   call3,       // number of dice player2 is guessing.
                   call4,       // face of the dice the player2 is guessing.
                   title,
                   count1,
                   count2,
                   sumCount;    /*sum of all dice equal to call2. I.E.
                                If call2 = 3 and three dice are equal 
                                 * to 3, then sumCount = 9.*/
    fstream        dice;        // Reading in the dice from player 1
    string         p1, p2;      // Player 1 and Player2.
    char           liar,        // input for guessing if the player is a liar.
                   again,       // Play again or not
                   choice;      // Decision to play game or not
    bool           isLiar;      // testing whether or not player is a liar.
    float          prob1,prob2; // probability of player 1 and player2 call
    unsigned short height;      // height of letter
    unsigned short width;       // width of letter
    
    //Title
    //Letter L
    height=7;
    //vertical line
    for (int i = 0; i < height - 1; i++) {
        cout<<"*"<<endl;
    }
    //horizontal line
    for (int i = 0; i < height; i++) {
        cout<<"*";
    }cout<<endl<<endl;
    
    //Letter I
    height=7;
    width=3;
    // top horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl;
    //vertical lines
    for (int i = 0; i < height; i++) {
        cout<<" ";
        cout<<"*"<<endl;
    }
    //bottom horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl<<endl;
    
    //Letter A
    height=7;
    width=7;
     //top line
    for (int i = 0; i < width; i++) {
        if (i == width / 2) {
           cout<<"*";
        } else {
           cout<<" ";
        }
    }cout<<endl;
    //top half of A
    for (int i = 0; i < height / 2 - 1; i++) {
        for (int j = 0; j < width; j++) {
            if (j == width / 2 - i - 1 || j == width / 2 + i + 1) {
                cout<<"*";
            } else {
                cout<<" ";
            }
        }cout<<endl;
    }
    //middle line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl;
    //bottom half of A
    for (int i = 0; i < height / 2 - 1; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1) {
                cout<<"*";
            } else {
                cout<<" ";
            }
        }cout<<endl<<endl;
    }
    //Letter R
    height=7;
    width=6;
     //top horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl;
    //top half of R
    for (int i = 0; i < height / 2 - 1; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1 || j == i + 1) {
               cout<<"*";
            } else {
               cout<<" ";
            }
        }cout<<endl;
    }
    //middle horizontal line
    for (int i = 0; i < width; i++) {
        if (i == 0 || i == width - 1) {
           cout<<"*";
        } else {
           cout<<" ";
        }
    }cout<<endl;
    //bottom half of R
    for (int i = height / 2; i < height - 1; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1 || j == height - i) {
              cout<<"*";
            } else {
               cout<<" ";
            }
        }cout<<endl;
    }
    //bottom horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl<<endl;
    
    //Letter S
    height=7;
    width=6;
     //top horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl;
    //top half of S
    for (int i = 0; i < height / 2 - 1; i++) {
        cout<<"*";
        for (int j = 0; j < width - 1; j++) {
            cout<<" ";
        }cout<<"*"<<endl;
    }
    //middle horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl;
    
    // bottom half of S
    for (int i = height / 2 + 1; i < height - 1; i++) {
        cout<<" ";
        for (int j = 0; j < width - 1; j++) {
            cout<<" ";
        }cout<<"*"<<endl;
    }
    //bottom horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl<<endl;
    
    //Letter D
    height=7;
    width=6;
    //top horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl;
    // top half of D
    for (int i = 0; i < height / 2 - 1; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1) {
                cout<<"*";
            } else {
                cout<<" ";
            }
        }cout<<endl;
    }
    //printing bottom half of D
    for (int i = height / 2; i < height - 1; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1) {
                cout<<"*";
            } else {
               cout<<" ";
            }
        }cout<<endl;
    }
    //bottom horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl<<endl;
    
    //Letter I
    height=7;
    width=3;
    // top horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl;
    //vertical lines
    for (int i = 0; i < height; i++) {
        cout<<" ";
        cout<<"*"<<endl;
    }
    //bottom horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl<<endl;
    
    //Letter C
    height=7;
    width=5;
    //top horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl;
    //top half of C
    for (int i = 0; i < height ; i++) {
        cout<<"*";
        for (int j = 0; j < width - 2; j++) {
            cout<<" ";
        }cout<<"*"<<endl;
    }
    
    // bottom horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl<<endl;
    
    //Letter E
    height=7;
    width=4;
    //top horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl;
    //top vertical line
    for (int i = 0; i < height / 2 - 1; i++) {
        cout<<"*"<<endl;
    }
    //middle horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl;
    // bottom vertical line
    for (int i = 0; i < height / 2 - 1; i++) {
        cout<<"*"<<endl;
    }
    //bottom horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl<<endl;
    
    while(title <= 30){
        cout << "LIARS DICE ";
        title++;
    }
    
        cout << endl << "Do you want to play?" << endl;
        cout << "1 = Yes\n" << "2 = No\n";
            
        cin >> choice;
        switch(choice) {
            case '1': { cout << endl << "Lets Play" << endl;
        
    
    
    //Initialize Variables/Input Values
                    do {
                       // die1 = rand() % 6 + 1; // [1,6] faces of the dice
                       // die2 = rand() % 6 + 1; // [1,6] faces of the dice
                       // die3 = rand() % 6 + 1; // [1,6] faces of the dice
                       // die4 = rand() % 6 + 1; // [1,6] faces of the dice
                       // die5 = rand() % 6 + 1; // [1,6] faces of the dice
                       // die6 = rand() % 6 + 1; // [1,6] faces of the dice
                        sumCount = 0;
                        p1 = "Player 1";
                        p2 = "Player 2";

                        //Map Input To Output/Process

                        //Display Output
                        cout<<"LAIRS DICE"<<endl;
                        cout<<"Lairs Dice is game where you have to find out "
                              "who is lieing about the dice on the board"<<endl
                            <<endl;

                        cout<<"SUPPLIES"<<endl;
                        cout<<"* At least 2 players"<<endl;
                        cout<<"* And at least 3 dices"<<endl;
                        cout<<"* You can add more players before or during the "
                              "game"<<endl;
                        cout<<"* And you can use any type of dice (usually "
                              "D6s) and add how ever"
                            <<"many dice you want"<<endl<<endl;
                        cout<<"CALL"<<endl;
                        cout<<"A call is you saying how many dice of one face "
                              "is on the board"<<endl;
                        cout<<"The next persons call has to either be same "
                              "face but more dice or"
                            <<"different dice and face or raise the face and "
                              "the dice"<<endl<<endl;
                        cout<<"LAIR"<<endl;
                        cout<<"You can only call the pervious person a liar"
                            <<endl;
                        cout<<"A liar is when a call doesn't match the board"
                            <<endl;
                        cout<<"If someone is called a lair then everyone "
                              "reveals their dice"<<endl;
                        cout<<"If the person who called a liar is lying they "
                              "are out/lost"<<endl;
                        cout<<"If they are correct then the person who called "
                              "them a lair is lying"
                            <<"so they are out/lost"<<endl<<endl;
                        cout<<"STEPS"<<endl;
                        cout<<"Step 1: Make your bets"<<endl;
                        cout<<"Step 2: Role your dice and don't show your "
                              "enemy(s)"<<endl;
                        cout<<"Step 3: Player 1 makes a call then moves to "
                              "player 2"<<endl;
                        cout<<"Step 4(Optional): Add in player(s)"<<endl;
                        cout<<"Step 5: Next person calls them a liar or makes "
                              "a call"<<endl;
                        cout<<"Step 6: Repeat step 4/5"<<endl << endl;

                        // Begin Game
                        dice.open("dice.dat", ios::in);
                        intlDce(die, PLYRS, dice);
                       // dice >> die1 >> die2 >> die3 >> die4 >> die5 >> die6;
                        do{
                        cout << "Player 1 make your call" << endl;
                        cin >> call1 >> call2;
                        }while(call1 < 1 || call2 > 6);
                        
                        //Players make their  first calls and game continues
                        do {
                            cout << p1 <<" says " << call1 << "," 
                                 << call2 << endl;
                            
                            //Probability player 1
                            cout<<setprecision(12);
                            if (call1==1)
                            prob1=(1/36);
                            if (call1==2)
                            prob1=(2/36);
                            if (call1==3)
                            prob1=(3/36);
                            if (call1==4)
                            prob1=(4/36);
                            if (call1==5)
                            prob1=(5/36);
                            if (call1==6)
                            prob1=(6/36);
                            cout<<"Probability = "<<prob1<<"%"<<endl;

                        //Truth/Liar 
                                cout << "Player 2:\n";
                                prntDce(die, PLYRS);
                                cout << p2 << " make your call" << endl;
                                cout << "Use 'L' if you think Player1 is "
                                        "lying and "
                                "'T' if you think he "
                                     <<  "is telling the truth." << endl;
                                cin >> liar;

                        // Test to see if Player 1 is a liar
                                if (liar == 'l' || liar == 'L') {
                                    
                                    cout << "Player 2 called Player 1 a liar" 
                                         << endl;
                                    
                                     count1 = 0;
                                    
                                     for(int row = 0; row < PLYRS; row++){
                                        for(int col = 0; col < DICE; col++){
                                            if(die[row][col] == call2){
                                                count1++;
                                            }
                                        }
                                     }
                                    
                                    isLiar = (count1 >= call1)? false:true;

                                    (isLiar) ? cout << "Player 1 is a liar. "
                                                        "Player "
                                                       "1 loses\n" :
                                               cout << "Player 1 is not a "
                                                        "liar. "
                                                       "Player 2 loses\n";

                                    cout << "Play again?\n" << "'Y' for Yes "
                                            "'N' for No.\n";
                                    cin >> again;
                                }
                                
                        // Code for if Player 2 doesn't call Player 1 a liar
                            else if (liar == 't' || liar == 'T') {
                                do{
                                    cout << "Player 2:\n";
                                    prntDce(die, PLYRS);
                                    cout << "Player 2 make your call" << endl;
                                    cin >> call3 >> call4;
                                }while(call3 <= call1 && call4 <= call2 || 
                                       call3 < call1 || call4 > 6);
                                    cout << p2 <<" says " << call3 << "," 
                                         << call4 << endl;
                                    
                                    //Probability player 2
                                cout<<setprecision(12);        
                                if (call3==1)
                                prob2=(1/36);
                                if (call3==2)
                                prob2=(2/36);
                                if (call3==3)
                                prob2=(3/36);
                                if (call3==4)
                                prob2=(4/36);
                                if (call3==5)
                                prob2=(5/36);
                                if (call3==6)
                                prob2=(6/36);        
                                cout<<"Probability = "<<prob2<<"%"<<endl;
                                
                                    cout << "Player 1 Make your call:" << endl;
                                    cout << "Use 'L' if you think Player2 is "
                                            "lying and 'T' if you think he "
                                         <<  "is telling the truth." << endl;
                                    cin >> liar;

                        // If Player 1 calls player 2 a liar
                                    if (liar == 'l' || liar == 'L') {
                                        cout << "Player 1 called Player 2 a "
                                                "liar" 
                                             << endl;
                                        
                                         count2 = 0;
                                    
                                    for(int row = 0; row < PLYRS; row++){
                                        for(int col = 0; col < DICE; col++){
                                            if(die[row][col] == call2){
                                                count2++;
                                            }
                                        }
                                     }
                                    
                                    isLiar = (count2 >= call3)? false:true;

                                        (isLiar) ? cout << "Player 2 is a liar."
                                                           " Player 2 loses\n" :
                                        cout << "Player 2 is not a liar. "
                                                "Player 1 loses\n";

                                        cout << "Play again?\n" << "'Y' for "
                                                "Yes 'N' for No.\n";
                                        cin >> again;
                                    }
                                    /* Code for if Player 1 doesn't call Player
                                     * 2 a liar*/
                                    else if (liar == 't' || liar == 'T') {
                                        do{
                                            cout << "Player 1 make your call" 
                                                 << endl;
                                            cin >> call1 >> call2;
                                        }while(call1 <= call3 && call2 <= call4
                                               || call1 < call3 || call2 > 6);
                                    }
                                }
                            }while(liar == 't' || liar == 'T');
                    }while (again == 'y' || again == 'Y');
            } break;
            default: cout << endl <<"Goodbye!" << endl;
        }
        dice.close();
    //Exit Program
    return 0;
}
//Function Execution
void srtDce(int a[][DICE], int PLYRS){
    // BubbleSort
    bool swap;
    do{
        swap = false;
        for(int row = 1; row < PLYRS; row++){
            for(int col = 0; col < DICE-1; col++){
                if(a[row][col] > a[row][col+1]){
                    a[row][col] = a[row][col]^a[row][col+1];
                    a[row][col+1] = a[row][col]^a[row][col+1];
                    a[row][col] = a[row][col]^a[row][col+1];
                    swap = true;
                }
            }
        }
    }while(swap);
}

void prntDce(int a[][DICE], const int PLYRS){
    srtDce(a, PLYRS);
    for(int row = 1; row < PLYRS; row++){
        for(int col = 0; col < DICE; col++){
            cout << "Die " << col + 1 << ": " << a[row][col]
                 << endl;
        }
    }
        cout << endl;
}

void intlDce(int a[][DICE], const int PLYRS, fstream& d){
    for(int row = 0; row < PLYRS; row++){
        for(int col = 0; col < DICE; col++){
            d >> a[row][col];
        }
    }
}
