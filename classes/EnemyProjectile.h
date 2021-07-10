#ifndef ROTBOI_ENEMYPROJECTILE_H
#define ROTBOI_ENEMYPROJECTILE_H

#include <SFML/Graphics.hpp>
#include "Entity.h"



class EnemyProjectile : public Entity {
public:

    float range;
    float shotSpeed;
    bool backwards;

    EnemyProjectile(){
        name = "eproj"; isAlive = true; backwards = false; range = 7; shotSpeed = 5;
    }

    void update(){
        sprite.setRotation(angle);

        if (backwards) {
            x += shotSpeed * cos(dtr * angle);
            y += shotSpeed * sin(dtr * angle);
        } else {
            x -= shotSpeed * cos(dtr * angle);
            y -= shotSpeed * sin(dtr * angle);
        }

        if (pDX != 0 && pDY != 0){
            pDX /= sqrt(2); pDY /= sqrt(2);
        }

        x-= pDX; y+= pDY;

        if (x > W || x < 0 || y > H || y < 0) {
            isAlive = false; // If it hits a wall, kills the bullet
        }

        range -= 0.15;

        if (range < 0) {
            isAlive = false;
        }
    }

};


#endif //ROTBOI_ENEMYPROJECTILE_H