
#include "Troll.h"


/**
 * Constructor
 * @param name - Troll's name.
 * @param weapon - Troll's weapon.
 * @param maxLife - MaxLife of troll.
 */
Troll::Troll(string const &name, Weapon const &weapon, int maxLife):
Player(name,weapon),maxLife(maxLife){
    if(maxLife<0){
        throw mtm::InvalidParam;
    }
}

/**
 * makeStep
 *
 * Increasing troll's position by 2.
 * Increasing troll's life by 1 (only if life is not full).
 */
void Troll::makeStep() {
    position+=2;
    if(maxLife<life){
        addLife();
    }
}

