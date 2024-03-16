#include <stdexcept>
#include "raylib.h"
#include "raymath.h"

#include "InputHandler.h"
#include "CharScene.h"
#include "MenuScene.h"

#include "Globals.h"

void displayErrorMsg(const char *errorMsg) {
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText(errorMsg, 300,300,14,RAYWHITE);
        EndDrawing();
    }

    exit(EXIT_FAILURE);
}

int main() {


    int return_value = EXIT_SUCCESS;

    InitWindow(screenWidth, screenHeight, "Raylib game");
    InitAudioDevice();

    try {
        InputHandler inputHandler;

        std::shared_ptr<Scene> currScene = std::make_shared<MenuScene>();
        currScene->loadResources();
        currScene->start();

        SetTargetFPS(60);

        while(!WindowShouldClose()) {
            inputHandler.handleInput(*currScene);
            auto nextScene = currScene->update();

            if (currScene->getShouldQuit()) {
                break;
            }

            if (nextScene) {
                nextScene->loadResources();
                nextScene->start();
                currScene = nextScene;
            }

            // Draw
            BeginDrawing();
            currScene->draw();
            EndDrawing();
        }

    } catch (std::runtime_error &e) {
        displayErrorMsg(e.what());
        return_value = EXIT_FAILURE;
    }

    CloseAudioDevice();
    CloseWindow();

    return return_value;
}