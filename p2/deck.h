/*
Algorithms 9/28/18
Project #2 Part A deck.h file
Flipcard Game
Rebekah Davis and Andrea Matellian
Group ID: DAVMAT
*/
#include "card.h"
#include <cstdlib>
#include <stdlib.h>
#include <random>

using namespace std;

#ifndef DECK_H
#define DECK_H
class deck
{
    public:
      deck(); //constructor creates the empty linked list

      void swap(card *a, card *b);

      void shuffle();

      friend ostream& operator<< (ostream &ostr, const deck& d); //printDeck

      ~deck();

    private:
      node<card> *front;
      node<card> *current;
      node<card> *next;
};
#endif
// ***********************************************************
//      deck class implementation
// ***********************************************************
deck::deck()
{
  //create a deck of cards
  card first(1, "Clubs");
  front = new node<card>(first);

  for (int i = 2; i <= 13; i++)
  {
    card c(i, "Clubs");
    front = new node<card>(c, front);
  }

  for (int i = 1; i <= 13; i++)
  {
    card c(i, "Spades");
    front = new node<card>(c, front);
  }

  for (int i = 1; i <= 13; i++)
  {
    card c(i, "Hearts");
    front = new node<card>(c, front);
  }

  for (int i = 1; i <= 13; i++)
  {
    card c(i, "Diamonds");
    front = new node<card>(c, front);
  }
}

void deck::swap(card *a, card *b)
{
    card temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void deck::shuffle()
{
  node <card> *tmp1 = front;
  node <card> *tmp2;

  for(int i = 0; i < 26; i++)
  {
    int index = rand() % 52;
    for (int i = 0; i < index-1; i++)
    {
      tmp2 = current;
      swap(&tmp1->nodeValue, &tmp2->nodeValue);
    }
    current = current->next;
  }
}

ostream & operator<<(ostream & os, const deck & d)
{
  node <card> *current;
  node <card> *next;
  cout<<"here"<<endl;
  for(current = d.front; current != NULL; current = current->next)
  {
     os << current->nodeValue;
  }
  return os;
}

deck::~deck()
{
    cout << "Deck destroyed\n";
}
