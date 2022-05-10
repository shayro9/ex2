//
// Created by michalmaya on 10/05/2022.
//

#include "Player.h"
#include "utilities.h"

Player::Player(char *name, int maxHP, int force) {
    Player::name = name;
    Player::level = 1;
    Player::force = force;
    Player::maxHP = maxHP;
    Player::HP = maxHP;
    Player::coins = 0;
}

Player::Player(const Player &player) :
    name(new char[strlen(player.name)]),
    level(player.level),
    force(player.force),
    maxHP(player.maxHP),
    HP(player.HP),
    coins(player.coins)
{
    for (int i = 0; i < strlen((player.name)); ++i) {
        name[i] = player.name[i];
    }
}

void Player::printInfo() {
    printPlayerInfo(name,level,force,HP,coins);
}

int Player::getLevel() const {
    return level;
}

void Player::heal(int amount) {
    if(HP + amount >= maxHP)
    {
        HP = maxHP;
        return;
    }
    HP += amount;
}

bool Player::isKnockedOut() const{
    return HP == 0;
}

bool Player::pay(int amount) {
    if(coins - amount < 0)
        return false;
    coins -= amount;
    return true;
}
