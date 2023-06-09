/*
 * File:   main.cpp
 * Author: Sterling Winston 2459130 & Joseph Halman 2821276
 * Created on June 3, 2023, 11:44 AM
 *
 * Purpose: missing Functions player 1
 */

 //System Libraries
#include <iostream> // Input/Output library
#include <iomanip>  // Format library
#include <cmath>    // Math library
#include <fstream>  // File library
#include <cstdlib>  // Time library
#include <ctime>    // Random number generator
using namespace std;

//User Libraries

//Global Constants - Math/Physics/Chemistry/Conversions ONLY!!! 
const int DICE = 3;

//Functions
bool isLiar2(int[][DICE], const int PLYRS, int, int); // Test to see if p2 liar
bool isLiar1(int[][DICE], const int PLYRS, int, int); // Test to see if p1 liar
void srtDce(int[][DICE], int PLYRS); // Sort Dice
void prntDce(int[][DICE], const int PLYRS); // Print Dice
void intlDce(int[][DICE], const int PLYRS); // Initialize dice
void begin (unsigned short,unsigned short);
void line (int);
void rule (string &,string &);
void pProb1 (float,int);
void pProb2 (float,int);
void leave (int);

//Execution Begins Here
int main(int argc, char** argv){
    //Setting Random Number Seed Here
    srand(static_cast<int>(time(0)));

    //Declare All Variables Here
    const int PLYRS = 2;
    int    die[PLYRS][DICE], // 2D array for p1 and p2 dice
           call1, // number of dice player1 is guessing.
           call2, // face of the dice the player1 is guessing.
           call3, // number of dice player2 is guessing.
           call4, // face of the dice the player2 is guessing.
           title=0;
    fstream dice;
    string p1, p2; // Player 1 and Player2.
    char liar, // input for guessing if the player is a liar.
         again, // Play again or not
         choice,
         isLiar; // testing whether or not player is a liar.
    float prob1,prob2;
    unsigned short height; // height of letter
    unsigned short width;  // width of letter
    int n;
    
    //Initialize Variables/Input Values
    begin (height,width);
    line (title);
    //Map Input To Output/Process
    cout << endl << "Do you want to play?" << endl;
        cout << "1 = Yes\n" << "2 = No\n";   
        cin >> choice;
        switch(choice) {
            case '1': { cout << endl << "Lets Play" << endl;
                do {
                    intlDce(die, PLYRS);
                    rule(p1,p2);

                    // Begin Game
                    dice.open("dice.dat", ios::out);
                    for(int row = 0; row < PLYRS; row++){
                            for(int col = 0; col < DICE; col++){
                                dice << die[row][col] << endl;
                            }
                        }
                    
                    do{
                        prntDce(die, PLYRS);
             
                        cin >> call1 >> call2;
                     }while(call1 < 1 || call2 > 6);
                    cout << p1 <<" says " << call1 << "," << call2 
                         << endl;
                    //Players make their  first calls
                    do {
                        //Probability player 1
                        pProb1 (prob1,call1);

                        //Truth/Liar 
                        cout << p2 << " make your call" << endl;
                        cout << "Use 'L' if you think Player1 is lying and "
                                "'T' if you think he "
                             <<  "is telling the truth." << endl;
                        cin >> liar;

                            // Test to see if Player 1 is a liar
                                if (liar == 'l' || liar == 'L') {
                                    isLiar = isLiar1(die, PLYRS, call1, call2);
                                    
                                    cin >> again;
                                }
                        
                        // Code for if Player 2 doesn't call Player 1 a liar
                            else if (liar == 't' || liar == 'T') {
                                    do{
                                        cout << "Player 2 make your call"
                                             << endl;
                                        
                                        cin >> call3 >> call4;
                                        
                                    }while(call3 <= call1 && call4 <= call2 || 
                                           call3 < call1 || call4 > 6);

                                    cout << p2 <<" says " << call3<< "," 
                                         << call4 << endl;
                                    
                                    //Probability player 2       
                                        pProb2 (prob2,call3);        

                                        prntDce(die, PLYRS);
                                        cout << "Use 'L' if you think Player2 "
                                                "is lying and 'T' if you think "
                                                "he is telling the truth." 
                                             << endl;
                                        cin >> liar;

                                        // If Player 1 calls player 2 a liar
                                        if (liar == 'l' || liar == 'L') {                                            
                                        
                                            isLiar = isLiar2(die, PLYRS, call3,
                                                            call4);
                                            cin >> again;
                                        }
                                        
                                        // If player1 doesnt call player2 a iiar
                                        else if (liar == 't' || liar == 'T') {
                                            do{
                                                prntDce(die, PLYRS);
                                                
                                                cin >> call1 >> call2;
                                                
                                                cout << p1 <<" says " << call1
                                                     << "," << call2  << endl;
                                            }while(call1 <= call3 && 
                                                   call2 <= call4 ||
                                                   call1 < call3 || call2 > 6);
                                        }
                                }
                        }while(liar == 't' || liar == 'T');
                    }while (again == 'y' || again == 'Y');
            } break;
            default: cout << endl <<"Goodbye!" << endl;
        }
        dice.close(); 
        leave (n);
    //Exit Program
    return 0;
}
//Function Implementation
bool isLiar2(int a[][DICE], const int PLYRS, int b, int c){
    int count2 = 0;
    bool isLiar;       
    
    cout << "Player 1 called Player 2 "
            "a liar" 
         << endl;
    
        for(int row = 0; row < PLYRS; row++)
            for(int col = 0; col < DICE; col++){
                if(a[row][col] == c){
                    count2++;
                }
            }

        isLiar = (count2 >= b)? false:true;
        (isLiar) ? cout << "Player 2 is a "
                           "liar.Player 2 "
                           "loses\n" 
                 :
        cout << "Player 2 is not a liar. "
                "Player 1 loses\n";
        cout << "Play again?\n" << "'Y' for "
                "Yes 'N' for No.\n";
        return isLiar;
}

