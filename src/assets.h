#ifndef ASSETS_H
#define ASSETS_H

#include "game.h"

#include <string>
#include <unordered_map>

class Assets
{
public:
    static const char* SPRITES_PATH;

    static SDL_Texture* GetTexture(std::string file_path);

private:
    Assets() { }

    static std::unordered_map<std::string, SDL_Texture*> _textures;

    static SDL_Texture* ReadTexture(const std::string &file_path);
};

#endif // ASSETS_H
