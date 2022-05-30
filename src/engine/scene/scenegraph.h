#ifndef ENGINE_SCENE_SCENEGRAPH_H
#define ENGINE_SCENE_SCENEGRAPH_H

#include "engine/scene/scenegraphnode.h"

class Scenegraph
{
public:
    Scenegraph() { }

    // Returns a shared pointer to a new node instance.
    template <class NT>
    static std::shared_ptr<NT> createNode(const std::string &name)
    {
        std::shared_ptr<NT> node = std::make_shared<NT>(name);
        // Start the new node up
        node->init();
        return node;
    }

};

#endif // ENGINE_SCENE_SCENEGRAPH_H
