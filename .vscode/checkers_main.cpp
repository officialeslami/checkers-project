#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <vector>
// white : $ black : #
using namespace std;
// size of the board
const int boardSize = 8;
// if it become true the game will be finished
bool exitState = false;

class Bead
{
public:
    int x, y;
    bool isKing = false;
    Bead(int, int, bool);
};
// based on details of every cells of board
Bead::Bead(int inputx, int inputy, bool inputIsKing)
{
    x = inputx;
    y = inputy;
    isKing = inputIsKing;
}
// (other functions)
int getExistBeadIndex(vector<Bead> beads, int x, int y);
void printBoard(vector<Bead> whiteBeads, vector<Bead> blackBeads);
void addAllBeads(vector<Bead> *, vector<Bead> *);
int getWordNumber(char *);
int getWordNumber(char word);
void getInputPositionFromUser(int *x, int *y, int status);

int main()
{
    // make the basic form of the game board with its beads
    vector<Bead> whiteBeads, blackBeads;
    addAllBeads(&whiteBeads, &blackBeads);
    printBoard(whiteBeads, blackBeads);

    string turn = "white";
    // start of the game
    while (!exitState)
    {
        // white's turn
        if (turn == "white")
        {
            cout << "(White's turn!)" << endl;

            // get the input of position for define the bead.
            int beadPositionX, beadPositionY;
            bool beadExist = false;
            while (!beadExist)
            {
                getInputPositionFromUser(&beadPositionX, &beadPositionY, 1);
                cout << "the position has been gotten (" << beadPositionX << " " << beadPositionY << endl;
                int beadIndex = getExistBeadIndex(whiteBeads, beadPositionX, beadPositionY);
                // check if there is any white bead in that position
                if (beadIndex < 0)
                {
                    cout << "There isn't any white bead in that position!" << endl;
                }
                else
                    beadExist = true;
            }

        }

        // black's turn
        else if (turn == "black")
            cout << "(Black's turn!)" << endl;
            int beadPositionX, beadPositionY;
            bool beadExist = false;
            while (!beadExist)
            {
                getInputPositionFromUser(&beadPositionX, &beadPositionY, 1);
                cout << "the position has been gotten (" << beadPositionX << " " << beadPositionY << endl;
                int beadIndex = getExistBeadIndex(blackBeads, beadPositionX, beadPositionY);
                // check if there is any black bead in that position
                if (beadIndex < 0)
                {
                    cout << "There isn't any black bead in that position!" << endl;
                }
                else
                    beadExist = true;
            }

        cout << "End!";
        break;
    }
}

void printBoard(vector<Bead> whiteBeads, vector<Bead> blackBeads)
{
    // based for saving the index of the bead that is in that special cell
    int existWhiteIndex, existBlackIndex;
    cout << "    a   b   c   d   e   f   g   h" << endl;
    for (int j = 1; j <= boardSize; j++)
    {
        cout << "  +---+---+---+---+---+---+---+---+" << endl;
        cout << j << " |";
        for (int i = 1; i <= boardSize; i++)
        {
            existWhiteIndex = getExistBeadIndex(whiteBeads, i, j);
            if (existWhiteIndex < 0)
                existBlackIndex = getExistBeadIndex(blackBeads, i, j);
            else
                existBlackIndex = -1;
            // *if there is any white bead in this cell of the board*
            if (existWhiteIndex >= 0)
            {
                // this isn't a king bead
                if (!whiteBeads.at(existWhiteIndex).isKing)
                {
                    cout << " $ ";
                }
                // this is a king bead
                else
                {
                    cout << " $*";
                }
            }
            // *if there is any black bead in this cell of the board*
            else if (existBlackIndex >= 0)
            {
                // this isn't a king bead
                if (!blackBeads.at(existBlackIndex).isKing)
                {
                    cout << " # ";
                }
                // this is a king bead
                else
                {
                    cout << " #*";
                }
            }
            // *if there isn't any bead in this cell of the board
            else
            {
                cout << "   ";
            }
            cout << "|";
        }
        cout << endl;
    }
    cout << "  +---+---+---+---+---+---+---+---+" << endl;
}
int getExistBeadIndex(vector<Bead> beads, int x, int y)
{
    int result = -1;
    for (int i = 0; i < beads.size(); i++)
    {
        if ((beads.at(i).x == x) && (beads.at(i).y == y))
        {
            result = i;
            break;
        }
    }
    // if(result>=0)cout<<"a Bead found at "<<result<<endl;
    return result;
}
void addAllBeads(vector<Bead> *whiteBeads, vector<Bead> *blackBeads)
{
    int y = 1;
    for (int x = 2; x <= boardSize; x += 2)
    {
        Bead bead(x, y, false);
        (*whiteBeads).push_back(bead);
    }
    y = 2;
    for (int x = 1; x <= boardSize; x += 2)
    {
        Bead bead(x, y, false);
        (*whiteBeads).push_back(bead);
    }
    y = 3;
    for (int x = 2; x <= boardSize; x += 2)
    {
        Bead bead(x, y, false);
        (*whiteBeads).push_back(bead);
    }
    y = 6;
    for (int x = 1; x <= boardSize; x += 2)
    {
        Bead bead(x, y, false);
        (*blackBeads).push_back(bead);
    }
    y = 7;
    for (int x = 2; x <= boardSize; x += 2)
    {
        Bead bead(x, y, false);
        (*blackBeads).push_back(bead);
    }
    y = 8;
    for (int x = 1; x <= boardSize; x += 2)
    {
        Bead bead(x, y, false);
        (*blackBeads).push_back(bead);
    }
}
int getWordNumber(char word)
{
    int number;
    word = tolower(word);
    switch (word)
    {
    case 'a':
        number = 1;
        break;
    case 'b':
        number = 2;
        break;
    case 'c':
        number = 3;
        break;
    case 'd':
        number = 4;
        break;
    case 'e':
        number = 5;
        break;
    case 'f':
        number = 6;
        break;
    case 'g':
        number = 7;
        break;
    case 'h':
        number = 8;
        break;

    default:
        number = -1;
        break;
    }
    return number;
}
void getInputPositionFromUser(int *x, int *y, int status)
{
    // status 1: for choosing the bead
    // status 2: for get position to move
    char inputPlace;
    bool correctInputX = false;
    while (!correctInputX)
    {
        if (status == 1)
            cout << "Define the position of bead which you want to move." << endl
                 << "put a word from a to h : ";
        else
            cout << "Define the position to move the bead." << endl
                 << "put a word from a to h : ";
        cin >> inputPlace;
        *x = getWordNumber(inputPlace);
        // if the y input is correct it will get x input
        if (*x > 0)
        {
            cout << *x << endl;
            bool correctInputY = false;
            while (!correctInputY)
            {
                cout << "put a number from 1 to 8 : ";
                cin >> *y;
                if (*y < 1 || *y > 8)
                {
                    cout << "Your input isn't correct!" << endl;
                    continue;
                }
                else
                {
                    correctInputY = true;
                    correctInputX = true;
                }
            }
        }
        else
        {
            cout << "Your input isn't correct!" << endl;
            continue;
        }
    }
}