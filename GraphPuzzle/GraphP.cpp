#include <LedControl.h>

//Setting up the dot matrix display
int DIN = 10; 
int CS =  9;
int CLK = 8;

//setting up the button for Up
const int Up = 7; 
int UpS = 0;
//setting up the button for Down
const int Down = 6;
int DownS = 0;
//setting up the button for Left
const int Left = 5;  
int LeftS = 0; 
//setting up the button for Right
const int Right = 4;  
int RightS = 0; 

LedControl lC = LedControl(DIN,CLK,CS,0);

//Declaring array for bit value of particular rows and columns
int nm[8] = {1,2,4,8,16,32,64,128};

void setup() {
    lC.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
    lC.setIntensity(0,1);       // Set the brightness to maximum value
    lC.clearDisplay(0);          // and clear the display
    pinMode(Up, INPUT_PULLUP); 
    pinMode(Down, INPUT_PULLUP); 
    pinMode(Left, INPUT_PULLUP);
    pinMode(Right, INPUT_PULLUP);  
}

void loop() {
    // main logic
    int x=4;
    int y=4;
    while(x!=7 && y!=5){
    UpS = digitalRead(Up);
    DownS = digitalRead(Down);
    LeftS = digitalRead(Left);
    RightS = digitalRead(Right);

    if (UpS == HIGH) {
        y=y+1;
    }
    if(DownS == HIGH){
        y=y-1;
    }
    if(LeftS == HIGH){
        x=x-1;
    }
    if(RightS == HIGH){
        x=x+1;
    }
    disp(x,y);
    }
}

void disp(int x,int y){
    int i = 0;
    for(i=0;i<8;i++)
    {
    lC.setRow(0,i,nm[y]);
    lC.setColumn(0,i,nm[x]);
    }
}