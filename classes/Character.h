//
// Created by Tyler on 6/15/2021.
//

#ifndef ROTBOI_CHARACTER_H
#define ROTBOI_CHARACTER_H

#include "Entity.h"


class Character : public Entity{
public:

    bool isMoving;
    bool isShooting;
    char shotDirection;
    float dx, dy;

    Character(){ name = "character"; isMoving = false;}

    void update() {

        if (dx == 1 && dy == 0){ angle = 0 ;}
        if (dx == 1 && dy == 1){ angle = 45 ;}
        if (dx == 0 && dy == 1){ angle = 90 ;}
        if (dx == -1 && dy == 1){ angle = 135 ;}
        if (dx == -1 && dy == 0){ angle = 180 ;}
        if (dx == -1 && dy == -1){ angle = 225 ;}
        if (dx == 0 && dy == -1){ angle = 270 ;}
        if (dx == 1 && dy == -1){ angle = 315 ;}

        if (isMoving){
            x += speed*cos(dtr * angle);
            y -= speed*sin(dtr * angle);
        }

        if(x > W) x = W;
        if(x < 0) x = 0;
        if(y > H) y = H;
        if(y < 0) y = 0;
    }

};


#endif //ROTBOI_CHARACTER_H
