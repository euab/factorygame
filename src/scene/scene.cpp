#include "scene/scene.h"
#include "scene/scenegraphnode.h"

Scene::Scene() : m_root(nullptr) { }

std::shared_ptr<Node> Scene::getRoot() const
{
    return m_root;
}
