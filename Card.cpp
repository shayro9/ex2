//
// Created by michalmaya on 11/05/2022.
//

#include "Card.h"

Card::Card(CardType type, const CardStats& stats) : m_effect(type), m_stats(CardStats
    (stats.force,stats.hpLossOnDefeat, stats.cost, stats.heal, stats.buff, stats.loot))
{}

void Card:: applyEncounter(Player& player) const{
    bool win = false;
    switch (m_effect) {
        case CardType::Battle:
            if (player.getAttackStrength() >= m_stats.force){
                win = true;
                player.levelUp();
                player.addCoins(m_stats.loot);

            }
            else{
                player.damage(m_stats.hpLossOnDefeat);
            }
            printBattleResult(win);
            break;
        case CardType::Treasure:
            player.addCoins(m_stats.loot);
            break;
        case CardType::Heal:
            if (player.pay(m_stats.cost))
                player.heal(m_stats.heal);
            break;
        case CardType::Buff:
            if (player.pay(m_stats.cost))
                player.buff(m_stats.heal);
            break;
        default://should not get here;
            return;
    }
}



void Card:: printInfo() const{
    switch(m_effect)
    {
        case CardType::Battle:
            printBattleCardInfo(this->m_stats);
            break;
        case CardType::Treasure:
            printTreasureCardInfo(this->m_stats);
            break;
        case CardType::Buff:
            printBuffCardInfo(this->m_stats);
            break;
        case CardType::Heal:
            printHealCardInfo(this->m_stats);
            break;
    }
}