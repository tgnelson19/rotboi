#ifndef ROTBOI_ITEMPREVIEW_H
#define ROTBOI_ITEMPREVIEW_H
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <cmath>

class ItemPreview : public Entity{
public:
    sf::Text toolTipItemName;
    sf::Text toolTipItemDamage;

    sf::Text toolTipItemFlavor1;
    sf::Text toolTipItemFlavor2;
    sf::Text toolTipItemFlavor3;

    ItemPreview(){
        toolTipItemName.setCharacterSize(30);  toolTipItemName.setFillColor(sf::Color::White); toolTipItemName.setString("Nothing"); toolTipItemName.setPosition(0,0);
        toolTipItemDamage.setCharacterSize(20);toolTipItemDamage.setFillColor(sf::Color::White);toolTipItemDamage.setString("Nothing"); toolTipItemDamage.setPosition(0,0);
        
    }

};





#endif //ROTBOI_ITEMPREVIEW_H