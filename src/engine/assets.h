#ifndef ENGINE_ASSETS_H
#define ENGINE_ASSETS_H

#include <engine/engineforward.h>

#include <SDL2/SDL_image.h>

#include <string>
#include <unordered_map>

class Assets
{
public:
    Assets(Engine &engine);
    ~Assets() { }
    
    static const char* SPRITES_PATH;

    SDL_Texture* GetTexture(std::string file_path);

private:
    Engine &m_engine;
    std::unordered_map<std::string, SDL_Texture*> m_textures;

    SDL_Texture* ReadTexture(const std::string &file_path);
};

#endif // ENGINE_ASSETS_H
