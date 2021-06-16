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

    cBNW.setPosition(575, 400);
    cBW1.setPosition(584, 400);
    cBW2.setPosition(575, 400);
    cBS1.setPosition(575, 400);
    cBS2.setPosition(575, 400);
    cRNW.setPosition(575, 400);
    cRW2.setPosition(575, 400);
    cRS1.setPosition(575, 400);
    cRS2.setPosition(575, 400);
    cLNW.setPosition(600, 400);
    cLW2.setPosition(607, 400);
    cLS1.setPosition(600, 400);
    cLS2.setPosition(600, 400);
    cFNW.setPosition(575, 400);
    cFW1.setPosition(584, 400);
    cFW2.setPosition(575, 400);
    cFS1.setPosition(575, 400);
    cFS2.setPosition(575, 400);

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

    sf::Texture bg, arrowTexture, Inventory, Stats, CrystalBoi, GoldTexture, upgradedBowShot;

    if (!bg.loadFromFile("images/World1.png")) { /// Released for non-commercial use by Oryx
        std::cout << "Error: Failed to load file" << std::endl;
        return EXIT_FAILURE;
    }
    if (!arrowTexture.loadFromFile("images/Arrow.png")) { /// Released for non-commercial use by Oryx
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

    sf::Sprite map(bg), arrowSprite(arrowTexture);

    enum states {STARTSCREEN, GAMEPLAY, PAUSE}; states state = GAMEPLAY;

    sf::RenderWindow window(sf::VideoMode(1500, 800), "rotboi"); ///Main window initialized

    window.setFramerateLimit(60);

    std::vector<Entity *> entities;

    sf::Mouse mouse;
    std::vector<float> mousePos = {0, 0};

    Background *b = new Background();
    map.scale(60,60);
    b->settings(map, -40000, -40000, 0);
    b->speed = 6;
    entities.push_back(b);

    Character *c = new Character();
    c->settings(cFNW, 600, 375, 0);
    entities.push_back(c);

    while (window.isOpen()) {
        switch (state){
            case STARTSCREEN: {

                sf::Event move{};
                while (window.pollEvent(move)) {
                    if (move.type == sf::Event::Closed) {
                        window.close(); /// Closes window when window is closed
                    }
                }


            break; }

            case GAMEPLAY: {

                sf::Event move{};
                while (window.pollEvent(move)) {
                    if (move.type == sf::Event::Closed) {
                        window.close(); /// Closes window when window is closed
                    }
                }

                if (!b->isMoving){ c->walk2 = true;}

                b->isMoving = false; b->dx = 0; b->dy = 0;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { b->isMoving = true; b->dx = 1; c->lastDirection = 'R'; }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { b->isMoving = true; b->dx = -1; c->lastDirection = 'L';}
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { b->isMoving = true; b->dy = 1; c->lastDirection = 'U'; }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { b->isMoving = true; b->dy = -1; c->lastDirection = 'D';}

                if (c->isShooting){
                    if (c->shot2) {
                        if (mousePos.at(0) > std::abs(mousePos.at(1))){ c->sprite = cRS2; c->x = cRS2.getPosition().x; c->lastDirection = 'R';}
                        else if (std::abs(mousePos.at(0)) > std::abs(mousePos.at(1))) {c->sprite = cLS2; c->x = cLS2.getPosition().x; c->lastDirection = 'L';}
                        else if (mousePos.at(1) > 0){c->sprite = cFS2; c->x = cFS2.getPosition().x;}
                        else {c->sprite = cBS2; c->x = cBS2.getPosition().x;}
                    } else {
                        if (mousePos.at(0) > std::abs(mousePos.at(1))){ c->sprite = cRS1; c->x = cRS1.getPosition().x;}
                        else if (std::abs(mousePos.at(0)) > std::abs(mousePos.at(1))){ c->sprite = cLS1; c->x = cLS1.getPosition().x;}
                        else if (mousePos.at(1) > 0){c->sprite = cFS1; c->x = cFS1.getPosition().x; c->lastDirection = 'D';}
                        else {c->sprite = cBS1; c->x = cBS1.getPosition().x; c->lastDirection = 'U';}
                    }
                } else if (b->isMoving && !c->isShooting) {
                    if (c->walk2) {
                        if (c->lastDirection == 'R'){ c->sprite = cRW2; c->x = cRW2.getPosition().x;}
                        else if (c->lastDirection == 'L') {c->sprite = cLW2; c->x = cLW2.getPosition().x;}
                        else if (c->lastDirection == 'U'){ c->sprite = cBW2; c->x = cBW2.getPosition().x;}
                        else if (c->lastDirection == 'D'){c->sprite = cFW2; c->x = cFW2.getPosition().x;}
                    } else {
                        if (c->lastDirection == 'R'){c->sprite = cRNW; c->x = cRNW.getPosition().x;}
                        else if (c->lastDirection == 'L') {c->sprite = cLNW; c->x = cLNW.getPosition().x;}
                        else if (c->lastDirection == 'U'){c->sprite = cBW1; c->x = cBW1.getPosition().x;}
                        else if (c->lastDirection == 'D'){c->sprite = cFW1; c->x = cFW1.getPosition().x;}
                    }
                } else if (!b->isMoving && !c->isShooting){
                    if (c->lastDirection == 'R'){ c->sprite = cRNW; c->x = cRNW.getPosition().x;}
                    else if (c->lastDirection == 'L') {c->sprite = cLNW; c->x = cLNW.getPosition().x;}
                    else if (c->lastDirection == 'U'){ c->sprite = cBNW; c->x = cBNW.getPosition().x;}
                    else if (c->lastDirection == 'D'){c->sprite = cFNW; c->x = cFNW.getPosition().x;}
                }

                c->isShooting = false;
                if (sf::Mouse::isButtonPressed(mouse.Left)){
                    if (c->canShoot){
                        Arrow *a = new Arrow();
                        a->shotSpeed = c->shotSpeed; a->damage = c->damage;
                        sf::Vector2i mvec = sf::Mouse::getPosition(window); ///Mouse position in vector form
                        mousePos.at(0) = mvec.x - c->x; ///Mouse position relative to the character
                        mousePos.at(1) = mvec.y - c->y - 25;
                        if (mousePos.at(0) < 0) { ///If x is negative
                            arrowSprite.setScale(-0.2, -0.2); ///Flop the arrow on x and y axis
                            a->backwards = true;
                            a->settings(arrowSprite, 610, 425, (atan(mousePos.at(1) / mousePos.at(0)) * 57.29));
                        } else {
                            arrowSprite.setScale(0.2, 0.2);
                            a->settings(arrowSprite, 620, 400, (atan(mousePos.at(1) / mousePos.at(0)) * 57.29));
                        }
                        entities.push_back(a);
                        c->canShoot = false;
                        c->shotTimer = 0;
                        c->shot2 = true;
                    }
                    c->isShooting = true;
                }







                for (auto i = entities.begin(); i != entities.end();) {
                    Entity *e = *i; //*i is an Entity pointer, using * on an iterator returns the element from the list
                    e->update(); // Uses polymorphism to call the proper update method
                    if (!e->isAlive) { i = entities.erase(i); delete e; }
                    else i++; //Move iterator to the next element in the list
                }

                ///Draw Logic

                for (auto i:entities) {
                    if (i->name == "arrow"){
                        i->pDX = b->speed*b->dx; i->pDY = b->speed*b->dy;
                    }
                    i->draw(window);
                }
                window.display();


                break; }

            case PAUSE: {

                sf::Event move{};
                while (window.pollEvent(move)) {
                    if (move.type == sf::Event::Closed) {
                        window.close(); /// Closes window when window is closed
                    }
                }


                break;}

        }
    }
    return 0;
}