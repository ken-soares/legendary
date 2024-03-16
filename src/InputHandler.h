//
// Created by ken-soares on 07/03/2024.
//

#ifndef EXAMPLE_INPUTHANDLER_H
#define EXAMPLE_INPUTHANDLER_H

class CommandListener;

class InputHandler {
public:
    InputHandler();
    ~InputHandler();
    void handleInput(CommandListener &listener);
private:
};


#endif//EXAMPLE_INPUTHANDLER_H
