//
// Created by ken-soares on 10/03/2024.
//

#include "Actor.h"

Actor::Actor() = default;
Actor::~Actor() = default;

bool Actor::update(bool onGround) {
    return true;
}

void Actor::draw() {
    DrawText("Override Actor::draw()", 300,300,14,RED);
}

Rectangle Actor::getBoundingBox() {
    return Rectangle {position.x, position.y};
}
