#ifndef ENGINE_TESTNODE_H
#define ENGINE_TESTNODE_H

#include "scene/scenegraphnode.h"

class TestNode : public Node
{
    using Node::Node;
public:
    virtual std::vector<std::string> mro() const;

    virtual void ready();

    void sayHi();
};

#endif // ENGINE_TESTNODE_H
