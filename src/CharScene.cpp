//
// Created by ken-soares on 10/03/2024.
//

#include "CharScene.h"

CharScene::CharScene() = default;
CharScene::~CharScene() = default;

void CharScene::loadResources() {
    std::shared_ptr<Char> character = std::make_shared<Char>();
    int sceneWidth = GetScreenWidth();
    character->position = Vector2{(float)sceneWidth / 2, (float)groundYpos};
    playerAvatar = character;
    actors.emplace_back(character);
}
