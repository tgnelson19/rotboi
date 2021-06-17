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
    bool backwards;
    float range;


    Arrow() { name = "arrow"; backwards = false; damage = 3; range = 3;}

    void update() {
        sprite.setRotation(angle);

        if (backwards) {
            x -= shotSpeed * cos(dtr * angle);
            y -= shotSpeed * sin(dtr * angle);
        } else {
            x += shotSpeed * cos(dtr * angle);
            y += shotSpeed * sin(dtr * angle);
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


#endif //ROTBOI_ARROW_H
