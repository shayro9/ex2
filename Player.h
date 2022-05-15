//
// Created by michalmaya on 10/05/2022.
//

#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H


#include "string"
#include "utilities.h"
typedef std::string String;

class Player {
public:
    explicit Player (const char* name, int maxHP=100, int force=5);
    ~Player () = default;
    Player (const Player& player) = default;
    Player& operator= (const Player& other) = default;
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
    String m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;

};

#endif //EX2_Player_H