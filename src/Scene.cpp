//
// Created by ken-soares on 08/03/2024.
//

#include "Scene.h"

#include "Actor.h"
#include "raylib.h"
#include "raymath.h"


void Scene::setShouldQuit(bool value) {
    shouldQuit = value;
}

bool Scene::getShouldQuit() {
    return shouldQuit;
}

Scene::Scene() {
    int sceneHeight = GetScreenHeight();
    groundYpos = (3 * sceneHeight) / 4;
    gravity = 0.8f;
}

Scene::~Scene() {
    freeResources();
}

void Scene::loadResources() {
}

void Scene::freeResources() {
    playerAvatar.reset();// resets the owner of the playerAvatar CommandListener
    actors.clear();      // list of actors emptied
}

void Scene::start() {
}

std::shared_ptr<Scene> Scene::update() {

    for (auto &actor: actors) {

        actor->position = Vector2Add(actor->position, actor->velocity);
        auto boundingRect = actor->getBoundingBox();
        auto distToGround = (float) groundYpos - (boundingRect.y + boundingRect.height);
        bool isGrounded = (distToGround <= 0);

        if (isGrounded) {
            actor->velocity.y = 0;
            actor->position.y = groundYpos;
        } else {
            actor->velocity.y += gravity;
        }

        actor->update(isGrounded);
    }

    return nullptr;
}

void Scene::draw() {
    ClearBackground(RAYWHITE);

    // TODO: check if works
    if (!actors.empty()) {
        for (auto &actor: actors) {
            actor->draw();
        }
    } else {
        // DrawText("No actors, please override Scene::draw() or add actors", 20, 20, 30, RED);
    }
}

void Scene::goUp() {
    if (playerAvatar) {
        playerAvatar->goUp();
    }
}


void Scene::goLeft() {
    if (playerAvatar) {
        playerAvatar->goLeft();
    }
}

void Scene::goRight() {
    if (playerAvatar) {
        playerAvatar->goRight();
    }
}

void Scene::goDown() {
    if (playerAvatar) {
        playerAvatar->goDown();
    }
}

void Scene::goNowhere() {
    if (playerAvatar) {
        playerAvatar->goNowhere();
    }
}

void Scene::goFullScreen() {
    int display = GetCurrentMonitor();

    if (IsWindowFullscreen()) {
        SetWindowSize(screenWidth, screenHeight);
    } else {
        SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
    }

    ToggleFullscreen();
}