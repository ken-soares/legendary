//
// Created by ken-soares on 08/03/2024.
//

#ifndef EXAMPLE_SCENE_H
#define EXAMPLE_SCENE_H

#include "CommandListener.h"
#include "Globals.h"
#include <memory>
#include <list>
#include <iostream>

class Actor;

/** Base class for "scenes."
 * A scene is a "place where action occurs." It can be a title screen, a loading screen,
 * a cut-scene, or an entire world in which players, actors, and other objects interact.
 *
 * At a technical level, a scene loads and manages all objects that exist in a scene. It
 * processes or passes on user inputs to the relevant objects, and performs any simulation,
 * Artificial Intelligence (AI) calculations, etc., that are needed to display the scene.
 * Scenes can also have audio.
 *
 * Child classes can set the playerAvatar, which is the object that user input will be
 * forwarded, unless the command methods (e.g., goRight()) are overridden.
 */

class Scene : public CommandListener {
public:
    Scene();
    virtual ~Scene();

    // Loads the resources needed to display this scene (e.g., the entire game level).
    // @throws std::runtime_error if something goes wrong
    virtual void loadResources();

    //Frees up the resources used in this scene.
    // The default behaviour is to empty this object of all items, e.g., the actors, playerAvatar, etc.
    virtual void freeResources();

    // called when a scene starts
    // takes care of everything not in the loadResources() method (music, etc.)
    virtual void start();

    /* Updates the scene.
     * This should perform tasks such as:
     * - Perform any Artificial Intelligence (AI) calculations
     * - Update animation
     * - Simulate the world, including triggering sound effects & maybe changing the music
     * @return std::shared_ptr<Scene> the next scene, or nullptr if this scene
     */
    virtual std::shared_ptr<Scene> update();


    // draws the scene to display
    virtual void draw();

    virtual void goUp();
    virtual void goLeft();
    virtual void goDown();
    virtual void goRight();
    virtual void goNowhere();
    virtual void goFullScreen();

    void setShouldQuit(bool value);
    bool getShouldQuit();
protected:

    bool shouldQuit = false;
    std::shared_ptr<CommandListener> playerAvatar;

    float gravity;
    int groundYpos;

    // all the actors of the current scene
    // NB: the player should also be in the actos list
    std::list<std::shared_ptr<Actor>> actors;
};


#endif//EXAMPLE_SCENE_H
