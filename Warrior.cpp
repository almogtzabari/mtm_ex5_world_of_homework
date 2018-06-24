
#include "Warrior.h"

Warrior::Warrior(string const& name, Weapon const& weapon, bool rider):
Player(name,weapon), mounted(rider){
    if(weapon.getTarget()==LEVEL){
        throw mtm_exception
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