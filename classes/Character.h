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
    bool isShooting;
    char shotDirection;
    bool canShoot;
    float shotTimer;
    float shotDelay;
    bool shot2;
    int goldCount;

    float damage;
    float shotSpeed;

    char lastDirection;

    bool walk2;
    sf::Clock gClock;
    float walkTimer, walkDelay;



    Character(){

        name = "character";
        isAlive = true;
        walkDelay = 0.2;
        shotDelay = 0.05;
        isShooting = false;
        canShoot = false;
        shot2 = false;

        damage = 1;
        shotSpeed = 13;

    }

    void update() {
        float walkTime = gClock.getElapsedTime().asSeconds();
        float shootTime = gClock.getElapsedTime().asSeconds();

        gClock.restart();

        walkTimer += walkTime;
        shotTimer += shootTime;

        if (shotTimer > shotDelay){
            canShoot = true;
        } else if (shotTimer > shotDelay/2){
            shot2 = false;
        }

        if (walkTimer > walkDelay){
            if (walk2) {
                walk2 = false;
            } else {
                walk2 = true;
            }
            walkTimer = 0;
        }
    }

};


#endif //ROTBOI_CHARACTER_H
