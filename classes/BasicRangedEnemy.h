#ifndef ROTBOI_BASICRANGEDENEMY_H
#define ROTBOI_BASICRANGEDENEMY_H

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Character.h"


class BasicRangedEnemy : public Enemy {

public:


float sightDistance;
sf::Clock gClock;
float attackDelay;
float attackTimer;
bool isMoving;

BasicRangedEnemy(){
    type = "BRE"; speed = 2; health = 500; maxHealth = 500; wantsToAttack = false; sightDistance = 300; attackDelay = 2; attackTimer = 0; isMoving = true;
}


void update() {

    float attackTime = gClock.getElapsedTime().asSeconds();
    attackTimer += attackTime; 
    gClock.restart(); attackTime = 0;

        if ( x > -100 && x < 1300){
            if ( y > -100 && y < 900){
                
                if ( sqrt(((x-600)*(x-600)) + ((y-390)*(y-390))) < sightDistance){
                    isMoving = false;
                } 
                else if (x > 601){
                    angle = atan((y-375)/(x-600));
                    x -= speed*cos(angle);
                    y -= speed*sin(angle);
                    isMoving = true;
                } else if (x < 599){
                    angle = atan((y-375)/(x-600));
                    x += speed*cos(angle);
                    y += speed*sin(angle);
                    isMoving = true;
                }
            }
        }

        if (!isMoving){
            if(attackTimer > attackDelay){
                wantsToAttack = true;
                attackTimer = 0;
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
            gold += 7;
        }

        healthbar.setSize(sf::Vector2f(60*(health/maxHealth), 6));

        miniEnemy.setPosition((x/3) + 285,(y/3) + 353);

    }

};

#endif //ROTBOI_BASICRANGEDENEMY_H