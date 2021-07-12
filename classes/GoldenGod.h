#ifndef ROTBOI_GOLDENGOD_H
#define ROTBOI_GOLDENGOD_H

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Character.h"

class GoldenGod : public Enemy{
public:

enum states {FPHASE, SPHASE, RAGE}; 
states state;

GoldenGod(){
    isAlive = true;
    type = "goldgod";
    states state = FPHASE;
    health = 10000;
    maxHealth = 10000;
}

void update(){

    if (health > (maxHealth / 2)){
        state = FPHASE;
    } else if (health > (maxHealth / 10)){
        state = SPHASE;
    } else {
        state = RAGE;
    }




    if (state == FPHASE){
        




    }
    















}









};











#endif //ROTBOI_GOLDENGOD_H