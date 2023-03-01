#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

class Card
{
    private:
        char rank;
        char suit;
    public:
        Card();
        Card(char, char);
        void display();
        int getValue();      
};
#endif
