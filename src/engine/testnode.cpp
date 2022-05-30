#include "engine/testnode.h"

#include <iostream>

std::vector<std::string> TestNode::mro() const
{
    auto _mro = Node::mro();
    _mro.push_back("TestNode");
    return _mro;
}

void TestNode::sayHi()
{
    std::cout << "AAAAAAAAAAAAAHHH" << std::endl;
}

void TestNode::ready()
{
    sayHi();
}
