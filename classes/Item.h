//
// Created by Tyler on 6/15/2021.
//

#ifndef ROTBOI_ITEM_H
#define ROTBOI_ITEM_H
#include "Entity.h"
#include "ItemPreview.h"
#include <SFML/Graphics.hpp>
#include <cmath>

class Item : public Entity {
public:
    
    std::string itemName;
    std::string itemType;
    bool isPresented;
    bool isBeingUsed;
    bool isInInv;
    std::string slot;
    ItemPreview iP;
    
    

    Item() { 
        isPresented = false;
        isBeingUsed = false;
        isInInv = false;
        slot = "-1";
        
    } /// Default Constructor

    void update(){

        if (slot == "I1"){x = 1230;y = 620;}
        if (slot == "I2"){x = 1300;y = 620;}
        if (slot == "I3"){x = 1360;y = 620;}
        if (slot == "I4"){x = 1425;y = 620;}
        if (slot == "G"){x = 1330;y = 715;}
        if (slot == "W"){x = 1230;y = 555;}
        if (slot == "Ab"){x = 1295;y = 555;}
        if (slot == "Ar"){x = 1365;y = 555;}
        if (slot == "R"){x = 1430;y = 555;}

    }

    void showTooltip(float mvecx, float mvecy, sf::RenderWindow &window, sf::Font font){
        iP.sprite.setPosition(mvecx - iP.sprite.getGlobalBounds().width, mvecy - iP.sprite.getGlobalBounds().height);
        window.draw(iP.sprite);
        iP.toolTipItemName.setPosition(iP.sprite.getPosition().x + 20, iP.sprite.getPosition().y + 20); iP.toolTipItemName.setFont(font);
        window.draw(iP.toolTipItemName);
        iP.toolTipItemDamage.setPosition(iP.sprite.getPosition().x + 20, iP.sprite.getPosition().y + 60); iP.toolTipItemDamage.setFont(font);
        window.draw(iP.toolTipItemDamage);

        

    }

};
#endif //ROTBOI_ITEM_H