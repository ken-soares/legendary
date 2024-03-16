//
// Created by ken-soares on 10/03/2024.
//

#ifndef EXAMPLE_CHARSCENE_H
#define EXAMPLE_CHARSCENE_H

#include "Scene.h"
#include "Char.h"

class CharScene : public Scene{
public:
    CharScene();
    virtual ~CharScene();
    virtual void loadResources();
};


#endif//EXAMPLE_CHARSCENE_H
