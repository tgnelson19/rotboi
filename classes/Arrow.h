//
// Created by Tyler on 6/15/2021.
//

#ifndef ROTBOI_ARROW_H
#define ROTBOI_ARROW_H

#include "Entity.h"
#include "Character.h"


class Arrow : public Entity{

public:

    float shotSpeed;
    float damage;
    bool backwards;


    Arrow() { name = "arrow"; backwards = false;}

    void update() {
        sprite.setRotation(angle);

        if (backwards) {
            x -= shotSpeed * cos(dtr * angle);
            y -= shotSpeed * sin(dtr * angle);
        } else {
            x += shotSpeed * cos(dtr * angle);
            y += shotSpeed * sin(dtr * angle);
        }

        x -= pDX; y+= pDY;

        if (x > W || x < 0 || y > H || y < 0) {
            isAlive = false; // If it hits a wall, kills the bullet
        }
    }

};


#endif //ROTBOI_ARROW_H
