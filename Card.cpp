#include <iostream>
#include "Card.h"
using namespace std;
#include <string>
//empty constructor
Card::Card(){}
//constructor with parameter
Card::Card(char r, char s)
{
    rank = r;
    suit = s;
}
//displays the card
void Card::display()
{
    if(rank == 'T')
    {
      cout << "" << "10" << "" << suit << "";
    }
    else
    {
      cout << "" << rank << "" << suit << "";
    }                 
}
//gets the value of the card
int Card::getValue()
{
    int value;
    if(rank == 'A')
      value = 1;
    else if(rank == 'T' || rank == 'J' || rank == 'Q' || rank == 'K')
      value = 10;
    else
      value = rank - '0';
    return value;
}
