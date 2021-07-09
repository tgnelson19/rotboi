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
#include "classes/Background.h"
#include "classes/MovingText.h"
 
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

    sf::Texture bg, arrowTexture, Inventory, Stats, CrystalBoi, GoldTexture, upgradedBowShot; /// Other textures initialized

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
    if (!GoldTexture.loadFromFile("images/gold.png")) { /// Released for non-commercial use by Oryx
        std::cout << "Error: Failed to load file" << std::endl;
        return EXIT_FAILURE;
    }
    if (!upgradedBowShot.loadFromFile("images/dBowShot.png")) { /// Created by Deca Games
        std::cout << "Error: Failed to load file" << std::endl;
        return EXIT_FAILURE;
    }

    sf::Sprite map(bg), arrowSprite(arrowTexture), crystalEnemy(CrystalBoi), goldIcon(GoldTexture); ///Mkaing basic sprites

    enum states {STARTSCREEN, GAMEPLAY, PAUSE}; states state = STARTSCREEN; ///Enumerations for game states

    sf::RenderWindow window(sf::VideoMode(W, H), "rotboi"); ///Main window initialized

    window.setFramerateLimit(60); /// Limits framerate

    std::vector<Entity *> entities; ///Entity list to interate through

    sf::Mouse mouse; std::vector<float> mousePos = {0, 0}; ///Mouse position

    sf::Font font;
    if (!font.loadFromFile("fonts/Oswald-Bold.ttf")) { /// Free for commercial use from fontsquirrel.com
        return EXIT_FAILURE;
    }

    sf::View miniMap; miniMap.setViewport(sf::FloatRect(0.805f, 0.008f, 0.19f, 0.35f)); ///Makes a minimap

    Background *b = new Background(); /// Background entity
    map.scale(60,60);
    b->settings(map, -40000, -40000, 0);
    b->speed = 6;
    entities.push_back(b);

    Character *c = new Character(); ///Character entity
    c->settings(cFNW, 600, 375, 0);
    entities.push_back(c);

    Entity *goldenEntity = new Entity(); ///Gold entity
    goldIcon.setScale(0.75, 0.75);
    goldenEntity->settings(goldIcon, 1050, 10, 0);
    entities.push_back(goldenEntity);

    ///Texts initialized
    sf::Text gold("0", font, 30); gold.setFillColor(sf::Color::White); gold.setPosition(1100, 15);
    sf::Text startText("Welcome to ROTBOI!", font, 50); startText.setFillColor(sf::Color::Black); startText.setPosition(550, 200);
    sf::Text pauseHelp("Pause with the Escape key | Unpause with the Tab key", font, 25); pauseHelp.setFillColor(sf::Color::Black); pauseHelp.setPosition(460, 700);
    sf::Text pause("Paused | Unpause with the Tab key", font, 50); pause.setFillColor(sf::Color::Black); pause.setPosition(400, 700);
    sf::Text playButtonText("Play", font, 50); playButtonText.setFillColor(sf::Color::Black); playButtonText.setPosition(700, 475);
    sf::Text dexterityUpgradeText("Dexterity", font, 50); dexterityUpgradeText.setFillColor(sf::Color::Yellow); dexterityUpgradeText.setPosition(100,100);
    sf::Text attackUpgradeText("Attack", font, 50); attackUpgradeText.setFillColor((sf::Color::Magenta)); attackUpgradeText.setPosition(100,200);
    sf::Text attackOnBar("Attack", font, 20); attackOnBar.setFillColor((sf::Color::Magenta)); attackOnBar.setPosition(1220,310);
    sf::Text dexterityOnBar("Dexterity", font, 20); dexterityOnBar.setFillColor((sf::Color::Yellow)); dexterityOnBar.setPosition(1220,340);
    sf::Text damageOnBar("Damage", font, 20); damageOnBar.setFillColor((sf::Color::Black)); damageOnBar.setPosition(1220,370);
    sf::Text critChanceOnBar("Crit Chance", font, 20); critChanceOnBar.setFillColor((sf::Color::Yellow)); critChanceOnBar.setPosition(1220,400);
    sf::Text critDamageOnBar("Crit Damage", font, 20); critDamageOnBar.setFillColor((sf::Color::Red)); critDamageOnBar.setPosition(1220,430);
    sf::Text attackText("0", font, 20); attackText.setFillColor((sf::Color::Magenta)); attackText.setPosition(1360,310);
    sf::Text dexterityText("0", font, 20); dexterityText.setFillColor((sf::Color::Yellow)); dexterityText.setPosition(1360,340);
    sf::Text damageText("0", font, 20); damageText.setFillColor((sf::Color::Black)); damageText.setPosition(1360,370);
    sf::Text critChanceText("0", font, 20); critChanceText.setFillColor((sf::Color::Yellow)); critChanceText.setPosition(1360,400);
    sf::Text critDamageText("0", font, 20); critDamageText.setFillColor((sf::Color::Red)); critDamageText.setPosition(1360,430);
    sf::Text wavePopup("Wave 1", font, 100); wavePopup.setFillColor((sf::Color::Red)); wavePopup.setPosition(475,250);
    sf::Text waveIndicator("Wave 1", font, 25); waveIndicator.setFillColor((sf::Color::Red)); waveIndicator.setPosition(10,10);

    bool showWavePopup = true; sf::Clock gameClock; float waveTimer; float waveDelay = 3; ///Wave counter data

    ///Shapes initialized
    sf::RectangleShape upgradeBackground(sf::Vector2f(1400.f, 500.f)); upgradeBackground.setPosition(50,66); 
    upgradeBackground.setFillColor(sf::Color::Black); upgradeBackground.setOutlineColor(sf::Color::Blue);
    sf::RectangleShape openingButton(sf::Vector2f(400.f, 200.f));openingButton.setPosition(550, 400); 
    openingButton.setFillColor(sf::Color::Blue); openingButton.setOutlineColor(sf::Color::Magenta);
    sf::RectangleShape sidebar(sf::Vector2f(400.f, 800.f)); sidebar.setPosition(1200,0); sidebar.setFillColor(sf::Color::Black);
    sf::RectangleShape statsOnBar(sf::Vector2f(280, 170.f)); statsOnBar.setPosition(1210,300); statsOnBar.setFillColor(sf::Color::Cyan);
    sf::RectangleShape miniDude(sf::Vector2f(25.f, 25.f)); miniDude.setFillColor(sf::Color::Yellow); miniDude.setPosition(475,475);

    float mapscale = 1.0/3.0; map.scale(mapscale,mapscale); ///Map scaled for the minimap

    while (window.isOpen()) {
        switch (state){
            case STARTSCREEN: { ///On start

                sf::Event move{};
                while (window.pollEvent(move)) { if (move.type == sf::Event::Closed) { window.close(); } } ///Close logic

                if (sf::Mouse::isButtonPressed(mouse.Left)) { ///Button 'click' logic
                    sf::Vector2i mvec = sf::Mouse::getPosition(window);
                    if( mvec.x > (0.3666*window.getSize().x) && mvec.x < (0.63333*window.getSize().x)){ if(mvec.y > (0.5*window.getSize().y) && mvec.y < (0.75*window.getSize().y)) { state = GAMEPLAY;}}
                }

                window.clear(sf::Color::Cyan); ///Startscreen draw logic
                window.draw(openingButton);window.draw(startText);window.draw(playButtonText);window.draw(pauseHelp);
                window.display();

            break; }

            case GAMEPLAY: { ///On gameplay

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

                if (rand() % 25 == 0){ ///Enemy creation logic
                    Enemy *e = new Enemy();
                    int randX = rand() % 4800 - 2400; int randY = rand() % 4800 - 2400;
                    if (randX > 700 || randX < 500){
                        if(randY > 500 || randY < 300){
                            e->settings(crystalEnemy, randX, randY, 0);
                            entities.push_back(e);
                        } else {
                            e->isAlive = false;
                        }
                    }else {
                        e->isAlive = false;
                    }
                }

                for (auto p:entities) { /// Enemy hit detection logic
                    for (auto q:entities) {
                        if (p->name == "arrow"){
                            if (q->name == "enemy"){
                                sf::FloatRect aBox = p->sprite.getGlobalBounds();
                                sf::FloatRect eBox = q->sprite.getGlobalBounds();
                                if (aBox.intersects(eBox)){
                                    int damageNow = rand() % (p->maxDamage-p->minDamage) + p->maxDamage;
                                    MovingText *mov = new MovingText();
                                    mov->text.setPosition(q->x + 30, q->y - 10);
                                    mov->text.setFont(font); mov->text.setFillColor(sf::Color::Red);
                                    mov->text.setCharacterSize(20);
                                    if (c->critChance == 0){break;}
                                    else if ((rand() % (100/c->critChance) == 0) || c->critChance == 100){
                                        damageNow *= ((c->critDamage + 100) / 100);
                                        mov->text.setFillColor(sf::Color::Yellow);
                                        mov->text.setCharacterSize(40);
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
                    if (!e->isAlive) {i = entities.erase(i); delete e;} else i++; //Move iterator to the next element in the list
                }
                for (auto i:entities) { ///Draw Logic
                    if (i->name == "arrow" || i->name == "enemy" || i->name == "movingText"){
                        i->pDX = b->speed*b->dx; i->pDY = b->speed*b->dy;
                    }
                    i->draw(window);
                }

                ///Default UI creation and setup
                attackText.setString(std::to_string(c->attack)); dexterityText.setString(std::to_string(c->dexterity));
                damageText.setString(std::to_string(c->minDamage) + " - " + std::to_string(c->maxDamage));
                critChanceText.setString(std::to_string(c->critChance) + "%"); critDamageText.setString("+" + std::to_string(c->critDamage) + "%");
                goldenEntity->draw(window); c->draw(window); window.draw(gold); window.draw(sidebar);
                window.draw(statsOnBar); window.draw(attackOnBar); window.draw(dexterityOnBar);
                window.draw(damageOnBar); window.draw(critChanceOnBar); window.draw(critDamageOnBar);
                window.draw(attackText); window.draw(dexterityText); window.draw(damageText);
                window.draw(critChanceText); window.draw(critDamageText);
                window.draw(waveIndicator);

                if (showWavePopup){ ///Wave popup logic
                    float waveTime = gameClock.getElapsedTime().asSeconds(); gameClock.restart();
                    waveTimer += waveTime;
                    window.draw(wavePopup); 
                    if (waveTimer > waveDelay){showWavePopup = false;}
                }

                ///Minimap drawing
                window.setView(miniMap);
                map.setPosition(((b->x)/3) + 285, ((b->y)/3) + 353);
                window.draw(map); window.draw(miniDude);
                for (auto i:entities) { if (i->name == "enemy"){window.draw(i->miniEnemy);}}
                window.setView(window.getDefaultView());

                window.display();

                break; }

            case PAUSE: { ///Pause logic
                sf::Event move{};
                while (window.pollEvent(move)) { if (move.type == sf::Event::Closed) {window.close(); } } ///Window close logic
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) { state = GAMEPLAY; } ///Back to game logic
                window.clear(sf::Color::Cyan); ///Drawing the pause screen
                goldenEntity->draw(window);window.draw(gold);window.draw(upgradeBackground);
                window.draw(dexterityUpgradeText);window.draw(attackUpgradeText);window.draw(pause);
                window.display();
                break;}
        }
    }
    return 0;
}