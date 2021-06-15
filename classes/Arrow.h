//
// Created by Tyler on 6/15/2021.
//

#ifndef ROTBOI_ARROW_H
#define ROTBOI_ARROW_H

#include "Entity.h"


class Arrow : public Entity{

public:

    float shotSpeed;
    float damage;

    Arrow() { name = "arrow"; }

    void update() {
        x += shotSpeed * cos(dtr*angle);
        y -= shotSpeed * sin(dtr*angle);

        if (x > W || x < 0 || y > H || y < 0) {
            isAlive = false; // If it hits a wall, kills the bullet
        }
    }

};


#endif //ROTBOI_ARROW_H