bool isLiar1(int a[][DICE], const int PLYRS, int b, int c){
    int count1 = 0;
    bool isLiar; 
    
    cout << "Player 2 called Player 1 a liar" 
         << endl;
    
        for(int row = 0; row < PLYRS; row++)
            for(int col = 0; col < DICE; col++){
                if(a[row][col] == c){
                    count1++;
                }
            }

        isLiar = (count1 >= b)? false:true;
        
        (isLiar) ? cout << "Player 1 is a liar. "
                           "Player "
                           "1 loses\n" :
                   cout << "Player 1 is not a "
                           "liar. Player 2 loses\n";

        cout << "Play again?\n" << "'Y' for Yes "
                "'N' "
                "for No.\n";
                                    
        return isLiar;
}

void srtDce(int a[][DICE], int PLYRS){
    // BubbleSort
    bool swap;
    do{
        swap = false;
        for(int row = 0; row < PLYRS; row++){
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
    cout << "Player 1:\n";
    for(int row = 0; row < PLYRS - 1; row++)
        for(int col = 0; col < DICE; col++){
        cout << "Die " << col+1 << ": " << a[row][col] << endl;
    }
    cout << endl << "Player 1 Make your call:" << endl;         
}

void intlDce(int a[][DICE], const int PLYRS){
    for(int row = 0; row < PLYRS; row++){
        for(int col = 0; col < DICE; col++){
        a[row][col] = rand() % 6 + 1; // [1,6] faces of dice
        }
    }
}

void begin(unsigned short height,unsigned short width){
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
    cout<<"*******"<<endl;
    cout<<"*     *"<<endl;
    cout<<"*******"<<endl;
    cout<<"* *    "<<endl;
    cout<<"*  *   "<<endl;
    cout<<"*   *  "<<endl;
    cout<<"*    *  "<<endl<<endl;
    
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
        }cout<<" "<<endl;
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
    for (int i = 0; i < width-1; i++) {
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
    //bottom half of D
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
    for (int i = 0; i < width-1; i++) {
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
        }cout<<" "<<endl;
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
}

void line (int title){
    while(title <= 20){
        cout << "LIARS DICE ";
        title++;
    }
}

void rule (string &p1,string &p2){
    p1 = "Player 1";
    p2 = "Player 2";

    //Display rules
    cout<<"LAIRS DICE"<<endl;
    cout<<"Lairs Dice is game where you have to find out "
          "who is lying about the dice on the board"<<endl
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
}

void pProb1 (float prob1,int call1){
    cout<<fixed<<setprecision(10);
    if (call1==1)
        prob1=(1.0/36);
    if (call1==2)
        prob1=(2.0/36);
    if (call1==3)
        prob1=(3.0/36);
    if (call1==4)
        prob1=(4.0/36);
    if (call1==5)
        prob1=(5.0/36);
    if (call1==6)
        prob1=(6.0/36);
    cout<<"Probability = "<<prob1<<"%"<<endl;
}

void pProb2 (float prob2,int call3){
    cout<<fixed<<setprecision(10);        
    if (call3==1)
        prob2=(1.0/36);
    if (call3==2)
        prob2=(2.0/36);
    if (call3==3)
        prob2=(3.0/36);
    if (call3==4)
        prob2=(4.0/36);
    if (call3==5)
        prob2=(5.0/36);
    if (call3==6)
        prob2=(6.0/36);
    cout<<"Probability = "<<prob2<<"%"<<endl;
}
void leave (int n){
    exit(0);
    n=0;
    cout<<"Why are you here?"<<endl;
}