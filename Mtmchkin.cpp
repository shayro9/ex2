//
// Created by michalmaya on 13/05/2022.
//

#include "Mtmchkin.h"


Mtmchkin::Mtmchkin(const String& playerName, const Card *cardsArray, int numOfCards):
    m_player(playerName.c_str())
    {
    m_cardsArray= new Card[numOfCards];
    for (int i=0; i<numOfCards; i++){
        m_cardsArray[i] = cardsArray[i];
    }
    m_numOfCards = numOfCards;
    m_cardIndex = 0;
    m_status = GameStatus::MidGame;
}

Mtmchkin:: ~Mtmchkin(){
    delete[] m_cardsArray;
}

Mtmchkin:: Mtmchkin (const Mtmchkin& other) :
    m_player(other.m_player){
    m_cardsArray= new Card[other.m_numOfCards];
    for (int i=0; i<other.m_numOfCards; i++){
        m_cardsArray[i]= other.m_cardsArray[i];
    }
    m_numOfCards=other.m_numOfCards;
    m_cardIndex=other.m_cardIndex;
    m_status= other.m_status;
}

Mtmchkin& Mtmchkin:: operator=(const Mtmchkin& other){
    if (this== &other){
        return *this;
    }
    delete[] m_cardsArray;
    m_player = other.m_player;
    m_cardsArray= new Card[other.m_numOfCards];
    for (int i=0; i<other.m_numOfCards; i++){
        m_cardsArray[i]= other.m_cardsArray[i];
    }
    m_numOfCards=other.m_numOfCards;
    m_cardIndex=other.m_cardIndex;
    m_status= other.m_status;
    return *this;
}

void Mtmchkin:: playNextCard(){
    Card currentCard = m_cardsArray[m_cardIndex];
    currentCard.printInfo();
    currentCard.applyEncounter(m_player);
    setWinLose();
    m_player.printInfo();
    m_cardIndex++;
    if (m_cardIndex==m_numOfCards){
        m_cardIndex=0;
    }
}

bool Mtmchkin:: isOver() const{
    if (m_status != GameStatus::MidGame){
        return true;
    }
    return false;
}

GameStatus  Mtmchkin:: getGameStatus() const{
    return m_status;
}

void Mtmchkin::setWinLose(){
    if(m_player.getLevel() == 10)
    {
        m_status = GameStatus::Win;
    }
    if(m_player.isKnockedOut())
    {
        m_status = GameStatus::Loss;
    }
}
