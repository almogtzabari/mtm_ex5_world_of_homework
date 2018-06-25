
#ifndef MTM_EX5_WORLD_OF_HOMEWORK_TROLL_H
#define MTM_EX5_WORLD_OF_HOMEWORK_TROLL_H

#include "Player.h"
#include "mtm_exceptions.h"

class Troll : public Player{
    int maxLife;

public:

    /**
     * Constructor
     * @param name - Troll's name.
     * @param weapon - Troll's weapon.
     * @param maxLife - MaxLife of troll.
     */
    Troll(string const& name,Weapon const& weapon, int maxLife);

/**
 * makeStep
 *
 * Increasing troll's position by 2.
 * Increasing troll's life by 1 (only if life is not full).
 */
    void makeStep() override ;
};


#endif //MTM_EX5_WORLD_OF_HOMEWORK_TROLL_H
