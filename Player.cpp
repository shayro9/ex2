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


Player::~Player (){
    delete[] name;
}


Player::Player(const Player &player) :
        name(new char[strlen(player.name)+1]),
        level(player.level),
        force(player.force),
        maxHP(player.maxHP),
        HP(player.HP),
        coins(player.coins)
{
    for (int i = 0; i < strlen(player.name); ++i) {
        name[i] = player.name[i];
    }
    name[strlen(player.name)] = 0;
}


Player& Player:: operator=(const Player& other) {
    if (this== &other){
        return *this;
    }
    delete[] name;
    name = new char[strlen(other.name)+1];
    for (int i = 0; i < strlen(other.name); ++i) {
        name[i] = other.name[i];
    }
    name[strlen(other.name)] = 0;
    level = other.level;
    force = other.force;
    maxHP = other.maxHP;
    HP = other.HP;
    coins = other.coins;
    return *this ;
}

void Player::printInfo() {
    printPlayerInfo(name,level,force,HP,coins);
}

void Player::levelUp() {
    if (level < 10) {
        level++;
    }
}

int Player::getLevel() const {
    return level;
}

void Player::buff(int amount) {
    force += amount;
}

void Player::heal(int amount) {
    if(HP + amount >= maxHP)
    {
        HP = maxHP;
        return;
    }
    HP += amount;
}

void Player::damage(int amount) {
    if (HP > amount) {
        HP -= amount;
    }
    HP = 0;
}

bool Player::isKnockedOut() const{
    return HP == 0;
}

void Player::addCoins(int amount) {
    coins += amount;
}

bool Player::pay(int amount) {
    if(coins - amount < 0)
        return false;
    coins -= amount;
    return true;
}

int Player::getAttackStrength() const{
    return (force + level);
}
