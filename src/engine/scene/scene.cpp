#include "engine/scene/scene.h"
#include "engine/scene/scenegraphnode.h"

Scene::Scene() : m_root(nullptr) { }

std::shared_ptr<Node> Scene::getRoot() const
{
    return m_root;
}
