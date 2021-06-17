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

    Enemy(){ name = "enemy"; isAlive = true; speed = 2;}

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

    }

};


#endif //ROTBOI_ENEMY_H
