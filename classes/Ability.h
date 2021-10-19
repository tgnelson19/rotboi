#ifndef ROTBOI_ABILITY_H
#define ROTBOI_ABILITY_H
#include "Entity.h"
#include "Item.h"

#include <SFML/Graphics.hpp>
#include <cmath>

class Ability : public Item {
public:

    Ability() { 
        
    } /// Default Constructor

    void newDetails(){
        if (itemName == "NSFWaki"){
            iP.toolTipItemName.setString("NSFWWaki");
            iP.toolTipItemDamage.setString("100");
        }
    }

};
#endif //ROTBOI_WEAPON_H