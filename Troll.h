
#ifndef MTM_EX5_WORLD_OF_HOMEWORK_TROLL_H
#define MTM_EX5_WORLD_OF_HOMEWORK_TROLL_H

#include "Player.h"

class Troll : public Player{
    int maxLife;
    /**
     * Constructor
     * @param name - Troll's name.
     * @param weapon - Troll's weapon.
     * @param maxLife - MaxLife of troll.
     */
    Troll(string const& name,Weapon const& weapon, int maxLife);
};


#endif //MTM_EX5_WORLD_OF_HOMEWORK_TROLL_H
