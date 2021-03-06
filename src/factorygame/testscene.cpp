#include "factorygame/testscene.h"
#include "engine/scene/scenegraphnode.h"
#include "engine/scene/scenegraph.h"
#include "engine/testnode.h"

#include <string>
#include <iostream>

void TestScene::load()
{
    std::cout << "I AM A SCENE" << std::endl;
    std::string tName = "node";
    std::shared_ptr<TestNode> tn = Scenegraph::createNode<TestNode>(tName);

    m_root = tn;
}

void TestScene::destroy()
{
    std::cout << "GOODBYE" << std::endl;
    m_root.reset();
}
