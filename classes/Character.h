//
// Created by Tyler on 6/15/2021.
//

#ifndef ROTBOI_CHARACTER_H
#define ROTBOI_CHARACTER_H

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Character : public Entity{
public:
    bool isMoving;
    bool isShooting;
    char shotDirection;
    float dx, dy;
    sf::Sprite cFNW;

    Character(){

        name = "character";
        isMoving = false;
        isAlive = true;

        sf::Texture SArcherSpriteSheet;

        if (!SArcherSpriteSheet.loadFromFile("images/SlimeArcherSpriteSheet.png")) { /// Created by IExisted
            std::cout << "Error: Failed to load file" << std::endl;
        }

        SArcherSpriteSheet.setSmooth(true);

        sf::Sprite

                cBNW(SArcherSpriteSheet, sf::IntRect(0, 0, 150, 140)),
                cBW1(SArcherSpriteSheet, sf::IntRect(150, 0, 120, 140)),
                cBW2(SArcherSpriteSheet, sf::IntRect(270, 0, 150, 140)),
                cBS1(SArcherSpriteSheet, sf::IntRect(420, 0, 135, 140)),
                cBS2(SArcherSpriteSheet, sf::IntRect(555, 0, 165, 140)),
                cRNW(SArcherSpriteSheet, sf::IntRect(0, 140, 150, 140)),
                cRW2(SArcherSpriteSheet, sf::IntRect(150, 140, 120, 140)),
                cRS1(SArcherSpriteSheet, sf::IntRect(420, 140, 135, 140)),
                cRS2(SArcherSpriteSheet, sf::IntRect(555, 140, 165, 140)),

                cLNW(SArcherSpriteSheet, sf::IntRect(0, 140, 150, 140)),
                cLW2(SArcherSpriteSheet, sf::IntRect(150, 140, 120, 140)),
                cLS1(SArcherSpriteSheet, sf::IntRect(420, 140, 135, 140)),
                cLS2(SArcherSpriteSheet, sf::IntRect(555, 140, 165, 140));

        cLNW.setOrigin(75, 0);
        cLW2.setOrigin(60, 0);
        cLS1.setOrigin(67.5, 0);
        cLS2.setOrigin(82.5, 0);

        sf::Sprite

                cFNWa(SArcherSpriteSheet, sf::IntRect(0, 280, 150, 140)),
                cFW1(SArcherSpriteSheet, sf::IntRect(150, 280, 120, 140)),
                cFW2(SArcherSpriteSheet, sf::IntRect(270, 280, 150, 140)),
                cFS1(SArcherSpriteSheet, sf::IntRect(420, 280, 135, 140)),
                cFS2(SArcherSpriteSheet, sf::IntRect(555, 280, 165, 140));

        ///Offsets in case some sprites are too far off center and look bad, also for character positioning

        cBNW.setPosition(575, 375);
        cBW1.setPosition(584, 375);
        cBW2.setPosition(575, 375);
        cBS1.setPosition(575, 375);
        cBS2.setPosition(575, 375);
        cRNW.setPosition(575, 375);
        cRW2.setPosition(575, 375);
        cRS1.setPosition(575, 375);
        cRS2.setPosition(575, 375);
        cLNW.setPosition(600, 375);
        cLW2.setPosition(607, 375);
        cLS1.setPosition(600, 375);
        cLS2.setPosition(600, 375);
        cFNWa.setPosition(575, 375);
        cFW1.setPosition(584, 375);
        cFW2.setPosition(575, 375);
        cFS1.setPosition(575, 375);
        cFS2.setPosition(575, 375);

        cBNW.setScale(0.5, 0.5);
        cBW1.setScale(0.5, 0.5);
        cBW2.setScale(0.5, 0.5);
        cBS1.setScale(0.5, 0.5);
        cBS2.setScale(0.5, 0.5);
        cRNW.setScale(0.5, 0.5);
        cRW2.setScale(0.5, 0.5);
        cRS1.setScale(0.5, 0.5);
        cRS2.setScale(0.5, 0.5);
        cLNW.setScale(-0.5, 0.5);
        cLW2.setScale(-0.5, 0.5);
        cLS1.setScale(-0.5, 0.5);
        cLS2.setScale(-0.5, 0.5);
        cFNWa.setScale(0.5, 0.5);
        cFW1.setScale(0.5, 0.5);
        cFW2.setScale(0.5, 0.5);
        cFS1.setScale(0.5, 0.5);
        cFS2.setScale(0.5, 0.5);

        sprite = cFNWa;

        cFNW = cFNWa;


    }

    void update() {
        sprite = cFNW;

    }

};


#endif //ROTBOI_CHARACTER_H
