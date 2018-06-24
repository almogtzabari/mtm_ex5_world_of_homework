
#ifndef MTM_EX5_WORLD_OF_HOMEWORK_WIZARD_H
#define MTM_EX5_WORLD_OF_HOMEWORK_WIZARD_H

#include "Player.h"

class Wizard : public Player {
    int range;

public:
    Wizard(string const& name,Weapon const& weapon, int range);

};


#endif //MTM_EX5_WORLD_OF_HOMEWORK_WIZARD_H
