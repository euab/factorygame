#ifndef ENGINE_SCENE_SCENE_H
#define ENGINE_SCENE_SCENE_H

#include "engine/scene/scenegraphnode.h"

class Scene
{
public:
    Scene();

    virtual void load() = 0;
    virtual void destroy() = 0;

    std::shared_ptr<Node> getRoot() const;

protected:
    std::shared_ptr<Node> m_root;
};

#endif // ENGINE_SCENE_SCENE_H
