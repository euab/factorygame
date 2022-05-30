#include "engine/scene/scenegraphnode.h"
#include "engine/scene/scene.h"
#include "engine/scene/scenegraph.h"
#include "engine/scene/scenemanager.h"

#include <iostream>

SceneManager::SceneManager() : m_currScene(nullptr) { }

SceneManager::~SceneManager()
{
    // Send the exit signal to the current scene graph to unload all
    // of the assets.
    if (m_currScene != nullptr)
        m_currScene->destroy();
}

void SceneManager::addScene(const std::string &name, std::shared_ptr<Scene> scene)
{
    m_scenes[name] = scene;
}

void SceneManager::swapScene(const std::string &name)
{
    if (m_currScene != nullptr) {
        // A scene is currently loaded. Unload this scene so we can load the
        // new one in.
        if (m_currScene->getRoot() != nullptr)
            // This node contains elements. Notify each one that they are being
            // removed from the active scene.
            m_currScene->getRoot()->notifyExitTree();
        
        m_currScene->destroy();
    }

    // Prepare the new scene
    m_currScene = m_scenes[name];
    m_currScene->load();

    if (m_currScene->getRoot() != nullptr)
        // Notify each element to perform their addition tasks.
        m_currScene->getRoot()->notifyEnterTree();
}
