
//start of DICEGAME_H
#ifndef DICEGAME_H

#define DICEGAME_H

typedef enum ROUNDTYPE { BONUS, DOUBLE, REGULAR } ROUNDTYPE;

typedef struct DiceRound

{

  	int dice;
  
  	int points;
  
  	ROUNDTYPE type;


}DiceRound;

  	int getRandomNumber(int min, int max);
  
  	void fillRounds(DiceRound *rounds, int size);
  
  	int getRoundPoints(DiceRound dice);
  
  	void printRoundInfo(DiceRound dice);
  
  	void printPlayerInfo(int p1, int p2);

	#endif // DICEGAME_H // end of dice game



//start of dicegame.h;enum

#include "dicegame.h"

#include <stdio.h>

#include <stdlib.h>
		
//declaration of variables

	  int getRandomNumber(int min, int max)

{

  	return rand()%(max-min+1)+min;

}

  	void fillRounds(DiceRound *rounds, int size)

{

  	int i;
  
  
  
  	for(i=0;i<size;i++)

{

  	rounds[i].dice = getRandomNumber(1,6);

	  rounds[i].points = getRandomNumber(1,10)*10;
   //random number
	  int n = getRandomNumber(1,10); 



		if(n <= 2)

	  rounds[i].type = BONUS;

	  else if(n <= 4)

  	rounds[i].type = DOUBLE;

	  else

	  rounds[i].type = REGULAR;

}

}

	  int getRoundPoints(DiceRound round)

{

	  if(round.type == BONUS) 

	  return 100;

	  else if(round.type == DOUBLE)

  	return 2*round.points;

 	  else 

	  return round.points;

}

    void printRoundInfo(DiceRound round)

{

	  printf("\nType: ");

	  if(round.type == BONUS)

	  printf("BONUS");

	  else if(round.type == REGULAR)

	  printf("REGULAR");

	  else

	  printf("DOUBLE");

	  printf("\nDICE: %d",round.dice);

	  printf("\nPOINTS: %d\n",round.points);

}

	//interger paramerters

	  void printPlayerInfo(int p1, int p2)

{

	  printf("\nP-1 : %d",p1);

	  printf("\nP-2 : %d\n",p2);

}

  //end of dicegame.h

  // start of main.c

#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#include "dicegame.h"

  int main(int argc, char* argv[])

{

	  srand(time(NULL));

	  int p1= 0, p2 = 0;

	  int nRounds, curPlayer;

	  DiceRound* rounds = NULL;

	  //user number
	  printf("Enter the number of rounds you want to play: ");

	  scanf("%d",&nRounds);

	  //user input

	  rounds = (DiceRound*)malloc(sizeof(DiceRound)*nRounds);

	

	  if(rounds == NULL)

{

	  return 1;

}

	  curPlayer = getRandomNumber(1,2);

	  fillRounds(rounds, nRounds);

	  printPlayerInfo(p1,p2);

	  for(int i=0;i<nRounds;i++)

{

	  printf("\nROUND %d\n--------\n", i+1);

	  printf("Player\t: %d\n", curPlayer); // Print current player


	  //information for round

	  printRoundInfo(rounds[i]);


	  //game logic

	  if(curPlayer == 1 )

{

	  if(rounds[i].dice%2 == 0 )

	  p1 += getRoundPoints(rounds[i]);

	  else

{

	  p1 -= getRoundPoints(rounds[i]);

	  curPlayer = 2;

}

}

	  else

{



	  if(rounds[i].dice%2 != 0)

	  p2 += getRoundPoints(rounds[i]);

	  else

{

	  p2 -= getRoundPoints(rounds[i]);

	  curPlayer = 1;

}

}



	  printPlayerInfo(p1,p2);

}

	  printf("\nGAME OVER!!\n");


	  if(p1 > p2)

	  printf("Player 1 is the WINNER!!!!");

	  else ifp1 < p2)

	  printf("Player 2 is the WINNER!!!!");

	  else

  	printf("The game ended in a TIE!!!");
  
  
  	free(rounds);
  
  	rounds = NULL;
  
  	return 0;

	}


}

