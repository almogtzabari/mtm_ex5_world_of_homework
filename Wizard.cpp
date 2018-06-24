
#include "Wizard.h"


Wizard::Wizard(string const &name, Weapon const &weapon, int range):
Player(name,weapon),range(range){
    if(weapon.getTarget()==LIFE){
        throw mtm::IllegalWeapon();
    }
}
