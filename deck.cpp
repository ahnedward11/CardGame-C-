#include <iostream>
#include "Card.h"
#include "deck.h"
using namespace std;
#include <string>
//constructor for deck
deck::deck()
{
  char suits [] = {'H', 'D', 'S', 'C'};
  char ranks [] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
  top = 0;
  int count =0;
  Card C1;
  for(int s = 0; s < sizeof(suits)/sizeof(suits[0]); s++)
  {
    for(int r = 0; r < sizeof(ranks)/sizeof(ranks[0]); r++)
      {
        storage[count++] = Card(ranks[r],suits[s]);      
      }
  } 
}
//makes a new deck
void deck::refreshdeck()
{
  char suits [] = {'H', 'D', 'S', 'C'};
  char ranks [] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
  int count = 0;
  for(int s = 0; s < sizeof(suits)/sizeof(suits[0]); s++)
  {
    for(int r = 0; r < sizeof(ranks)/sizeof(ranks[0]); r++)
      {
        storage[count++] = Card(ranks[r],suits[s]);
      }
  } 
}
//deals the card from the first card
Card deck::deal()
{
  return storage[top++];
}
//shuffles the whole deck
void deck::shuffle()
{
  srand(time(0));
  for(int i = 0; i < 100; i++)
  {
    int swap = rand()%52;
    int swap2 = rand()%52;
    Card temp = storage[swap];
    storage[swap] = storage[swap2];
    storage[swap2] = temp;
  }
}
//returns if there are cards left or not
bool deck::cardsLeft()
{
  if(51 - top > 0)
    return true;
  else
    return false;
}
//displays the deck neatly
void deck::showdeck()
{
  for(int i = 0; i < sizeof(storage)/sizeof(storage[0]);i++ )
  {
    if((i == 13) || (i == 26) || (i==39))
    {
      cout << "" << endl;
    }
    storage[i].display();
    cout << " ";
  }
}