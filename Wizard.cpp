
#include "Wizard.h"

/**
 * Constructor:
 * @param name - Name of the wizard.
 * @param weapon - Weapon of the wizard.
 * @param range - Attacking range.
 */
Wizard::Wizard(string const &name, Weapon const &weapon, int range):
Player(name,weapon),range(range){
    if(weapon.getTarget()==LIFE){
        throw mtm::IllegalWeapon();
    }
    if(range<0){
        throw mtm::InvalidParam();
    }
}

/**
    * canAttack
    * @param player - A player to attack.
    * @return
    * True if the wizard can attack, else false.
    */
bool Wizard::canAttack (const Player& player) const{
    if (position==player.getPosition() || distance(*this,player)>range){
        return false;
    }
    return true;
}