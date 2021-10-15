//
// Created by Tyler on 6/15/2021.
//

#ifndef ROTBOI_BAG_H
#define ROTBOI_BAG_H
#include "Entity.h"
#include "Item.h"
#include <SFML/Graphics.hpp>
#include <cmath>

class Bag : public Entity {
public:
    
    Item *itemInside;

    Bag() { 
        
    } /// Default Constructor

    void update(){

        
        if (pDX != 0 && pDY != 0){
            pDX /= sqrt(2); pDY /= sqrt(2);
        }

        x-= pDX; y+= pDY;

    }

    

};
#endif //ROTBOI_BAG_H