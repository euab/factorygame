#ifndef SCENE_H
#define SCENE_H

#include "scene/scenegraphnode.h"

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

#endif // SCENE_H
