#ifndef ROTBOI_BASICCHASEENEMY_H
#define ROTBOI_BASICCHASEENEMY_H

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Character.h"


class BasicChaseEnemy : public Enemy {

public:

BasicChaseEnemy(){
    type = "BCE"; speed = 2; health = 1000; maxHealth = 1000;
}


void update() {

        if ( x > 0 && x < 1200){
            if ( y > 0 && y < 800){
                if (x > 601){
                    angle = atan((y-375)/(x-600));
                    x -= speed*cos(angle);
                    y -= speed*sin(angle);
                } else if (x < 599){
                    angle = atan((y-375)/(x-600));
                    x += speed*cos(angle);
                    y += speed*sin(angle);
                }
            }
        }

        if ( (x < -despawnDistance) || (x > despawnDistance)) {
            isAlive = false;
        }
        if ((y < -despawnDistance) || (y > despawnDistance)) {
            isAlive = false;
        }

        if (pDX != 0 && pDY != 0){
            pDX /= sqrt(2); pDY /= sqrt(2);
        }

        x -= pDX; y+= pDY;

        if (health < 1) {
            isAlive = false;
            gold += 5;
        }

        healthbar.setSize(sf::Vector2f(60*(health/maxHealth), 6));

        miniEnemy.setPosition((x/3) + 285,(y/3) + 353);

    }








};

#endif //ROTBOI_BASICCHASEENEMY_H
