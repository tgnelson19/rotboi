//
// Created by Tyler on 6/17/2021.
//

#ifndef ROTBOI_MOVINGBOX_H
#define ROTBOI_MOVINGBOX_H

#include "Entity.h"


class MovingBox : public Entity {
public:
    sf::RectangleShape box;

    MovingBox(){name= "movingBox"}

    void update(){}

};


#endif //ROTBOI_MOVINGBOX_H
