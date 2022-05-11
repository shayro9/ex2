//
// Created by michalmaya on 10/05/2022.
//

#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H


#include "string.h"
#include "utilities.h"

class Player {
public:
    explicit Player (char* name, int maxHP=100, int force=5);
    ~Player ();
    Player (const Player& player);
    Player& operator= (const Player& other);
    void printInfo();
    void levelUp();
    int getLevel() const;
    void buff(int amount);
    void heal(int amount);
    void damage(int amount);
    bool isKnockedOut() const;
    void addCoins (int amount);
    bool pay (int amount);
    int getAttackStrength () const;



private:
    char* name;
    int level;
    int force;
    int maxHP;
    int HP;
    int coins;

};

#endif //EX2_Player_H