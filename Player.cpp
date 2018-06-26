
#include "Player.h"

/**
 * Constructor
 *
 * @param name - Name of the player.
 * @param weapon - Weapon of the player.
 */
Player::Player(const string name, const Weapon& weapon): name(name),
level(1),strength(1),life(1),position(0),weapon(weapon){
}

/**
 * operator<<
 *
 * @param os - Stream to concatenate to.
 * @param player - Player to print.
 *
 * @return
 * Stream of Player details.
 */
ostream& operator<<(ostream& os, const Player& player){
    return os << "{player name: " << player.name << "," <<" weapon: " <<
              player.weapon << "}";
}

/**
 * nextLevel
 *
 * Increasing player's level by 1.
 *
 */
void Player::nextLevel() {
    level++;
}

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
bool Player::isPlayer(const string playerName) const {
    return playerName==name;
}

/**
 * makeStep
 *
 * Increasing player's position by 1.
 */
void Player::makeStep() {
    position++;
}

/**
 * addLife
 *
 * Increasing player's life by 1.
 */
void Player::addLife() {
    life++;
}

/**
 * addStrength
 *
 * Increasing player's strength by given amount.
 *
 * @param strengthToAdd - Amount to add to player's strength.
 */
void Player::addStrength(int strengthToAdd) {
    strength+=strengthToAdd;
}

/**
 * isAlive
 *
 * Checks if the player is alive.
 *
 * @return
 * True - Player is alive.
 * False - Player is dead.
 */
bool Player::isAlive() const {
    if(strength<1||life<1||level<1){
        return false;
    }
    return true;
}

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
bool Player::weaponIsWeak(int weaponMinStrength)const {
    return (weapon.getValue()<weaponMinStrength);
}

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
bool operator<(const Player& player1,const Player& player2) {
    return player1.name<player2.name;
}

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
bool operator>(const Player& player1,const Player& player2){
    return player1.name>player2.name;
}

/**
 * fight
 *
 * @param player - Player to fight against.
 *
 * @return
 * True - Fight succeeded.
 * False - Fight failed.
 */
bool Player::fight(Player &player) {
    if(!this->canAttack(player)){
        /* Not in the same position or has same weapon value, therefore
         * shouldn't fight .*/
        if(!player.canAttack(*this)){
            return false;
        }
        player.attack(*this);
        return true;
    }
    /* Can attack. */
    this->attack(player);
    return true;
}

/**
 * attack
 *
 * Attacks a given player.
 *
 * @param player - Player to attack.
 */
void Player::attack(Player &player) const {
    switch(weapon.getTarget()) {
        case LEVEL : this->hitLevel(player);
            return;
        case LIFE : this->hitLife(player);
            return;
        case STRENGTH : this->hitStrength(player);
            return;
    }
}

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
bool operator==(const Player& player1, const Player& player2){
    return player1.isPlayer(player2.name);
}

/**
 * hitLife
 *
 * Hits life of given player.
 *
 * @param player - Player taking the damage.
 */
void Player::hitLife(Player& player)const {
    player.life-=weapon.getHitStrength();
    if(player.life<0){
        player.life=0;
    }
}

/**
 * hitLevel
 *
 * Hits level of given player.
 *
 * @param player - Player taking the damage.
 */
void Player::hitLevel(Player& player)const {
    player.level-=weapon.getHitStrength();
    if(player.level<0){
        player.level=0;
    }
}

/**
 * hitStrength
 *
 * Hits strength of given player.
 *
 * @param player - Player taking the damage.
 */
void Player::hitStrength(Player& player)const {
    player.strength-=weapon.getHitStrength();
    if(player.strength<0){
        player.strength=0;
    }
}

/**
 * canAttack
 * @param player - A player to attack.
 * @return
 * True if the player can attack, else false.
 */
bool Player::canAttack(const Player& player) const {
    return position==player.position && weapon>player.weapon;
}

/**
 * distance
 *
 * @param player1 - First player.
 * @param player2 - Second player.
 *
 * @return
 * Returns the distance between two players.
 */
int Player::distance(const Player &player1, const Player &player2) {
    int position1 = player1.position;
    int position2 = player2.position;
    return (position1-position2)*(position1>position2) +
           (position2-position1)*(position2>position1);
}

/** Returns the position of a player. */
int Player::getPosition() const{
    return position;
}