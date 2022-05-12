//
// Created by michalmaya on 10/05/2022.
//

#include "Player.h"
#include "utilities.h"

Player::Player(String& name, int maxHP, int force) {
    Player::m_name = name;
    Player::m_level = 1;
    Player::m_force = force;
    Player::m_maxHP = maxHP;
    Player::m_HP = maxHP;
    Player::m_coins = 0;
}

void Player::printInfo() {
    printPlayerInfo(m_name.c_str(),m_level,m_force,m_HP,m_coins);
}

void Player::levelUp() {
    if (m_level < 10) {
        m_level++;
    }
}

int Player::getLevel() const {
    return m_level;
}

void Player::buff(int amount) {
    m_force += amount;
}

void Player::heal(int amount) {
    if(m_HP + amount >= m_maxHP)
    {
        m_HP = m_maxHP;
        return;
    }
    m_HP += amount;
}

void Player::damage(int amount) {
    if (m_HP > amount) {
        m_HP -= amount;
    }
    m_HP = 0;
}

bool Player::isKnockedOut() const{
    return m_HP == 0;
}

void Player::addCoins(int amount) {
    m_coins += amount;
}

bool Player::pay(int amount) {
    if(m_coins - amount < 0)
        return false;
    m_coins -= amount;
    return true;
}

int Player::getAttackStrength() const{
    return (m_force + m_level);
}
