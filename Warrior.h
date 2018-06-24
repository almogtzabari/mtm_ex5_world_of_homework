

#ifndef MTM_EX5_WORLD_OF_HOMEWORK_WARRIOR_H
#define MTM_EX5_WORLD_OF_HOMEWORK_WARRIOR_H

#include "Player.h"
#include "mtm_exceptions.h"
using std::string;


class Warrior : public Player {
bool mounted;

public:

/**
 * Consturctor
 *
 * @param name - Name of the warrior.
 * @param weapon - Weapon of the warrior.
 * @param rider - Mounted or not (true/false).
 */
Warrior(string const& name, Weapon const& weapon, bool rider);

void makeStep() override ;


};


#endif //MTM_EX5_WORLD_OF_HOMEWORK_WARRIOR_H
