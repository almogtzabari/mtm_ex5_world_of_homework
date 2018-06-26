
#ifndef MTM_EX5_WORLD_OF_HOMEWORK_GAME_H
#define MTM_EX5_WORLD_OF_HOMEWORK_GAME_H

#include "Player.h"
#include "Warrior.h"
#include "Wizard.h"
#include "Troll.h"
#include <vector>
using std::vector;

enum GameStatus
{
    INVALID_PARAM,
    NAME_ALREADY_EXISTS,
    GAME_FULL,
    NAME_DOES_NOT_EXIST,
    FIGHT_FAILED,
    SUCCESS
};

#define INDEX_NOT_FOUND -1

//-----------------------------------------------------------------------//
//                          CLASS GAME:                                  //
//-----------------------------------------------------------------------//

class Game {
    int max_players;
    vector<Player*> players_vector;


//-----------------------------------------------------------------------//
//                        PRIVATE METHODS:                               //
//-----------------------------------------------------------------------//

/**
 * isFull
 *
 * @return
 * True - Game is full.
 * False - Game is not full.
*/
bool isFull()const;

/**
 * playerExist
 *
 * @param player_name - Name of the player to check if exists.
 *
 * @return
 * True - Player with given name exists.
 * False - Player with given name does not exists.
 */
bool playerExist(const string& player_name)const;

/**
 * removePlayer
 *
 * Removing player from the game.
 *
 * @param player -  Player to remove.
 */
void removePlayer(const Player& player);

/**
 * getPlayerIndexByName
 *
 * @param playerName - Name of the player to get its index.
 *
 * @return
 * Index of the player with the given name.
 * If not found returns -1.
 */
int getPlayerIndexByName(const string& playerName)const;

/**
 * swap
 *
 * Swaping to players.
 *
 * @param player1_ptr - Pointer of first player.
 * @param player2_ptr - Pointer of second player.
 */
void swap(Player* player1_ptr, Player* player2_ptr);

/**
 * sortPlayers
 *
 * Sorting (bubble sort) players array (only the real players) by name.
 */
void sortPlayers();

//-----------------------------------------------------------------------//
//                         PUBLIC METHODS:                               //
//-----------------------------------------------------------------------//

public:

/**
 * Constructor
 *
 * @param maxPlayer - Max player of the game.
 */
Game(int maxPlayer);

/**
 * Destructor
 */
~Game();

/**
 * addPlayer - OLD FUNCTION
 *
 * Adding an unmounted warrior to the game.
 *
 * @param playerName - Warrior's name.
 * @param weaponName - Warrior's weapon name.
 * @param target - Warrior's weapon target.
 * @param hit_strength - Warrior's weapon hit strength.
 *
 * @return
 * GAME_FULL - Game is full.
 * NAME_ALREADY_EXISTS - Player with that name already exists.
 * SUCCESS - Player added successfully.
 *
 */
GameStatus addPlayer(const string& playerName,const string& weaponName,
Target target,int hit_strength);

/**
 * addWizard
 *
 * Adding a wizard to the game.
 *
 * @param playerName - Wizard's name.
 * @param weaponName - Wizard's weapon name.
 * @param target - Wizard's weapon target.
 * @param hitStrength - Wizard's weapon hit Strength.
 * @param range - Wizard's range.
 */
void addWizard(string const& playerName, string const& weaponName,
                   Target target, int hitStrength, int range);

/**
 * addTroll
 *
 * Adding a troll to the game.
 *
 * @param playerName - Troll's name.
 * @param weaponName - Troll's weapon name.
 * @param target - Troll's weapon target.
 * @param hitStrength - Troll's weapon hit strength.
 * @param maxLife - Troll's max life.
 */
void addTroll(string const& playerName, string const& weaponName,
              Target target, int hitStrength, int maxLife);


/**
 * addWarrior
 *
 * Adding a warrior to the game.
 *
 * @param playerName - Warrior's name.
 * @param weaponName - Warrior's weapon name.
 * @param target - Warrior's weapon target.
 * @param hitStrength - Warrior's weapon hit strength.
 * @param rider - Mounted or not.
 */
void addWarrior(string const& playerName, string const& weaponName,
                    Target target, int hitStrength, bool rider);


/**
 * nextLevel
 *
 * Increasing the level of player with given name by 1.
 *
 * @param playerName - Name of player to increase its level.
 *
 * @return
 * NAME_DOES_NOT_EXIST - Player with given name does not exist.
 * SUCCESS - Player's level increased successfully.
 */
GameStatus nextLevel(const string& playerName);

/**
 * makeStep
 *
 * Increasing position of player with given name by 1.
 *
 * @param playerName - Name of the player to increase its position.
 *
 * @return
 * NAME_DOES_NOT_EXIST - Player with given name does not exist.
 * SUCCESS - Player's position increased successfully.
 */
GameStatus makeStep(const string& playerName);

/**
 * addLife
 *
 * Increasing life of player with given name by 1.
 *
 * @param playerName - Name of the player to increase its life.
 *
 * @return
 * NAME_DOES_NOT_EXIST - Player with given name does not exist.
 * SUCCESS - Player's life increased successfully.
 */
GameStatus addLife(const string& playerName);

/**
 * addStrength
 *
 * Increasing strength of player with given name by given amount.
 *
 * @param playerName - Name of the player to increase its strength.
 * @param strengthToAdd - Amount to increase.
 *
 * @return
 * INVALID_PARAM - Given amount is a negative number.
 * NAME_DOES_NOT_EXIST - Player with given name does not exist.
 * SUCCESS - Player's strength increased successfully.
 */
GameStatus addStrength(const string& playerName, int strengthToAdd);

/**
 * removeAllPlayersWithWeakWeapon
 *
 * Removes all players with weapon weaker than given amount.
 *
 * @param weaponStrength - Amount.
 *
 * @return
 * True - Players removed.
 * False - Players not removed.
 */
bool removeAllPlayersWithWeakWeapon (int weaponStrength);

/**
 * fight
 *
 * Managing a fight between two players.
 *
 * @param playerName1 - First player in the fight.
 * @param playerName2 - Second player in the fight.
 *
 * @return
 * NAME_DOES_NOT_EXIST - At least one of the given names does not match any
 * player.
 */
GameStatus fight(const string& playerName1, const string& playerName2);

/**
 * operator<<
 *
 * @param os - Stream to concatenate to.
 * @param game - Game to print its details.
 *
 * @return
 * Stream of game details.
 */
friend ostream& operator<<(ostream& os, Game& game);

/**
 * This template function will activate operator() on all the players in
 * the players vector and will remove all players that returned true.
 * @tparam FCN - A given function or functor.
 * @param fcn - A given function or functor.
 * @return
 * True if at least 1 player was removed, else false.
 */
template <class FCN>
bool removePlayersIf(FCN& fcn){
    int counter=0;
    for(int i=0; i<players_vector.size(); i++){
        if(fcn(static_cast<const Player&>(*players_vector[i]))){
            removePlayer(*players_vector[i--]);
            counter++;
        }
    }
    return counter>0;
}

/**
 * weakerThan
 */
class weakerThan{
    int val;
    public:
    explicit weakerThan(int val): val(val){};
    bool operator()(const Player& player){
        return player.weaponIsWeak(val);
    }
};

};

#endif //MTM_EX5_WORLD_OF_HOMEWORK_GAME_H
