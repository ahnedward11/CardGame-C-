//Edward Ahn
//CECS 282-04
//Prog 1-Solitaire Prime
//9/9/20

#include <iostream>
using namespace std;
#include "deck.h"
#include "Card.h"
//menu function for the program
void menu(){
    cout << "" << endl;
    cout << "Welcome to Solitaire Prime!" << endl;
    cout << "1) New Deck" << endl;
    cout << "2) Display Deck" << endl;
    cout << "3) Shuffle Deck" << endl;
    cout << "4) Play Solitaire Prime" << endl;
    cout << "5) Exit" << endl;
}
//runs the game returns if prime and winner and loser
bool playSolitairePrime(deck tester){
  int Count = 0;
  int total = 0;
  int isPrime = 1;
  cout << "Lets play Solitaire!" << endl;
  while(tester.cardsLeft() == true)
  {
    Card C = tester.deal();
    C.display();
    cout << ", ";
    total += C.getValue();
    for(int i = 2; i <= total/2; i++)
    {
      if(total % i == 0)
      {
        isPrime = 0;
        break;
      }
      else{
        cout << "Prime: " << total << endl;
        if(tester.cardsLeft() == true)
        {
          total = 0;
        }
        else
        {
          total = total;
          isPrime = 1;
          break;
        }
      }
      Count += 1;
    }
  }
  if(isPrime == 1)
  {
    cout << "Winner in " << Count << " piles!" << endl;
    return true;
  }
  else 
  {
    cout << "Loser" << endl;
  return false;
  }
}
//main function calls everything that is needed
int main()
{
  menu();
  deck tester = deck();
  int num;
  cin >> num;
  while (num < 1 || num > 6)
  {
    cout << "Please select an option between (1-6)" << endl;
    cin >> num;
  }
  while (num >= 1 && num <= 6)
    if(num == 1)
    {
      tester.refreshdeck();
      menu();
      cin >> num;
    }
    else if(num == 2)
    {
      tester.showdeck();
      menu();
      cin >> num;
    }
    else if(num == 3)
      {
        tester.shuffle();
        menu();
        cin >> num;
      } 
    else if(num == 4)
    {
      playSolitairePrime(tester);
      menu();
      cin >> num;
    }
    else if(num == 5)
    {
      cout << "Bye!" << endl;
    }
  return 0;
}