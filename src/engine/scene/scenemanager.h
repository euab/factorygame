#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <unordered_map>

#include "engine/scene/scenegraphnode.h"
#include "engine/scene/scene.h"

class SceneManager
{
public:
    SceneManager();
    ~SceneManager();

    // Add a new scene to the scene manager. Takes a string name of the scene
    // and a shared pointer to the scene instance.
    void addScene(const std::string &name, std::shared_ptr<Scene> scene);

    // Get the root node of the scene.
    std::shared_ptr<Node> getSceneRoot();

    // Load in a new scene. Takes the name of the scene to switch to.
    void swapScene(const std::string &name);

private:
    std::shared_ptr<Scene> m_currScene;
    std::unordered_map<std::string, std::shared_ptr<Scene>> m_scenes;
};

#endif // SCENEMANAGER_H
