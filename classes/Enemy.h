//
// Created by Tyler on 6/15/2021.
//

#ifndef ROTBOI_ENEMY_H
#define ROTBOI_ENEMY_H

#include "Entity.h"

class Enemy : public Entity{
public:
    bool isShooting;
    char shotDirection;
    float dx, dy;
    sf::RectangleShape healthbar;
    sf::RectangleShape hpbackground;

    Enemy(){
        name = "enemy"; isAlive = true; speed = 2; health = 1000; maxHealth = 1000;
        healthbar.setSize(sf::Vector2f(60.f, 6.f));
        hpbackground.setSize(sf::Vector2f(60.f, 6.f));
        miniEnemy.setSize(sf::Vector2f(25.f, 25.f));
        healthbar.setFillColor(sf::Color::Green);
        hpbackground.setFillColor(sf::Color::Red);
        miniEnemy.setFillColor(sf::Color::Red);
    }

    void update() {

        if (x > 601){
            angle = atan((y-375)/(x-600));
            x -= speed*cos(angle);
            y -= speed*sin(angle);
        } else if (x < 599){
            angle = atan((y-375)/(x-600));
            x += speed*cos(angle);
            y += speed*sin(angle);
        }

        if (pDX != 0 && pDY != 0){
            pDX /= sqrt(2); pDY /= sqrt(2);
        }

        x -= pDX; y+= pDY;

        if (health < 1) {
            isAlive = false;
        }

        healthbar.setSize(sf::Vector2f(60*(health/maxHealth), 6));

        miniEnemy.setPosition((x/3) + 285,(y/3) + 353);

    }

    void draw(sf::RenderWindow &app){

        sprite.setPosition(x,y);
        healthbar.setPosition(x + 20, y + 90);
        hpbackground.setPosition(x + 20, y + 90);
        app.draw(hpbackground);
        app.draw(healthbar);
        app.draw(sprite);

    }

};


#endif //ROTBOI_ENEMY_H
