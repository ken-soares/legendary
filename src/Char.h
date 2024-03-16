//
// Created by ken-soares on 10/03/2024.
//

#ifndef EXAMPLE_CHAR_H
#define EXAMPLE_CHAR_H

#include "Actor.h"

class Char : public Actor{
public:
    Char();
    virtual ~Char();
    virtual bool update(bool onGround);
    virtual void draw();
    virtual Rectangle getBoundingBox();
    virtual void goUp();
    virtual void goLeft();
    virtual void goRight();
    virtual void goDown();
    virtual void goNowhere();

private:
    Vector2 getUpperLeftPosition();
    Texture2D texture{};
    Sound landingSound{};


    // animation State
    unsigned numFrames;
    int frameWidth;
    unsigned frameDelay;
    unsigned frameDelayCounter;
    unsigned frameIndex;
    Rectangle frameRect{};

    float jumpSpeed;
    float walkSpeed;
    bool isGrounded;
};


#endif//EXAMPLE_CHAR_H
