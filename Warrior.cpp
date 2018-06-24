
#include "Warrior.h"

Warrior::Warrior(string const& name, Weapon const& weapon, bool rider):
Player(name,weapon), mounted(rider){
    if(weapon.getTarget()==LEVEL){
        /* Warrior cannot use this weapon. */
        throw mtm::IllegalWeapon();
    }
}

void Warrior::makeStep() {
    if(mounted){
        position+=5;
        return;
    }
    else{
        position++;
    }
}