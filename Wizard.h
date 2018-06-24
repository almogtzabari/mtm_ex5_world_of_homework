
#ifndef MTM_EX5_WORLD_OF_HOMEWORK_WIZARD_H
#define MTM_EX5_WORLD_OF_HOMEWORK_WIZARD_H

#include "Player.h"
#include "mtm_exceptions.h"

class Wizard : public Player {
    int range;

public:
    /**
 * Constructor:
 * @param name - Name of the wizard.
 * @param weapon - Weapon of the wizard.
 * @param range - Attacking range.
 */
    Wizard(string const& name,Weapon const& weapon, int range);
    /**
     * canAttack
     * @param player - A player to attack.
     * @return
     * True if the wizard can attack, else false.
     */
    bool canAttack (const Player& player) const override;

};


#endif //MTM_EX5_WORLD_OF_HOMEWORK_WIZARD_H
