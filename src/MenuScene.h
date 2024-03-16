//
// Created by ken-soares on 13/03/2024.
//

#ifndef GAME_MENUSCENE_H
#define GAME_MENUSCENE_H

#include "Scene.h"

class MenuScene : public Scene {
public:
    MenuScene();
    ~MenuScene();
    virtual void draw();
    virtual std::shared_ptr<Scene> update();

    [[nodiscard]] bool getCanPlay() const;
    void setCanPlay(bool value);
private:
    bool canPlay = false;
};


#endif//GAME_MENUSCENE_H
