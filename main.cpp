#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iostream>

#include "classes/Character.h"
#include "classes/Arrow.h"
#include "classes/Entity.h"
#include "classes/Enemy.h"
#include "classes/Background.h"


int main(){

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

            cFNW(SArcherSpriteSheet, sf::IntRect(0, 280, 150, 140)),
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
    cFNW.setPosition(575, 375);
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
    cFNW.setScale(0.5, 0.5);
    cFW1.setScale(0.5, 0.5);
    cFW2.setScale(0.5, 0.5);
    cFS1.setScale(0.5, 0.5);
    cFS2.setScale(0.5, 0.5);

    sf::Texture bg, Arrow, Inventory, Stats, CrystalBoi, GoldTexture, upgradedBowShot;

    if (!bg.loadFromFile("images/World1.png")) { /// Released for non-commercial use by Oryx
        std::cout << "Error: Failed to load file" << std::endl;
        return EXIT_FAILURE;
    }
    if (!Arrow.loadFromFile("images/Arrow.png")) { /// Released for non-commercial use by Oryx
        std::cout << "Error: Failed to load file" << std::endl;
        return EXIT_FAILURE;
    }
    if (!Inventory.loadFromFile("images/Inventory.png")) { /// Created by Wildshadow Studios
        std::cout << "Error: Failed to load file" << std::endl;
        return EXIT_FAILURE;
    }
    if (!Stats.loadFromFile("images/Stats.png")) { /// Created by Deca Games
        std::cout << "Error: Failed to load file" << std::endl;
        return EXIT_FAILURE;
    }
    if (!CrystalBoi.loadFromFile("images/Crystal_Crawler.png")) { /// Created by Deca Games
        std::cout << "Error: Failed to load file" << std::endl;
        return EXIT_FAILURE;
    }
    if (!GoldTexture.loadFromFile("images/gold.png")) { /// Released for non-commercial use by Oryx
        std::cout << "Error: Failed to load file" << std::endl;
        return EXIT_FAILURE;
    }
    if (!upgradedBowShot.loadFromFile("images/dBowShot.png")) { /// Created by Deca Games
        std::cout << "Error: Failed to load file" << std::endl;
        return EXIT_FAILURE;
    }

    sf::Sprite map(bg);

    enum states {STARTSCREEN, GAMEPLAY, PAUSE}; states state = GAMEPLAY;

    sf::RenderWindow window(sf::VideoMode(1500, 800), "RotTest"); ///Main window initialized

    window.setFramerateLimit(60);

    std::vector<Entity *> entities;

    Background *b = new Background();
    map.scale(60,60);
    b->settings(map, -40000, -40000, 0);
    b->speed = 6;
    entities.push_back(b);


    Character *c = new Character();
    c->x = 600; c->y = 400; c->speed = 6;
    entities.push_back(c);

    while (window.isOpen()) {
        switch (state){
            case STARTSCREEN:



                break;

            case GAMEPLAY:


                b->isMoving = false; b->dx = 0; b->dy = 0;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { b->isMoving = true; b->dx = 1; }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { b->isMoving = true; b->dx = -1; }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { b->isMoving = true; b->dy = 1; }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { b->isMoving = true; b->dy = -1; }



                for (auto i = entities.begin(); i != entities.end();) {
                    Entity *e = *i; //*i is an Entity pointer, using * on an iterator returns the element from the list
                    e->update(); // Uses polymorphism to call the proper update method
                    if (!e->isAlive) { i = entities.erase(i); delete e; }
                    else i++; // if life was true, move iterator to the next element in the list
                }

                ///Draw Logic

                //window.clear(sf::Color::White);

                for (auto i:entities) {i->draw(window);}

                window.display();



                break;

            case PAUSE:


                break;

        }
    }
    return 0;
}