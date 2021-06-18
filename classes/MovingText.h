//
// Created by Tyler on 6/17/2021.
//

#ifndef ROTBOI_MOVINGTEXT_H
#define ROTBOI_MOVINGTEXT_H

#include "Entity.h"


class MovingText :public Entity{
public:
    sf::Text text;
    sf::Clock gameClock;
    float lifeTimer;

    MovingText(){
        name = "movingText"; isAlive = true;
    }

    void update(){
        float lifeTime = gameClock.getElapsedTime().asSeconds();
        lifeTimer += lifeTime;

        if (pDX != 0 && pDY != 0){
            pDX /= sqrt(2); pDY /= sqrt(2);
        }

        if (lifeTime < 0.3){
            text.setPosition(text.getPosition().x - pDX, text.getPosition().y - 4 + pDY);
        } else {
            isAlive = false;
        }

    }

    void draw(sf::RenderWindow &app){
        app.draw(text);
    }

};


#endif //ROTBOI_MOVINGTEXT_H
