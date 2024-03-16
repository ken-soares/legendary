//
// Created by ken-soares on 13/03/2024.
//

#include "MenuScene.h"
#include "CharScene.h"
#include "Globals.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

// Trivial constructor and destructor

MenuScene::MenuScene() = default;
MenuScene::~MenuScene() = default;

// getters and setters
bool MenuScene::getCanPlay() const {
    return canPlay;
}

void MenuScene::setCanPlay(bool value) {
    canPlay = value;
}

// override Scene methods
std::shared_ptr<Scene> MenuScene::update() {
    if(getCanPlay()) {
        return std::make_shared<CharScene>();
    } else {
        return nullptr;
    }
}

void MenuScene::draw() {

    int textSize = MeasureText("Game Name", 30);
    int xCenterText = screenWidth/2 - textSize/2;
    DrawText("Game Name", xCenterText, 100, 30, (Color){153, 230, 0, 255});
    Scene::draw();
    if (GuiButton((Rectangle){ (int)(screenWidth/2 - 100), 200, 200, 30 },"Play")){
        setCanPlay(true);
    }

    if(GuiButton((Rectangle) {(int)(screenWidth/2 - 100),250,200,30}, GuiIconText(ICON_DOOR, "Quit Game"))) {
        setShouldQuit(true);
    }
}