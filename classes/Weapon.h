#ifndef ROTBOI_WEAPON_H
#define ROTBOI_WEAPON_H
#include "Entity.h"
#include "Item.h"

#include <SFML/Graphics.hpp>
#include <cmath>

class Weapon : public Item {
public:
    
    int minDmg, maxDmg;
    int rateOfFire;
    int range;
    int shotSpeed;




    Weapon() { 
        
    } /// Default Constructor

    void newDetails(){
        if (itemName == "Grimsbane"){
            minDmg = 700; maxDmg = 800;
            rateOfFire = 100;
            range = 4;
            shotSpeed = 12;

            iP.toolTipItemName.setString("Grimsbane");
            iP.toolTipItemDamage.setString("700 - 800");

            
        }
    }

};
#endif //ROTBOI_WEAPON_H