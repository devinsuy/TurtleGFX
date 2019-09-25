class TurtleGFX{
public:
    TurtleGFX();
    void printTurtlePosition();
    void printTurtleDirection();
    void penUp();
    void penDown();
    void turnRight();
    void turnLeft();
    void moveFwd(short);
    void displayCanvas();
    void cmd (short);
    void cmd(short, short);

    // Public interface to access instance variables
    short getXPosition(){return turtleXPosition;}
    short getYPosition(){return turtleYPosition;}
    short getDirection(){return turtleDirection;}
    bool getPenPosition(){return penPosition;}
    void setXPosition(short x){turtleXPosition = x;}
    void setYPosition(short y){turtleYPosition = y;}
    void setDirection(short direction){turtleDirection = direction;}
    void setPenPosition(bool pen){penPosition = pen;}


private:
    bool penPosition;
    short turtleXPosition, turtleYPosition;
    short int turtleDirection;
    short canvas[20][20];
};
