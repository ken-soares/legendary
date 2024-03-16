//
// Created by ken-soares on 10/03/2024.
//

#include "Char.h"

Char::Char() {

    texture = LoadTexture("../res/women/Enchantress/Run.png");
    landingSound = LoadSound("../res/sounds/jump.wav");

    // animation vars
    numFrames = 8;
    frameDelay = 3;
    frameDelayCounter = 0;
    frameIndex = 0;

    frameWidth = (int)(texture.width / numFrames);
    frameRect = Rectangle{0.0f, 0.0f, (float) frameWidth, (float) texture.height};

    walkSpeed = 8;
    jumpSpeed = 12;

    isGrounded = true;
}

Char::~Char() = default;

bool Char::update(bool onGround) {
    bool charMoving = (velocity.x != 0.0f || velocity.y != 0.0f);
    bool wasGrounded = isGrounded;
    isGrounded = onGround;

    if (isGrounded && !wasGrounded) {
        PlaySound(landingSound);
    }

    frameDelayCounter++;
    if (frameDelayCounter > frameDelay) {
        if (charMoving) {
            if (isGrounded) {

                frameIndex = (frameIndex + 1) % numFrames;

                // insert footstepSounds here if defined
            } else {
                // ...
            }
            frameRect.x = (float) (frameWidth * frameIndex);
        }
        frameDelayCounter = 0;
    }

    return true;
}


void Char::draw() {
    Vector2 ulPosition = getUpperLeftPosition();
    DrawTextureRec(texture, frameRect, ulPosition, WHITE);
}

Rectangle Char::getBoundingBox() {
    Vector2 ulPosition = getUpperLeftPosition();
    return Rectangle{ulPosition.x, ulPosition.y, (float) frameWidth, (float) texture.height};
}

void Char::goUp() {
    if (isGrounded) {
        velocity.y = -jumpSpeed;
    }
}

void Char::goLeft() {
    //if (isGrounded) {

    velocity.x = -walkSpeed;
    if (frameRect.width > 0) {
        frameRect.width = -frameRect.width;
    }
}

void Char::goRight() {
    //if (isGrounded) {

    velocity.x = walkSpeed;
    if (frameRect.width < 0) {
        frameRect.width = -frameRect.width;
    }
}

void Char::goDown() {
}

void Char::goNowhere() {
    velocity.x = 0.0f;
}

Vector2 Char::getUpperLeftPosition() {
    return Vector2{position.x - (float) frameWidth / 2, position.y - (float) texture.height};
}