//
// Created by ken-soares on 07/03/2024.
//

#include "InputHandler.h"
#include "CommandListener.h"
#include "raylib.h"
#include <iostream>

// trivial constructor and destructor
InputHandler::InputHandler() = default;
InputHandler::~InputHandler() = default;

void InputHandler::handleInput(CommandListener &listener) {

    // left right movement
    if (IsKeyDown(KEY_LEFT)) {
        listener.goLeft();
    }else if (IsKeyDown(KEY_RIGHT)) {
        listener.goRight();
    } else {
        listener.goNowhere();
    }

    if (IsKeyPressed(KEY_UP)) {
        listener.goUp();
    }

    if(IsKeyPressed(KEY_ENTER) && (IsKeyDown(KEY_LEFT_ALT) || IsKeyDown(KEY_RIGHT_ALT))) {
        listener.goFullScreen();
    }

}