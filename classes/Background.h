//
// Created by Tyler on 6/16/2021.
//

#ifndef ROTBOI_BACKGROUND_H
#define ROTBOI_BACKGROUND_H

#include "Entity.h"


class Background : public Entity{
public:

    bool isMoving;
    bool isShooting;
    char shotDirection;
    float dx, dy;

    Background(){ name = "background"; isAlive = true;

        sf::Texture bg;
        if (!bg.loadFromFile("images/World1.png")) { /// Released for non-commercial use by Oryx
            std::cout << "Error: Failed to load file" << std::endl;
        }
        sf::Sprite mapSprite(bg);

        sprite = mapSprite;

    }

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
            x -= speed*cos(dtr * angle);
            y += speed*sin(dtr * angle);
        }
    }


};


#endif //ROTBOI_BACKGROUND_H
