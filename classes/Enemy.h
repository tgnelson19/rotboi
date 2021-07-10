//
// Created by Tyler on 6/15/2021.
//

#ifndef ROTBOI_ENEMY_H
#define ROTBOI_ENEMY_H

#include "Entity.h"
#include "Character.h"

class Enemy : public Entity{
public:
    bool isShooting;
    char shotDirection;
    float dx, dy;
    
    sf::RectangleShape healthbar;
    sf::RectangleShape hpbackground;
    

    int despawnDistance;

    Enemy(){
        name = "enemy"; isAlive = true;
        healthbar.setSize(sf::Vector2f(60.f, 6.f));
        hpbackground.setSize(sf::Vector2f(60.f, 6.f));
        miniEnemy.setSize(sf::Vector2f(25.f, 25.f));
        healthbar.setFillColor(sf::Color::Green);
        hpbackground.setFillColor(sf::Color::Red);
        miniEnemy.setFillColor(sf::Color::Red);
        despawnDistance = 2400;
    }

    

    void draw(sf::RenderWindow &app){

        sprite.setPosition(x,y);
        healthbar.setPosition(x + 20, y + 90);
        hpbackground.setPosition(x + 20, y + 90);
        app.draw(hpbackground); app.draw(healthbar); app.draw(sprite);

    }

};


#endif //ROTBOI_ENEMY_H
