//
// Created by ken-soares on 08/03/2024.
//

#ifndef EXAMPLE_COMMANDLISTENER_H
#define EXAMPLE_COMMANDLISTENER_H


class CommandListener {
public:
    CommandListener();
    virtual ~CommandListener();

    virtual void goLeft();
    virtual void goRight();
    virtual void goUp();
    virtual void goDown();
    virtual void goNowhere();
};


#endif//EXAMPLE_COMMANDLISTENER_H
