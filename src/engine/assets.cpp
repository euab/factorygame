#include "engine/assets.h"
#include "engine/io/file.h"
#include "engine/engine.h"

#include <iostream>

const char* Assets::SPRITES_PATH = "assets/";

Assets::Assets(Engine &engine) : m_engine(engine) { }

SDL_Texture* Assets::GetTexture(std::string file_path)
{
    SDL_Texture* texture;
    file_path = std::string(SPRITES_PATH) + file_path;

    texture = ReadTexture(file_path);

    if (texture != nullptr)
        m_textures[file_path] = texture;
    
    // BUG: Texture is nullptr
    
    else {
        std::cerr << "ERROR: Failed to read texture from " << file_path 
            << std::endl;
        
        if (!m_engine.renderer())
            std::cerr << "[ASSETMANAGER] Has the renderer been initialised?"
                << std::endl;
    }
    
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
        texture = IMG_LoadTexture_RW(m_engine.renderer(), data, 1);
    
    return texture;
}
