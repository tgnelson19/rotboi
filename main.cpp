#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iostream>

#include "classes/Character.h"
#include "classes/Arrow.h"
#include "classes/Entity.h"
#include "classes/Enemy.h"


int main(){

    sf::Texture bg, Arrow, SArcherSpriteSheet, Inventory, Stats, CrystalBoi, GoldTexture, upgradedBowShot;

    if (!bg.loadFromFile("images/World1.png")) { /// Released for non-commercial use by Oryx
        std::cout << "Error: Failed to load file" << std::endl;
        return EXIT_FAILURE;
    }
    if (!Arrow.loadFromFile("images/Arrow.png")) { /// Released for non-commercial use by Oryx
        std::cout << "Error: Failed to load file" << std::endl;
        return EXIT_FAILURE;
    }
    if (!SArcherSpriteSheet.loadFromFile("images/SlimeArcherSpriteSheet.png")) { /// Created by IExisted
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

    enum state {STARTSCREEN, GAMEPLAY, PAUSE};

    sf::RenderWindow window(sf::VideoMode(1500, 800), "RotTest"); ///Main window initialized
    window.setFramerateLimit(60);

    std::vector<Entity *> entities;






    Character *c = new Character();
    c->settings(, 600, 600, 0);
    entities.push_back(c);

    while (window.isOpen()) {


        switch (state){
            case 0:

                break;

            default: ;

        }








        c->isMoving = false; c->dx = 0; c->dy = 0;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { c->isMoving = true; c->dx = 1; }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { c->isMoving = true; c->dx = -1; }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { c->isMoving = true; c->dy = 1; }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { c->isMoving = true; c->dy = -1; }



    }
    return 0;
}