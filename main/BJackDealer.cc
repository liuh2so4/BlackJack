/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     BJackDealer.cc
   PURPOSE
     
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct 12, 1998: Created.
***************************************************************************/

/* $Log:$ */

extern "C" {
#include <stdio.h>
#include <stdlib.h>
}

using namespace std;
#include <assert.h>
#include <iostream>
#include "AnsiPrint.h"
#include "Card.h"
#include "BJackPlayer.h"
#include "BJackDealer.h"

// constructor 
// nDeck is the number of standard decks that the dealer will deal with

/* 
 * revise the initialization list from an object oriented to just call function
 */  
BJackDealer::BJackDealer(int nSet): BJackPlayer("Dealer") {

    assert(nSet>0);
    cardLeft=nTotalCards=kMaxNCards*nSet;
    cardsDealt = new bool[nTotalCards];
    for(int i=0;i<nTotalCards;i++) 
        cardsDealt[i]=false;
    
}

// distribute a card to the player
int
BJackDealer::giveCard() {

    assert(cardLeft>0);
    int newCard;
    
    while(true) {
	if (!cardsDealt[newCard=rand()%nTotalCards]) {
	    cardsDealt[newCard]=true;
	    cardLeft--;
	    return newCard%kMaxNCards;
	}
    }
    
}

// give the dealer as many cards as necessary to exceed the player 
// of the given total points
// A special case happen when both of them have 21 points.
// It is a tie game and therefore the dealer does not get more cards.

/* 
 * revise the totalPoints & addCard function from an object oriented to just call function
 */  
void
BJackDealer::addCards(int oppTotal) {

  if (oppTotal > 21) 
    oppTotal=16;
  while (BJackPlayer::totalPoints() <= oppTotal) {
    // special case where both have 21 points
    // in this case, the dealer doesn't need to get more cards
    if ((oppTotal==21) && (BJackPlayer::totalPoints()==oppTotal))
	break;
	BJackPlayer::addCard(giveCard());
  }

}

// Determine who has win the game.
// The total points that the dealer has should be greater than 
// the player at the point this function is called.

/* 
 * revise the totalPoints function from an object oriented to just call function
 */  
result
BJackDealer::judge(int oppTotal) const {

    int myTotal = BJackPlayer::totalPoints();

    if (((oppTotal > 21) && (myTotal > 21)) || 
	((oppTotal == 21) && (myTotal == 21))) {
	return tie;
    } else if (oppTotal > 21) {
      return lose;
    } else if (myTotal > 21) {
      return win;
    } 
    return lose;

}

// start a new game
// before starting a new game, check if there are enough cards left for 
// the next game.

/*
 * we still need start class function in BJackDealer because it does 
 * different thing compare with the start class function in BJackPlayer
 * this start class function has to shuffle if it is needed
 */
void
BJackDealer::start(void) {

    if (cardLeft <= 17*(nTotalCards/kMaxNCards)) {
	shuffle();
    }
	// revise dealer.start(); to BJackPlayer::start();
	BJackPlayer::start();

}

void 
BJackDealer::shuffle(void) {

    for(int i=0;i<nTotalCards;i++) 
        cardsDealt[i]=false;
    cardLeft = nTotalCards;

}

void
BJackDealer::shuffle(long seed) {

    srand(seed);
    shuffle();

}

/*
 * revise it to now we don't need to use openFirstCard, addCard, showCards class function in BJackDealer
 * because BJackDealer do inheritance
 */

/*
void 
BJackDealer::openFirstCard(void) {

    dealer.openFirstCard();

}

void 
BJackDealer::addCard() {

	dealer.addCard(giveCard());

}

void 
BJackDealer::showCards(void) const {

    dealer.showCards();

}
*/

