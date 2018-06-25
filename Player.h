
#ifndef MTM_EX5_WORLD_OF_HOMEWORK_PLAYER_H
#define MTM_EX5_WORLD_OF_HOMEWORK_PLAYER_H

#include "Weapon.h"
#include <iostream>
using std::ostream;
using std::string;

//-----------------------------------------------------------------------//
//                          CLASS PLAYER:                                //
//-----------------------------------------------------------------------//

class Player {
    string name;
    int level;
    int strength;

protected:
    int life;
    int position;
    Weapon weapon;

    /** Returns true if *this can attack player. False otherwise. */
    virtual bool canAttack(const Player& player) const;

    /** Returns the distance between two players. */
    static int distance(const Player& player1 , const Player& player2 );

//-----------------------------------------------------------------------//
//                        PRIVATE METHODS:                               //
//-----------------------------------------------------------------------//
private:
/**
 * attack
 *
 * Attacks a given player.
 *
 * @param player - Player to attack.
 */
void attack(Player& player)const;

/**
 * hitLife
 *
 * Hits life of given player.
 *
 * @param player - Player taking the damage.
 */
void hitLife(Player& player)const;

/**
 * hitLevel
 *
 * Hits level of given player.
 *
 * @param player - Player taking the damage.
 */
void hitLevel(Player& player)const;

/**
 * hitStrength
 *
 * Hits strength of given player.
 *
 * @param player - Player taking the damage.
 */
void hitStrength(Player& player)const;

//-----------------------------------------------------------------------//
//                         PUBLIC METHODS:                               //
//-----------------------------------------------------------------------//

public:

/**
 * Default constructor
 */
Player() = default;

/**
 * Copy constructor
 *
 * @param player - Player to copy.
 */
Player(const Player& player) = default;

/**
 * Constructor
 *
 * @param name - Name of the player.
 * @param weapon - Weapon of the player.
 */
Player(const string name, const Weapon& weapon);

/**
 * Destructor
 *
 * Free all resources of given player.
 */
virtual ~Player() = default;

/**
 * Operator=
 *
 * @param player - Player to assign.
 *
 * @return
 * Reference to the player after assignment.
 */
Player& operator=(const Player& player) = default;

/**
 * nextLevel
 *
 * Increasing player's level by 1.
 *
 */
void nextLevel();

/**
 * isPlayer
 *
 * Checks if the player has the given name.
 *
 * @param playerName - Name to compare to.
 *
 * @return
 * True - Player's name is the given name.
 * False - Otherwise.
 */
bool isPlayer(const string playerName)const;

/**
 * makeStep
 *
 * Increasing player's position by 1.
 */
virtual void makeStep();

/**
 * addLife
 *
 * Increasing player's life by 1.
 */
virtual void addLife();

/**
 * addStrength
 *
 * Increasing player's strength by given amount.
 *
 * @param strengthToAdd - Amount to add to player's strength.
 */
void addStrength(int strengthToAdd);

/**
 * isAlive
 *
 * Checks if the player is alive.
 *
 * @return
 * True - Player is alive.
 * False - Player is dead.
 */
bool isAlive()const;

/**
 * weaponIsWeak
 *
 * Checks if player's weapon is weaker than given amount.
 *
 * @param weaponMinStrength - Amount.
 *
 * @return
 * True - Player's weapon is weaker than given amount.
 * False - Otherwise.
 */
bool weaponIsWeak(int weaponMinStrength)const;

/**
 * fight
 *
 * @param player - Player to fight against.
 *
 * @return
 * True - Fight succeeded.
 * False - Fight failed.
 */
bool fight(Player& player);

/**
 * operator<<
 *
 * @param os - Stream to concatenate to.
 * @param player - Player to print.
 *
 * @return
 * Stream of Player details.
 */
friend ostream& operator<<(ostream& os, const Player& player);

/**
 * operator<
 *
 * @param player1 - First player.
 * @param player2 - Second player.
 *
 * @return
 * True - player1<player2
 * False - Otherwise.
 */
friend bool operator<(const Player& player1,const Player& player2);

/**
 * operator>
 *
 * @param player1 - First player.
 * @param player2 - Second player.
 *
 * @return
 * True - player1>player2
 * False - Otherwise.
 */
friend bool operator>(const Player& player1,const Player& player2);

/**
 * operator==
 *
 * @param player1 - First player to compare.
 * @param player2 - Second player to compare.
 *
 * @return
 * True - Players are equal (by comparing their names).
 * False - Otherwise.
 */
friend bool operator==(const Player& player1, const Player& player2);

/** Returns the position of a player. */
    int getPosition() const;
};

#endif //MTM_EX5_WORLD_OF_HOMEWORK_PLAYER_H
