

#include "Game.h"
using std::ostream;
using std::string;

/**
 * Constructor
 *
 * @param maxPlayer - Max player of the game.
 */
Game::Game(int maxPlayer) : max_players(maxPlayer),players_vector(0){} //todo: What if maxPlayer<0?

/**
 * Destructor
 */
Game::~Game() {
    for (int i=0;i<players_vector.size();i++) {
        delete players_vector[i];
    }
}

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
GameStatus Game::addPlayer(const string& playerName, const string& weaponName,
                           Target target, int hit_strength) {
    if(isFull()){
        return GAME_FULL;
    }
    if(playerExist(playerName)){
        return NAME_ALREADY_EXISTS;
    }
    Weapon weapon = Weapon(weaponName,target,hit_strength);
    try{
        Player* warrior_ptr = new Warrior(playerName,weapon,false);
        players_vector.push_back(warrior_ptr);
    }
    catch(mtm::IllegalWeapon& e){
        return ILLEGAL_WEAPON;
    }
    return SUCCESS;
}

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
void Game::addWizard(string const &playerName, string const &weaponName,
                     Target target, int hitStrength, int range) {
    if(isFull()){
        throw mtm::GameFull();
    }
    if(playerExist(playerName)){
        throw mtm::NameAlreadyExists();
    }
    Weapon weapon = Weapon(weaponName,target,hitStrength);
    Player* wizard_ptr = new Wizard(playerName,weapon,range);
    players_vector.push_back(wizard_ptr);
}

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
void Game::addTroll(string const &playerName, string const &weaponName,
                    Target target, int hitStrength, int maxLife) {
    if(isFull()){
        throw mtm::GameFull();
    }
    if(playerExist(playerName)){
        throw mtm::NameAlreadyExists();
    }
    Weapon weapon = Weapon(weaponName,target,hitStrength);
    Player* troll_ptr = new Troll(playerName,weapon,maxLife);
    players_vector.push_back(troll_ptr);
}

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
void Game::addWarrior(string const &playerName, string const &weaponName,
                      Target target, int hitStrength, bool rider) {
    if(isFull()){
        throw mtm::GameFull();
    }
    if(playerExist(playerName)){
        throw mtm::NameAlreadyExists();
    }
    Weapon weapon = Weapon(weaponName,target,hitStrength);
    Player* warrior_ptr = new Warrior(playerName,weapon,rider);
    players_vector.push_back(warrior_ptr);
}

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
GameStatus Game::nextLevel(const string& playerName) {
    int player_index = getPlayerIndexByName(playerName);
    if(player_index==INDEX_NOT_FOUND){
        return NAME_DOES_NOT_EXIST;
    }
    players_vector[player_index]->nextLevel();
    return SUCCESS;
}

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
GameStatus Game::makeStep(const string& playerName) {
    int player_index = getPlayerIndexByName(playerName);
    if(player_index==INDEX_NOT_FOUND){
        return NAME_DOES_NOT_EXIST;
    }
    players_vector[player_index]->makeStep();
    return SUCCESS;
}

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
GameStatus Game::addLife(const string& playerName) {
    int player_index = getPlayerIndexByName(playerName);
    if(player_index==INDEX_NOT_FOUND){
        return NAME_DOES_NOT_EXIST;
    }
    players_vector[player_index]->addLife();
    return SUCCESS;
}

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
GameStatus Game::addStrength(const string& playerName, int strengthToAdd) {
    if(strengthToAdd<0){
        return INVALID_PARAM;
    }
    int player_index = getPlayerIndexByName(playerName);
    if(player_index==INDEX_NOT_FOUND){
        return NAME_DOES_NOT_EXIST;
    }
    players_vector[player_index]->addStrength(strengthToAdd);
    return SUCCESS;

}

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
bool Game::removeAllPlayersWithWeakWeapon(int weaponStrength) {
    weakerThan tooWeak (weaponStrength);
    return removePlayersIf(tooWeak);
}

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
 *
 *
 */
GameStatus Game::fight(const string& playerName1, const string& playerName2) {
    int player1_index = getPlayerIndexByName(playerName1);
    int player2_index = getPlayerIndexByName(playerName2);
    if(player1_index==INDEX_NOT_FOUND || player2_index==INDEX_NOT_FOUND){
        throw mtm::NameDoesNotExist();
    }
    if(!players_vector[player1_index]->fight(*players_vector[player2_index])){
        if(!players_vector[player2_index]->fight(*players_vector[player1_index])){
            return FIGHT_FAILED;
        }
        return SUCCESS;
    }
    if(!players_vector[player1_index]->isAlive()){
        /* Player1 died. */
        removePlayer(*players_vector[player1_index]);
                return SUCCESS;
    }
    if(!players_vector[player2_index]->isAlive()){
        /* Player2 died. */
        removePlayer(*players_vector[player2_index]);
                return SUCCESS;
    }
    /* No one died. */
    return SUCCESS;
}


/**
 * operator<<
 *
 * @param os - Stream to concatenate to.
 * @param game - Game to print its details.
 *
 * @return
 * Stream of game details.
 */
ostream& operator<<(ostream& os,Game& game){
    /* Sorting players' array before printing. */
    game.sortPlayers();
    for(int i=0;i<game.players_vector.size();i++){
        os << "player "<<i<<": "<< *game.players_vector[i]<<","<< std::endl;
    }
    return os;
}

/**
 * isFull
 *
 * @return
 * True - Game is full.
 * False - Game is not full.
 */
bool Game::isFull() const {
    return players_vector.size() == max_players;
}

/**
 * playerExist
 *
 * @param player_name - Name of the player to check if exists.
 *
 * @return
 * True - Player with given name exists.
 * False - Player with given name does not exists.
 */
bool Game::playerExist(const string& player_name) const {
    for(int i=0; i<players_vector.size();i++){
        if(players_vector[i]->isPlayer(player_name)){
            return true;
        }
    }
    return false;
}

/**
 * removePlayer
 *
 * Removing player from the game.
 *
 * @param player -  Player to remove.
 */
void Game::removePlayer(const Player& player){
    for (int i=0;i<players_vector.size();i++) {
        if(player == *players_vector[i]){
            delete players_vector[i];
            players_vector[i]=players_vector[players_vector.size()-1];
            players_vector.pop_back();
            break;
        }
    }
}

/**
 * getPlayerIndexByName
 *
 * @param playerName - Name of the player to get its index.
 *
 * @return
 * Index of the player with the given name.
 * If not found returns -1.
 */
int Game::getPlayerIndexByName(const string& playerName) const {
    for(int i=0;i<players_vector.size();i++){
        if(players_vector[i]->isPlayer(playerName)){
            return i;
        }
    }
    return INDEX_NOT_FOUND;
}

/**
 * swap
 *
 * Swaping to players.
 *
 * @param player1_ptr - Pointer of first player.
 * @param player2_ptr - Pointer of second player.
 */
void Game::swap(Player* player1_ptr, Player* player2_ptr) {
    Player temp = *player1_ptr;
    *player1_ptr = *player2_ptr;
    *player2_ptr = temp;
}

/**
 * sortPlayers
 *
 * Sorting (bubble sort) players array (only the real players) by name.
 */
void Game::sortPlayers() {
    for (int i = 0; i < players_vector.size(); i++) {
        for (int j = 0; j < players_vector.size() - i - 1; j++) {
            if(*players_vector[j]>*players_vector[j+1]){
                swap(players_vector[j],players_vector[j+1]);
            }
        }
    }
}