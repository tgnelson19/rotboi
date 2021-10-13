///Made by Tyler Nelson

#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iostream>

#include "classes/Character.h"
#include "classes/Arrow.h"
#include "classes/Entity.h"
#include "classes/Enemy.h"
#include "classes/BasicChaseEnemy.h"
#include "classes/BasicRangedEnemy.h"
#include "classes/EnemyProjectile.h"
#include "classes/Background.h"
#include "classes/MovingText.h"

const int enemyCap = 3;

int enemyCount = 0;
 
int main(){

    srand(time(0));

    sf::Texture SArcherSpriteSheet; ///Sprite sheet initialized
    if (!SArcherSpriteSheet.loadFromFile("images/SlimeArcherSpriteSheet.png")) { /// Created by IExisted
        std::cout << "Error: Failed to load file" << std::endl;
    }

    SArcherSpriteSheet.setSmooth(true); ///Smoothes the jags made by scaling

    sf::Sprite ///Initializing all of the character sprites off of the sprite sheet
            cBNW(SArcherSpriteSheet, sf::IntRect(0, 0, 150, 140)), cBW1(SArcherSpriteSheet, sf::IntRect(150, 0, 120, 140)),
            cBW2(SArcherSpriteSheet, sf::IntRect(270, 0, 150, 140)), cBS1(SArcherSpriteSheet, sf::IntRect(420, 0, 135, 140)),
            cBS2(SArcherSpriteSheet, sf::IntRect(555, 0, 165, 140)), cRNW(SArcherSpriteSheet, sf::IntRect(0, 140, 150, 140)),
            cRW2(SArcherSpriteSheet, sf::IntRect(150, 140, 120, 140)), cRS1(SArcherSpriteSheet, sf::IntRect(420, 140, 135, 140)),
            cRS2(SArcherSpriteSheet, sf::IntRect(555, 140, 165, 140)), cLNW(SArcherSpriteSheet, sf::IntRect(0, 140, 150, 140)), 
            cLW2(SArcherSpriteSheet, sf::IntRect(150, 140, 120, 140)), cLS1(SArcherSpriteSheet, sf::IntRect(420, 140, 135, 140)), 
            cLS2(SArcherSpriteSheet, sf::IntRect(555, 140, 165, 140)), cFNW(SArcherSpriteSheet, sf::IntRect(0, 280, 150, 140)),
            cFW1(SArcherSpriteSheet, sf::IntRect(150, 280, 120, 140)), cFW2(SArcherSpriteSheet, sf::IntRect(270, 280, 150, 140)),
            cFS1(SArcherSpriteSheet, sf::IntRect(420, 280, 135, 140)), cFS2(SArcherSpriteSheet, sf::IntRect(555, 280, 165, 140));

    ///Offsets to make the sprites look more fluid
    cBNW.setPosition(575, 400); cBW1.setPosition(584, 400); cBW2.setPosition(575, 400);
    cBS1.setPosition(575, 400); cBS2.setPosition(575, 400); cRNW.setPosition(575, 400);
    cRW2.setPosition(575, 400); cRS1.setPosition(575, 400); cRS2.setPosition(575, 400);
    cLNW.setPosition(600, 400); cLW2.setPosition(607, 400); cLS1.setPosition(600, 400);
    cLS2.setPosition(600, 400); cFNW.setPosition(575, 400); cFW1.setPosition(584, 400);
    cFW2.setPosition(575, 400); cFS1.setPosition(575, 400); cFS2.setPosition(575, 400);
    cBNW.setScale(0.5, 0.5); cBW1.setScale(0.5, 0.5); cBW2.setScale(0.5, 0.5);
    cBS1.setScale(0.5, 0.5); cBS2.setScale(0.5, 0.5); cRNW.setScale(0.5, 0.5);
    cRW2.setScale(0.5, 0.5); cRS1.setScale(0.5, 0.5); cRS2.setScale(0.5, 0.5);
    cLNW.setScale(-0.5, 0.5); cLW2.setScale(-0.5, 0.5); cLS1.setScale(-0.5, 0.5);
    cLS2.setScale(-0.5, 0.5); cFNW.setScale(0.5, 0.5); cFW1.setScale(0.5, 0.5);
    cFW2.setScale(0.5, 0.5); cFS1.setScale(0.5, 0.5); cFS2.setScale(0.5, 0.5);
    cLNW.setOrigin(75, 0);cLW2.setOrigin(60, 0); cLS1.setOrigin(67.5, 0);cLS2.setOrigin(82.5, 0);

    sf::Texture bg, arrowTexture, Inventory, Stats, CrystalBoi, CrystalBluey, GoldTexture, 
    upgradedBowShot, upArrow, upgradeBackground, deadArrow, upgradeBoard, stScreen, bright, inv, bosRom; /// Other textures initialized

    if (!bg.loadFromFile("images/World1.png")) { /// Released for non-commercial use by Oryx
        std::cout << "Error: Failed to load file" << std::endl;
        return EXIT_FAILURE;
    }
    if (!arrowTexture.loadFromFile("images/Arrow.png")) { /// Released for non-commercial use by Oryx
        std::cout << "Error: Failed to load file" << std::endl;
        return EXIT_FAILURE;
    }
    if (!CrystalBoi.loadFromFile("images/Crystal_Crawler.png")) { /// Created by Deca Games
        std::cout << "Error: Failed to load file" << std::endl;
        return EXIT_FAILURE;
    }
    if (!CrystalBluey.loadFromFile("images/Crystal_Charger.png")) { /// Created by Deca Games
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
    if (!upArrow.loadFromFile("images/pixil-frame-0 (4).png")) { 
        std::cout << "Error: Failed to load file" << std::endl;
        return EXIT_FAILURE;
    }
    if (!upgradeBackground.loadFromFile("images/pixil-frame-0 (1).png")) { 
        std::cout << "Error: Failed to load file" << std::endl;
        return EXIT_FAILURE;
    }
    if (!deadArrow.loadFromFile("images/pixil-frame-0 (5).png")) { 
        std::cout << "Error: Failed to load file" << std::endl;
        return EXIT_FAILURE;
    }
    if (!upgradeBoard.loadFromFile("images/pixil-frame-0 (6).png")) { 
        std::cout << "Error: Failed to load file" << std::endl;
        return EXIT_FAILURE;
    }
    if (!stScreen.loadFromFile("images/startScreen.png")) { 
        std::cout << "Error: Failed to load file" << std::endl;
        return EXIT_FAILURE;
    }
    if (!bright.loadFromFile("images/pixil-frame-0 (7).png")) { 
        std::cout << "Error: Failed to load file" << std::endl;
        return EXIT_FAILURE;
    }
    if (!inv.loadFromFile("images/pixil-frame-0 (8).png")) { 
        std::cout << "Error: Failed to load file" << std::endl;
        return EXIT_FAILURE;
    }
    if (!bosRom.loadFromFile("images/pixil-frame-0 (9).png")) { 
        std::cout << "Error: Failed to load file" << std::endl;
        return EXIT_FAILURE;
    }

    sf::Sprite map(bg), arrowSprite(arrowTexture), crystalEnemy(CrystalBoi), crystalShootey(CrystalBluey), goldIcon(GoldTexture), enemyShot(upgradedBowShot); ///Making basic sprites
    sf::Sprite uppy(upArrow), upBackground(upgradeBackground), deadUppy(deadArrow), upgBoard(upgradeBoard), startScreen(stScreen), highLight(bright), rightSide(inv);
    sf::Sprite bossRoom(bosRom);

    arrowSprite.setPosition(1600, 800); crystalEnemy.setPosition(0,0); crystalShootey.setPosition(0,0);

    uppy.setScale(0.7, 0.7); startScreen.setScale(5,5);

    highLight.setScale(1.2, 1.2);

    highLight.setPosition(335, 520);

    rightSide.setScale(0.71, 0.71); rightSide.setPosition(1208, 292); 

    enum states {STARTSCREEN, GAMEPLAY, PAUSE}; states state = STARTSCREEN; ///Enumerations for game states

    sf::RenderWindow window(sf::VideoMode(W, H), "rotboi"); ///Main window initialized

    window.setFramerateLimit(60); /// Limits framerate

    std::vector<Entity *> entities; ///Entity list to interate through
    entities.clear();

    sf::Mouse mouse; std::vector<float> mousePos = {0, 0}; ///Mouse position

    sf::Font font;
    if (!font.loadFromFile("fonts/Oswald-Bold.ttf")) { /// Free for commercial use from fontsquirrel.com
        return EXIT_FAILURE;
    }

    sf::View miniMap; miniMap.setViewport(sf::FloatRect(0.805f, 0.008f, 0.19f, 0.35f)); ///Makes a minimap

    Background *b = new Background(); /// Background entity
    ///map.scale(60,60);
    bossRoom.setScale(2,2);
    b->settings(bossRoom, -1900, -4500, 0);
    /// For map it's -40000, -40000
    b->speed = 6;
    entities.push_back(b);

    Character *c = new Character(); ///Character entity
    c->settings(cFNW, 600, 375, 0);
    entities.push_back(c);

    Entity *goldenEntity = new Entity(); ///Gold entity
    goldIcon.setScale(0.6, 0.6);
    goldenEntity->settings(goldIcon, 1360, 298, 0);
    entities.push_back(goldenEntity);

    ///Texts initialized
    sf::Text gold("0", font, 30); gold.setFillColor(sf::Color::White); gold.setPosition(1400, 300);
    sf::Text pauseHelp("Pause with the Escape key | Unpause with the Tab key", font, 25); pauseHelp.setFillColor(sf::Color::Black); pauseHelp.setPosition(460, 750);
    sf::Text pause("Unpause with the Tab key", font, 25); pause.setFillColor(sf::Color::Black); pause.setPosition(100, 220);
    sf::Text playButtonText("Play", font, 50); playButtonText.setFillColor(sf::Color::Black); playButtonText.setPosition(700, 475);

    sf::Text damageOnBar("DMG", font, 30); damageOnBar.setFillColor((sf::Color::Black)); damageOnBar.setPosition(1230,360);
    sf::Text attackOnBar("ATT", font, 20); attackOnBar.setFillColor((sf::Color::Magenta)); attackOnBar.setPosition(1225,430);
    sf::Text dexterityOnBar("DEX", font, 20); dexterityOnBar.setFillColor((sf::Color::Yellow)); dexterityOnBar.setPosition(1370,430);
    sf::Text critChanceOnBar("C.C.", font, 20); critChanceOnBar.setFillColor((sf::Color::Yellow)); critChanceOnBar.setPosition(1225,465);
    sf::Text critDamageOnBar("C.D.", font, 20); critDamageOnBar.setFillColor((sf::Color::Red)); critDamageOnBar.setPosition(1370,465);
    sf::Text speedOnBar("SPD", font, 20); speedOnBar.setFillColor((sf::Color::Green)); speedOnBar.setPosition(1225,500);
    sf::Text vitalityOnBar("VIT", font, 20); vitalityOnBar.setFillColor((sf::Color::Red)); vitalityOnBar.setPosition(1370,500);

    sf::Text damageText("0", font, 30); damageText.setFillColor((sf::Color::Black)); damageText.setPosition(1340,360);
    sf::Text attackText("0", font, 20); attackText.setFillColor((sf::Color::Magenta)); attackText.setPosition(1270,430);
    sf::Text dexterityText("0", font, 20); dexterityText.setFillColor((sf::Color::Yellow)); dexterityText.setPosition(1415,430);
    sf::Text critChanceText("0", font, 20); critChanceText.setFillColor((sf::Color::Yellow)); critChanceText.setPosition(1270,465);
    sf::Text critDamageText("0", font, 20); critDamageText.setFillColor((sf::Color::Red)); critDamageText.setPosition(1415,465);
    sf::Text speedText("0", font, 20); speedText.setFillColor((sf::Color::Green)); speedText.setPosition(1270,500);
    sf::Text vitalityText("0", font, 20); vitalityText.setFillColor((sf::Color::Red)); vitalityText.setPosition(1415,500);

    sf::Text wavePopup("Wave 1", font, 100); wavePopup.setFillColor((sf::Color::Red)); wavePopup.setPosition(475,250);
    sf::Text waveIndicator("Wave 1", font, 25); waveIndicator.setFillColor((sf::Color::Red)); waveIndicator.setPosition(1230,302);
    sf::Text mouseX(" ", font, 25); mouseX.setFillColor((sf::Color::Red)); mouseX.setPosition(10,10);
    sf::Text mouseY(" ", font, 25); mouseY.setFillColor((sf::Color::Red)); mouseY.setPosition(10,40);

    bool showWavePopup = true; sf::Clock gameClock; float waveTimer; float waveDelay = 3; ///Wave counter data

    ///Shapes initialized
    sf::RectangleShape sidebar(sf::Vector2f(400.f, 800.f)); sidebar.setPosition(1200,0); sidebar.setFillColor(sf::Color::Black); 
    sf::RectangleShape miniDude(sf::Vector2f(25.f, 25.f)); miniDude.setFillColor(sf::Color::Yellow); miniDude.setPosition(475,475);

    float mapscale = 1.0/3.0; 
     ///map.scale(mapscale,mapscale); ///Map scaled for the minimap
     bossRoom.scale(mapscale,mapscale);

    while (window.isOpen()) {
        switch (state){
            case STARTSCREEN: { ///On start

                sf::Event move{};
                while (window.pollEvent(move)) { if (move.type == sf::Event::Closed) { window.close(); } } ///Close logic

                ///Startscreen draw logic
                
                window.draw(startScreen); window.draw(pauseHelp);

                sf::Vector2i mvec = sf::Mouse::getPosition(window);
                    if( mvec.x > 435 && mvec.x < 1139){ 
                        if(mvec.y > 528 && mvec.y < 695) { 
                            window.draw(highLight);
                            if (sf::Mouse::isButtonPressed(mouse.Left)) { ///Button 'click' logic
                                state = GAMEPLAY;
                            }
                        }
                    }

                mouseX.setString(std::to_string(mvec.x));
                mouseY.setString(std::to_string(mvec.y));

                window.draw(mouseX); window.draw(mouseY);

                window.display();

            break; }

            case GAMEPLAY: { ///On gameplay

                window.clear(sf::Color::Black);

                sf::Event move{};
                while (window.pollEvent(move)) { if (move.type == sf::Event::Closed) { window.close(); } } ///Close logic

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {state = PAUSE; } ///Pause logic

                if (!b->isMoving){ c->walk2 = true;} /// Allows the user to move

                b->isMoving = false; b->dx = 0; b->dy = 0; ///Walk logic
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { b->isMoving = true; b->dx = 1; c->lastDirection = 'R'; }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { b->isMoving = true; b->dx = -1; c->lastDirection = 'L';}
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { b->isMoving = true; b->dy = 1; c->lastDirection = 'U'; }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { b->isMoving = true; b->dy = -1; c->lastDirection = 'D';}

                if (c->isShooting){ ///Character sprite animation logic
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
                if (sf::Mouse::isButtonPressed(mouse.Left)){ ///Character shooting logic
                    if (c->canShoot){
                        Arrow *a = new Arrow();
                        a->shotSpeed = c->shotSpeed; a->minDamage = c->minDamage;a->maxDamage = c->maxDamage; a->range = c->range;
                        sf::Vector2i mvec = sf::Mouse::getPosition(window); ///Mouse position in vector form
                        mousePos.at(0) = mvec.x - (0.4*window.getSize().x); ///Mouse position relative to the character
                        mousePos.at(1) = mvec.y - (0.46875*window.getSize().y) - 25;
                        if (mousePos.at(0) < 0) { ///If x is negative
                            arrowSprite.setScale(-0.2, -0.2); ///Flop the arrow on x and y axis
                            a->backwards = true;
                            a->settings(arrowSprite, 610, 425, (atan(mousePos.at(1) / mousePos.at(0)) * 57.29));
                        } else {
                            arrowSprite.setScale(0.2, 0.2);
                            a->settings(arrowSprite, 620, 400, (atan(mousePos.at(1) / mousePos.at(0)) * 57.29));
                        }
                        entities.push_back(a); c->canShoot = false; c->shotTimer = 0; c->shot2 = true;
                    }
                    c->isShooting = true;
                }

                if (enemyCount <= enemyCap && !showWavePopup ){
                    if (rand() % c->enemySpawnSpeed == 0){ ///Enemy creation logic
                        if(rand() % 1 == 0){
                            BasicChaseEnemy *e = new BasicChaseEnemy();
                            int randX = rand() % 4800 - 2400; int randY = rand() % 4800 - 2400;
                            enemyCount += 1;
                            if (randX > 700 || randX < 500){
                                if(randY > 500 || randY < 300){
                                    e->settings(crystalEnemy, randX, randY, 0);
                                    
                                } else {
                                    e->isAlive = false;
                                }
                            }else {
                                e->isAlive = false;
                            }
                            entities.push_back(e);
                        } else {
                            BasicRangedEnemy *e = new BasicRangedEnemy();
                            int randX = rand() % 4800 - 2400; int randY = rand() % 4800 - 2400;
                            enemyCount += 1;
                            if (randX > 700 || randX < 500){
                                if(randY > 500 || randY < 300){
                                    e->settings(crystalShootey, randX, randY, 0);
                                } else {
                                    e->isAlive = false;
                                }
                            }else {
                                e->isAlive = false;
                            }
                            entities.push_back(e);
                            }   
                        }
                        
                    }

                    

                for (auto p:entities) { /// Basic Ranged Enemy Attack Logic
                    if (p->name == "enemy"){
                        if(p->type == "BRE"){
                            if(p->wantsToAttack){
                                EnemyProjectile *ep = new EnemyProjectile();
                                if ((p->x - 600) < 0) { ///If x is negative
                                    enemyShot.setScale(0.7, 0.7); ///Flop the arrow on x and y axis
                                    ep->backwards = true;
                                    ep->settings(enemyShot, p->x + 25, 25 + p->y, (atan(((p->y) - 375) / ((p->x) - 600)) * 57.29));
                                } else {
                                    enemyShot.setScale(-0.7, -0.7);
                                    ep->settings(enemyShot, p->x + 25, 25 + p->y, (atan(((p->y) - 375) / ((p->x) - 600)) * 57.29));
                                }
                                entities.push_back(ep);
                                p->wantsToAttack = false;
                            }
                        }
                    }
                }

                for (auto p:entities) { 
                    for (auto q:entities) { /// Enemy hit detection logic
                        sf::FloatRect aBox = p->sprite.getGlobalBounds();
                        sf::FloatRect eBox = q->sprite.getGlobalBounds();
                        if (p->name == "arrow" && p->isAlive){
                            if (q->name == "enemy" && q->isAlive){
                                if (aBox.intersects(eBox)){
                            
                                    int damageNow = rand() % (p->maxDamage-p->minDamage + c->attack) + (p->maxDamage + c->attack);
                                    MovingText *mov = new MovingText();
                                    mov->text.setPosition(q->x + 30, q->y - 10);
                                    mov->text.setFont(font); mov->text.setFillColor(sf::Color::Red);
                                    mov->text.setCharacterSize(20);
                                    if (c->critChance != 0){
                                        if ((rand() % (100/c->critChance) == 0) || c->critChance == 100){
                                            damageNow *= ((c->critDamage + 100) / 100);
                                            mov->text.setFillColor(sf::Color::Yellow);
                                            mov->text.setCharacterSize(40);
                                        }
                                    }
                                    q->health -= damageNow;
                                    p->isAlive = false;
                                    mov->text.setString(std::to_string(damageNow));
                                    entities.push_back(mov);
                                }
                            }
                        }
                    }
                }

                gold.setString(std::to_string(c->goldCount)); /// Sets gold count to gold count

                for (auto i = entities.begin(); i != entities.end();) { ///Entity update logic
                    Entity *e = *i; //*i is an Entity pointer, using * on an iterator returns the element from the list
                    e->update(); // Uses polymorphism to call the proper update method
                    if (!e->isAlive) {
                        i = entities.erase(i); 
                        if(e->name == "enemy"){
                             enemyCount -= 1;
                        }
                        delete e; 
                    } else {
                        i++;
                    } //Move iterator to the next element in the list
                }
                
                for (auto i:entities) { ///Draw Logic
                    if (i->name == "arrow" || "enemy" || "movingText" || "eproj"){
                        i->pDX = b->speed*b->dx; i->pDY = b->speed*b->dy;
                    }
                    i->draw(window);
                }

                ///Default UI creation and setup
                attackText.setString(std::to_string(c->attack)); dexterityText.setString(std::to_string(c->dexterity));
                damageText.setString(std::to_string(c->minDamage) + " - " + std::to_string(c->maxDamage));
                critChanceText.setString(std::to_string(c->critChance) + "%"); critDamageText.setString("+" + std::to_string(c->critDamage) + "%");
                speedText.setString(std::to_string(b->speed));

                window.draw(sidebar); window.draw(rightSide);

                goldenEntity->draw(window); c->draw(window); window.draw(gold);
                window.draw(attackOnBar); window.draw(dexterityOnBar);
                window.draw(damageOnBar); window.draw(critChanceOnBar); window.draw(critDamageOnBar);
                window.draw(attackText); window.draw(dexterityText); window.draw(damageText);
                window.draw(critChanceText); window.draw(critDamageText);
                window.draw(speedText); window.draw(speedOnBar);
                window.draw(vitalityText); window.draw(vitalityOnBar);
                window.draw(waveIndicator);
                

                sf::Vector2i mvec = sf::Mouse::getPosition(window);
                mouseX.setString(std::to_string(mvec.x));
                mouseY.setString(std::to_string(mvec.y));

                window.draw(mouseX); window.draw(mouseY);

                if (showWavePopup){ ///Wave popup logic
                    float waveTime = gameClock.getElapsedTime().asSeconds(); gameClock.restart();
                    waveTimer += waveTime;
                    window.draw(wavePopup); 
                    if (waveTimer > waveDelay){showWavePopup = false;}
                }

                ///Minimap drawing
                window.setView(miniMap);
                ///map.setPosition(((b->x)/3) + 285, ((b->y)/3) + 353);
                bossRoom.setPosition(((b->x)/3) + 285, ((b->y)/3) + 353);
                ///window.draw(map); 
                window.draw(bossRoom); 
                window.draw(miniDude);
                for (auto i:entities) { if (i->name == "enemy"){window.draw(i->miniEnemy);}}
                window.setView(window.getDefaultView());

                window.display();

                break; }

            case PAUSE: { ///Pause logic
                sf::Event move{};
                while (window.pollEvent(move)) { if (move.type == sf::Event::Closed) {window.close(); } } ///Window close logic
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) { state = GAMEPLAY; } ///Back to game logic

                window.draw(upBackground);

                sf::Vector2i mvec = sf::Mouse::getPosition(window);
                mouseX.setString(std::to_string(mvec.x));
                mouseY.setString(std::to_string(mvec.y));

                window.draw(mouseX); window.draw(mouseY);

                uppy.setPosition(451, 416); window.draw(uppy);
                uppy.setPosition(674, 467); window.draw(uppy);
                uppy.setPosition(934, 549); window.draw(uppy);
                uppy.setPosition(1201, 397); window.draw(uppy);
                uppy.setPosition(1265, 620); window.draw(uppy);

                upgBoard.setPosition(450, 35); window.draw(upgBoard);

                goldenEntity->sprite.setPosition(100,100);
                goldenEntity->draw(window);window.draw(gold);window.draw(pause);


                window.display();

                break;}
        }
    }
    return 0;
}