
#include "Warrior.h"

/**
 * Consturctor
 *
 * @param name - Name of the warrior.
 * @param weapon - Weapon of the warrior.
 * @param rider - Mounted or not (true/false).
 */
Warrior::Warrior(string const& name, Weapon const& weapon, bool rider):
Player(name,weapon), mounted(rider){
    if(weapon.getTarget()==LEVEL){
        /* Warrior cannot use this weapon. */
        throw mtm::IllegalWeapon();
    }
}

/**
 * makeStep
 *
 * If the warrior is mounted increasing his position by 5, if not
 * increasing position by 1.
 */
void Warrior::makeStep() {
    if(mounted){
        position+=5;
        return;
    }
    else{
        position++;
    }
}