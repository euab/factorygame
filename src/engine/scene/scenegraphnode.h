#ifndef ENGINE_SCENEGRAPHNODE_H
#define ENGINE_SCENEGRAPHNODE_H

#include <SDL2/SDL.h>
#include <memory>
#include <string>
#include <vector>

class Node : public std::enable_shared_from_this<Node>
{
public:
    Node(const std::string &name);

    virtual void init();

    const char *getName() const;
    virtual std::vector<std::string> mro() const;

    bool isOf(const std::string &nodetype) const;

    std::vector<std::shared_ptr<Node>> getChildren() const;
    std::shared_ptr<Node> getParent() const;
    std::shared_ptr<Node> getRoot();

    std::shared_ptr<Node> getNode(const std::string &path);

    void addChild(std::shared_ptr<Node> child);
    void removeChild(std::shared_ptr<Node> child);

    void setDrawEnabled(bool enabled);
    bool canDraw();
    void onDraw();
    virtual void draw();

    void notifyEnterTree();
    virtual void enterTree();
    void notifyExitTree();
    virtual void exitTree();

    virtual void ready();

private:
    std::string m_name;

    std::weak_ptr<Node> m_parent;
    std::vector<std::shared_ptr<Node>> m_children;

    bool m_drawEnabled;
};

#endif // ENGINE_SCENE_SCENEGRAPHNODE_H
