//
// Created by Tyler on 6/15/2021.
//

#ifndef ROTBOI_ENTITY_H
#define ROTBOI_ENTITY_H
#include <SFML/Graphics.hpp>
#include <cmath>

static float W = 1500;
static float H = 800;

const float dtr = 0.017453f;

class Entity {
public:
    float x, y; /// Position on the screen
    float pDX, pDY;
    float health;
    float maxHealth;
    int minDamage;
    int maxDamage;
    float speed, angle; /// Speed of an entity will be based off of POLAR coordinate system, not cartesian
    bool isAlive; /// Determines if entity is alive
    std::string name; /// Determines which entity it is
    sf::Sprite sprite; /// Gives the entity a sprite
    sf::RectangleShape miniEnemy;
    std::string type;
    bool wantsToAttack;

    Entity() { isAlive = true; } /// Default Constructor

    void settings(sf::Sprite &s, float X, float Y, float Angle) { sprite = s; x = X; y = Y; angle = Angle; } /// Changes Settings

    virtual void update() {}; /// Used for future derived classes

    virtual void draw(sf::RenderWindow &app){ /// Draws current entity to the screen
        sprite.setPosition(x,y);
        app.draw(sprite);
    }

    virtual ~Entity() {}; /// Used for future derived classes
    };


#endif //ROTBOI_ENTITY_H
