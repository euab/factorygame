#include "assets.h"
#include "io/file.h"

const char* Assets::SPRITES_PATH = "assets/";

std::unordered_map<std::string, SDL_Texture*> Assets::_textures;

SDL_Texture* Assets::GetTexture(std::string file_path)
{
    SDL_Texture* texture;
    file_path = std::string(SPRITES_PATH) + file_path;

    texture = ReadTexture(file_path);

    if (texture != nullptr)
        return texture;
    
    else
        std::cerr << "ERROR: Failed to read texture from " << file_path 
            << std::endl;
    
    return texture;
}

SDL_Texture* Assets::ReadTexture(const std::string &file_path)
{
    SDL_RWops* data = nullptr;
    SDL_Texture* texture = nullptr;

    std::vector<char> buffer;

    File file(file_path);

    if (file.Read(buffer) && !buffer.empty())
        data = SDL_RWFromMem(&buffer[0], buffer.size());
    
    if (data != nullptr)
        texture = IMG_LoadTexture_RW(Game::renderer, data, 1);
    
    return texture;
}
