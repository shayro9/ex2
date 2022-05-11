//
// Created by michalmaya on 11/05/2022.
//

#include "Card.h"

Card::Card(CardType type, const CardStats& stats) : m_effect(type), m_stats(CardStats
    (stats.force,stats.hpLossOnDefeat, stats.cost, stats.heal, stats.buff, stats.loot))
{}

void Card:: applyEncounter(Player& player) const{
    if (m_effect== CardType::Battle){
        bool win = false;
        if (player.getAttackStrength() >= m_stats.force){
            win = true;
            player.levelUp();
            player.addCoins(m_stats.loot);

        }
        else{
            player.damage(m_stats.hpLossOnDefeat);
        }
        printBattleResult(win);
    }
    if (m_effect== CardType::Treasure){
        player.addCoins(m_stats.loot);
    }
    else{
        if (player.pay(m_stats.cost)){
            if(m_effect== CardType::Heal){
                player.heal(m_stats.heal);
            }
            else{
                player.buff(m_stats.buff);
            }
        }
    }
}



void Card:: printInfo() const{
    if (m_effect== CardType::Battle){
        printBattleCardInfo(this->m_stats);
    }
    if (m_effect== CardType::Treasure){
        printTreasureCardInfo(this->m_stats);
    }
    if (m_effect== CardType::Buff){
        printBuffCardInfo(this->m_stats);
    }
    if (m_effect== CardType::Heal){
        printHealCardInfo(this->m_stats);
    }
}