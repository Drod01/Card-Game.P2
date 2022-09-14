// cards.c
#include <stdio.h>
#include <stdlib.h>
#include "cards.h"


Card* createCard(){
    // dynamically allocate new Card
    Card* card = (Card*) malloc(sizeof(Card));
    // check if memory allocation was successful
    
    if (card == NULL)   exit (EXIT_FAILURE);
    // generate a random number in range (1, 100)
    
    int number = (1 + rand() % 100);
    // take decision based on number
    
    if (number <= 40) {
        // 40% chances of being ATTACK
        card->type = ATTACK;
        // value is random number between [1, 5]
        card->value = 1 + rand() % 5;
    } else if (number <= 90) {
        // 50% chances of being DEFEND
        card->type = DEFEND;
        // value is a random number between [3, 8]
        card->value = 3 + rand() % 6;
    } else {
        // 10% chances of being RUN
        card->type = RUN;
        // value is a random number between [1, 8]
        card->value = 1 + rand() % 8;
    }
    
    card->next = NULL;
    
    return card;
}


Card* removeCard(Card* head) {
    
    if (head == NULL)   return head;
    
    Card* newHead = head->next;
    
    free (head);
    
    return newHead;
}


Card* addCard(Card* head, Card* card){
    
    if (head == NULL)   return card;
    if (card == NULL)   return head;
    
    if (card->value > head->value) {
        
        card->next = head;
        
        return card;
    }
    
    Card* prevCard = NULL;
    Card* tempCard = head;
    while (tempCard != NULL && tempCard->value >= card->value) {
        prevCard = tempCard;
        tempCard = tempCard->next;
    }
   
    card->next = tempCard;
    prevCard->next = card;
    
    return head;
}


int getLength(Card* head) { 
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

 
void printCard(Card* card) {
    if (card != NULL) {
        char type = 'A';
        if (card->type == DEFEND)   type = 'D';
        else if (card->type == RUN) type = 'R';
        printf ("%c%d ", type, card->value);
    }
}


void printCards(Card* head) {
    
    Card* tempCard = head;
    while (tempCard != NULL) {
        
        printCard(tempCard);
        
        tempCard = tempCard->next;
    }
}


Card* buildCards(int n){
    
    Card* head = NULL;
    
    for (int i = 0; i < n; ++i) {
        
        Card* card = createCard();
        
        head = addCard(head, card);
    }
    
    return head;
}



Card* destroyCards(Card* head) {
    
    do {
        
        head = removeCard(head);
    } while (head != NULL);
    // return null always
    return NULL;
}