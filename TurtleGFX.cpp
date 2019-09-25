#include <iostream>
#include "TurtleGFX.hpp"

#define EMPTY 0
#define INKED 1
#define UP false
#define DOWN true
#define X_DIMENSION 20
#define Y_DIMENSION 20
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

using namespace std;

TurtleGFX::TurtleGFX(){
    turtleXPosition = turtleYPosition = 0;
    turtleDirection = SOUTH;
    penPosition = UP;
    for (int i = 0; i < X_DIMENSION; i++){
        for (int j = 0; j < Y_DIMENSION; j++){canvas[i][j] = EMPTY;}
    }

    cout << "Turtle GFX has been launched! ";
    TurtleGFX::printTurtlePosition();
    TurtleGFX::printTurtleDirection();
    cout << endl;
}

void TurtleGFX::printTurtlePosition(){
    cout << "The turtle is at position: (" << TurtleGFX::getXPosition() << ", " << TurtleGFX::getYPosition() << ")" << endl;
}

void TurtleGFX::printTurtleDirection(){
    short currentDirection = TurtleGFX::getDirection();

    cout << "The turtle is now facing ";
    switch(currentDirection){
        case 0: cout << "North" << endl;
            break;
        case 1: cout << "East" << endl;
            break;
        case 2: cout << "South" << endl;
            break;
        case 3: cout << "West" << endl;
            break;
    }
}

void TurtleGFX::moveFwd(short distance){
    short currentDirection = TurtleGFX::getDirection();
    short x = TurtleGFX::getXPosition();
    short y = TurtleGFX::getYPosition();
    bool penStatus = TurtleGFX::getPenPosition();
    // Used for input validation to stay in bounds
    short tempX1 = x + distance;
    short tempY1 = y + distance;
    short tempX2 = x - distance;
    short tempY2 = y - distance;

    cout << "\nBefore moving ... ";
    TurtleGFX::printTurtlePosition();

    if (penStatus){ // Updates canvas after each position traversed
        switch(currentDirection){
            case 0:
                if(tempY2 < 0){
                    cout << "ERROR: Movement places turtle out of bounds\n\n";
                    TurtleGFX::cmd(9); // Terminates program
                    break;
                }
                for (int i = y; i > y-distance-1; i--){TurtleGFX::canvas[x][i] = INKED;}
                y -= distance;
                TurtleGFX::setYPosition(y);
                break;
            case 1:
                if(tempX1 > 19){
                    cout << "ERROR: Movement places turtle out of bounds\n\n";
                    TurtleGFX::cmd(9); // Terminates program
                    break;
                }
                for (int i = x; i < distance+x+1; i++){TurtleGFX::canvas[i][y] = INKED;}
                x += distance;
                TurtleGFX::setXPosition(x);
                break;
            case 2:
                if(tempY1 > 19){
                    cout << "ERROR: Movement places turtle out of bounds\n\n";
                    TurtleGFX::cmd(9); // Terminates program
                    break;
                }
                for (int i = y; i < distance+y+1; i++){TurtleGFX::canvas[x][i] = INKED;}
                y += distance;
                TurtleGFX::setYPosition(y);
                break;
            case 3:
                if(tempX2 < 0){
                    cout << "ERROR: Movement places turtle out of bounds\n\n";
                    TurtleGFX::cmd(9); // Terminates program
                    break;
                }
                for (int i = x; i > x-distance-1; i--){TurtleGFX::canvas[i][y] = INKED;}
                x -= distance;
                TurtleGFX::setXPosition(x);
                break;
        }
    }
    else{ // Updates position without changing canvas
        switch(currentDirection){
            case 0: y -= distance;
                TurtleGFX::setYPosition(y);
                break;
            case 1: x += distance;
                TurtleGFX::setXPosition(x);
                break;
            case 2: y += distance;
                TurtleGFX::setYPosition(y);
                break;
            case 3: x -= distance;
                TurtleGFX::setXPosition(x);
                break;
        }
    }
    cout << "After moving ... ";
    TurtleGFX::printTurtlePosition();
    cout << endl;
}

void TurtleGFX::displayCanvas(){
    cout << "Begin displaying 20x20 Canvas" << endl;
    for (int i = 0; i < 22; i++){cout << "-";}
    cout << endl;

    for (int j = 0; j < 20; j++){
        cout << "|"; // First character of every row is a pipe
        for(int k = 0; k < 21; k++){
            if(k == 20){cout << "|";} // The last character is a pipe
            else{
                if(TurtleGFX::canvas[k][j] == INKED){cout << "*";}
                else{cout << " ";}
            }
        }
        cout << endl;
    }

    for (int i = 0; i < 22; i++){cout << "-";}
    cout << "\nEnd displaying Canvas\n" << endl;
}

void TurtleGFX::penUp(){
    TurtleGFX::setPenPosition(UP);
    cout << "Turtle pen has been lifted off the canvas" << endl;
}

void TurtleGFX::penDown(){
    TurtleGFX::setPenPosition(DOWN);
    cout << "Turtle pen has been pressed to the canvas" << endl;
}

void TurtleGFX::turnRight(){
    short currentDir = TurtleGFX::getDirection();
    currentDir++; // Turns right
    if (currentDir == 4){currentDir = 0;}
    TurtleGFX::setDirection(currentDir); // Updates direction

    cout << "Turtle has turned Right and is now facing ";
    switch(currentDir){
        case 0: cout << "North" << endl;
            break;
        case 1: cout << "East" << endl;
            break;
        case 2: cout << "South" << endl;
            break;
        case 3: cout << "West" << endl;
            break;
    }
}

void TurtleGFX::turnLeft(){
    short currentDir = TurtleGFX::getDirection();
    currentDir--; // Turns left
    if (currentDir == -1){currentDir = 3;}
    TurtleGFX::setDirection(currentDir); // Updates direction

    cout << "Turtle has turned Left and is now facing ";
    switch(currentDir){
        case 0: cout << "North" << endl;
            break;
        case 1: cout << "East" << endl;
            break;
        case 2: cout << "South" << endl;
            break;
        case 3: cout << "West" << endl;
            break;
    }

}

void TurtleGFX::cmd(short c){ // Command codes used to run program
    switch(c){
        case 1: TurtleGFX::penUp();
            break;
        case 2: TurtleGFX::penDown();
            break;
        case 3: TurtleGFX::turnRight();
            break;
        case 4: TurtleGFX::turnLeft();
            break;
        case 5: cout << "ERROR: Insufficient arguments received\n\n";
            cout << "Terminating TurtleGFX . . ." << endl;
            break;
        case 6: TurtleGFX::displayCanvas();
            break;
        case 9: cout << "END OF TURTLE SIMULATION\n\n";
            cout << "Terminating TurtleGFX . . ." << endl;
            break;
        default: cout << "ERROR: Invalid command code\n\n";
            cout << "Terminating TurtleGFX . . ." << endl;
    }
}

void TurtleGFX::cmd(short c, short distance){
    if(c != 5){ // Input validation
        cout << "ERROR: Invalid arguments recieved\n\n";
        cout << "Terminating TurtleGFX . . ." << endl;
    }
    else{TurtleGFX::moveFwd(distance);}
}
