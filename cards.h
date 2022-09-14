// cards.h
#ifndef CARDS_H
#define CARDS_H

// types
typedef enum CardType{ATTACK, DEFEND, RUN} CardType;
typedef struct Card{
    CardType type;
    int value;
    struct Card* next;
}Card;

// proptotypes for required functions
Card* createCard(); 
Card* removeCard(Card* head);
Card* addCard(Card* head, Card* card);
int getLength(Card* head);
void printCard(Card* card);
void printCards(Card* head);
Card* buildCards(int n);
Card* destroyCards(Card* card);

#endif