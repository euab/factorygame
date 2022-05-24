#include "game.h"
#include "scenegraphnode.h"

#include <sstream>
#include <string>
#include <list>

Node::Node(const std::string &name) : m_name(name) { }

// Called to when a node is created.
// Override this to execute code when a node is loaded.
void Node::init() { }

// Return char array of node name.
const char *Node::getName() const
{
    return m_name.c_str();
}

std::vector<std::string> Node::mro() const
{
    return {"Node"};
}

// Returns a boolean depending if the node type matches nodeType.
bool Node::isOf(const std::string &nodeType) const
{
    for (auto &ntype : mro()) {
        if (ntype == nodeType)
            return true;
    }

    return false;
}

std::vector<std::shared_ptr<Node>> Node::getChildren() const
{
    return m_children;
}

std::shared_ptr<Node> Node::getParent() const
{
    return m_parent.lock();
}

std::shared_ptr<Node> Node::getRoot()
{
    std::shared_ptr<Node> root = shared_from_this();

    while (root->getParent() != nullptr)
        root = root->getParent();
    
    return root;
}

std::shared_ptr<Node> Node::getNode(const std::string &path)
{
    if (path.empty())
        return shared_from_this();
    
    if (path[0] == '/')
        return getRoot()->getNode(path.substr(1));
    
    else {
        size_t pos = path.find("/");
        std::string childPath = path.substr(0, pos);

        if (childPath == ".") {
            if (pos == std::string::npos)
                return shared_from_this();     
            else
                return getNode(path.substr(pos + 1));
        }

        if (childPath == "..") {
            if (pos == std::string::npos)
                return getParent();
            else
                return getParent()->getNode(path.substr(pos + 1));
        }

        std::shared_ptr<Node> p_child = nullptr;

        for (auto &child : m_children) {
            if (child->getName() == childPath) {
                p_child = child;
                break;
            }
        }

        if (pos == std::string::npos)
            return p_child;
        
        return p_child->getNode(path.substr(pos + 1));
    }
}

void Node::addChild(std::shared_ptr<Node> child)
{
    m_children.push_back(child);
}

// Remove a child from the scene graph and all subchildren.
void Node::removeChild(std::shared_ptr<Node> child)
{
    for (auto it = m_children.begin(); it != m_children.end(); ++it) {
        if (*it == child) {
            m_children.erase(it);
            break;
        }
    }
}

void Node::setDrawEnabled(bool enabled)
{
    m_drawEnabled = enabled;
}

bool Node::canDraw()
{
    return m_drawEnabled;
}

// NOTE: I'm not sure how I feel about using draw code inside the scene graph
// as the scene graph should be as far encapsulated from the render code as
// possible.
// Could we send a generic event to the node instead? Maybe the node should
// evaulate itself whether or not it's allowed to draw instead of it being
// done up here. This code needs to be as abstract as possible.

void Node::onDraw()
{
    if (canDraw())
        draw();
    
    // Send draw event to all children of this node.
    for (auto &child : m_children)
        child->onDraw();
}

void Node::draw() { }

// Called by the scene manager when a node is being loaded from a scene.
void Node::notifyEnterTree()
{
    enterTree();

    for (auto &child: m_children)
        child->notifyEnterTree();
    
    ready();
}

// Called when the node is loaded from a scene.
void Node::enterTree() { }

// Called by the scene manager when a scene is being destroyed.
void Node::notifyExitTree()
{
    for (auto& child: m_children)
        child->notifyExitTree();
    
    exitTree();
}

// Called to when a node is removed from a scene.
void Node::exitTree() { }

// Called to when a node is ready for work.
// This must be overrided to provide node functionality.
void Node::ready() { }
