//
// Created by ken-soares on 10/03/2024.
//

#ifndef EXAMPLE_ACTOR_H
#define EXAMPLE_ACTOR_H

#include "CommandListener.h"
#include "raylib.h"

class Actor : public CommandListener {
public:
    Actor();
    virtual ~Actor();

    /** Updates this actor's state.
    * This could include the animation state, triggering of sound effects, etc.
    *
    * IMPORTANT: Physics simulation is handled at the scene level.
    *
    * @param onGround true if the actor is on the ground/floor, and false if
    * he/she/it is airborne
    *
    * @return bool true if this actor still exists, and false if it has "exited
    * the scene, never to return" (eg. dead)
    */
     virtual bool update(bool onGround);

     // draws the actor to the display
     virtual void draw();

     // return the bounding Rectangle of the actor in world coordinates
     virtual Rectangle getBoundingBox();

     Vector2 position;
     Vector2 velocity;
};


#endif//EXAMPLE_ACTOR_H
