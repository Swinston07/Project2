/*
 * File:   main.cpp
 * Author: Sterling Winston  2459130 & Joseph Halman 2821276
 * Created on May 16, 2023, 11:00 AM
 *
 * Purpose: Functions player 2
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

//Functions
void begin (unsigned short,unsigned short);
void line (int);
void rule (int &,int &,int &,int &,string &,string &);
void p1Liar (bool,char,char,int,int,int,int,int,int,int,int,int);
void p2Liar (bool,char,char,int,int,int,int,int,int,int,int,int);
int  p1Np2L (char,string,int,int,int,int,int,int,int);
int  p2Np1L (char,string,int,int,int,int,int,int,int);
void pProb1 (float,int);
void pProb2 (float,int);

//Execution Begins Here
int main(int argc, char** argv){
    //Setting Random Number Seed Here
    srand(static_cast<int>(time(0)));

    //Declare All Variables Here
    int            die1,die2,
                   die3,die4,
                   die5, die6,  /* number of dice in game(3 per player)
                                                      * */
                   call1,       // number of dice player1 is guessing.
                   call2,       // face of the dice the player1 is guessing.
                   call3,       // number of dice player2 is guessing.
                   call4,       // face of the dice the player2 is guessing.
                   title=0,
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
                    rule (die4,die5,die6,sumCount,p1,p2);
                    // Begin Game
                    dice.open("dice.dat", ios::in);
                    dice >> die1 >> die2 >> die3 >> die4 >> die5 >> die6;
                    cout << "Player 1 make your call" << endl;
                    cin >> call1 >> call2;                       
                    //Players make their  first calls and game continues
                    do {
                        cout << p1 <<" says " << call1 << ","<< call2 << endl;
                        //Probability player 1
                        pProb1 (prob1,call1);
                        //Truth/Liar 
                            cout << "Player 2:\n";
                            cout << "Die1: " << die4 << endl 
                                 << "Die2: " << die5 << endl << "Die3: " 
                                 << die6 << endl << endl;
                            cout << p2 << " make your call" << endl;
                            cout << "Use 'L' if you think Player1 is "
                                    "lying and "
                            "'T' if you think he "
                                 <<  "is telling the truth." << endl;
                            cin >> liar;
                    // Test to see if Player 1 is a liar
                        p1Liar (isLiar,again,liar,call1,call2,die1,die2,die3,die4,die5,die6,sumCount);                                
                    // Code for if Player 2 doesn't call Player 1 a liar
                        p2Np1L (liar,p2,call1,call2,call3,call4,die4,die5,die6);
                                //Probability player 2
                                pProb2 (prob2,call3);                               
                                cout << "Player 1 Make your call:" << endl;
                                cout << "Use 'L' if you think Player2 is "
                                        "lying and 'T' if you think he "
                                     <<  "is telling the truth." << endl;
                                cin >> liar;
                    // If Player 1 calls player 2 a liar
                        p2Liar (isLiar,again,liar,call3,call4,die1,die2,die3,die4,die5,die6,sumCount);
                                // Code for if Player 1 doesn't call Player2 a liar
                                p1Np2L (liar,p1,call1,call2,call3,call4,die1,die2,die3);
                            }while(liar == 't' || liar == 'T');
                    }while (again == 'y' || again == 'Y');
            } break;
            default: cout << endl <<"Goodbye!" << endl;
        }
        dice.close();
    //Exit Program
    return 0;
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
void rule (int &die4,int &die5,int &die6,int &sumCount,string &p1,string &p2){
    die4 = rand() % 6 + 1; // [1,6] faces of the dice
    die5 = rand() % 6 + 1; // [1,6] faces of the dice
    die6 = rand() % 6 + 1; // [1,6] faces of the dice
    sumCount = 0;
    p1 = "Player 1";
    p2 = "Player 2";
    //Display rules
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
}
void p1Liar (bool isLiar,char again,char liar,int call1,int call2,int die1,int die2,int die3,int die4,int die5,int die6,int sumCount){
     if (liar == 'l' || liar == 'L') {
    cout << "Player 2 called Player 1 a liar" 
         << endl;
    (call2 == die1) ? sumCount += die1 :
                      sumCount += 0;
    (call2 == die2) ? sumCount += die2 : 
                      sumCount += 0;
    (call2 == die3) ? sumCount += die3 : 
                      sumCount += 0;
    (call2 == die4) ? sumCount += die4 : 
                      sumCount += 0;
    (call2 == die5) ? sumCount += die5 :   
                      sumCount += 0;
    (call2 == die6) ? sumCount += die6 : 
                      sumCount += 0;

    if(sumCount >= abs(call1*call2)) {
        isLiar = false;
    }
    else
        isLiar = true;

    (isLiar) ? cout << "Player 1 is a liar. "
                       "Player "
                       "1 loses\n" :
               cout << "Player 1 is not a "
                       "liar. Player 2 loses\n";

    cout << "Play again?\n" << "'Y' for Yes "
            "'N' "
            "for No.\n";
    cin >> again;
    }
}
void p2Liar (bool isLiar,char again,char liar,int call3,int call4,int die1,int die2,int die3,int die4,int die5,int die6,int sumCount){
    if (liar == 'l' || liar == 'L') {
    cout << "Player 1 called Player 2 a liar" << endl;
    (call4 == die1) ? sumCount += die1 : 
                      sumCount += 0;
    (call4 == die2) ? sumCount += die2 : 
                      sumCount += 0;
    (call4 == die3) ? sumCount += die3 : 
                      sumCount += 0;
    (call4 == die4) ? sumCount += die4 :   
                      sumCount += 0;
    (call4 == die5) ? sumCount += die5 : 
                      sumCount += 0;
    (call4 == die6) ? sumCount += die6 :    
                      sumCount += 0;

    if(sumCount >= call3*call4) {
        isLiar = false;
    }
    else
        isLiar = true;

    (isLiar) ? cout << "Player 2 is a "
                       "liar.Player 2 "
                       "loses\n" 
             :
    cout << "Player 2 is not a liar. "
            "Player 1 loses\n";

    cout << "Play again?\n" << "'Y' for "
            "Yes 'N' for No.\n";
    cin >> again;
    }
}
int p1Np2L (char liar,string p1,int call1,int call2,int call3,int call4,int die1,int die2,int die3){
    if (liar == 't' || liar == 'T') {
    do{
        cout << "Player 1 make your call" 
             << endl;
        cin >> call1 >> call2;
    }while(call1 <= call3 && call2 <= call4
           || call1 < call3);
    } return call1,call2;
}
int p2Np1L (char liar,string p2,int call1,int call2,int call3,int call4,int die4,int die5,int die6){
    if (liar == 't' || liar == 'T') {
    do{
        cout << "Player 2:\n";
        cout << "Die1: " << die4 << endl 
             << "Die2: " << die5 << endl << "Die3: " 
             << die6 << endl << endl;
        cout << "Player 2 make your call" << endl;
        cin >> call3 >> call4;
    }while(call3 <= call1 && call4 <= call2 || 
           call3 < call1);
        cout << p2 <<" says " << call3 << "," 
             << call4 << endl;
    }return call3,call4;
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