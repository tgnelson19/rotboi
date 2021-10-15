//
// Created by Tyler on 6/15/2021.
//

#ifndef ROTBOI_ITEM_H
#define ROTBOI_ITEM_H
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <cmath>

class Item : public Entity {
public:
    
    std::string itemName;
    bool isPresented;
    bool isBeingUsed;
    int slotNum;

    Item() { 
        isPresented = false;
        isBeingUsed = false;
        slotNum = -1;
    } /// Default Constructor

    

};
#endif //ROTBOI_ITEM_H