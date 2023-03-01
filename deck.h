#ifndef deck_H
#define deck_H
#include <string>
#include "Card.h"
using namespace std;

class deck
{
  private:
    Card storage[52];
    int top;
  public:
    deck();
    void refreshdeck();
    Card deal();
    void shuffle();
    bool cardsLeft();
    void showdeck();
};

#endif