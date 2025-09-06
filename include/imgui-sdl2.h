#ifndef IMGUI_SDL2_H
#define IMGUI_SDL2_H

#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <cstdint>

#include "imgui-sdl2_export.h"

namespace ImGui
{
    namespace SDL2
    {
        struct SDL2ImageWrapper {
            uint8_t* data = nullptr;
            uint32_t w = 0;
            uint32_t h = 0;
        };
        IMGUI_SDL2_API bool Init(SDL_Window* window, SDL_Renderer* render, SDL_GLContext* ogl);
        IMGUI_SDL2_API void UpdateFontTexture();

        IMGUI_SDL2_API void NewFrame();

        IMGUI_SDL2_API void Render(SDL_Window* window, SDL_Renderer* render, SDL_GLContext* ogl);

        IMGUI_SDL2_API void SetTextureUnloadInterval(int updateCount);
    
        IMGUI_SDL2_API bool ProcessEvent(SDL_Event &event);

        IMGUI_SDL2_API void Shutdown();
    }

    // custom ImGui widgets for SFML stuff

    // Image overloads
    IMGUI_SDL2_API void Image(const SDL2::SDL2ImageWrapper& texture,
        const glm::vec4& tintColor = glm::vec4(1),
        const glm::vec4& borderColor = glm::vec4(0));
    IMGUI_SDL2_API void Image(const SDL2::SDL2ImageWrapper& texture, const glm::vec2& size,
        const glm::vec4& tintColor = glm::vec4(1),
        const glm::vec4& borderColor = glm::vec4(0));

    // ImageButton overloads
    IMGUI_SDL2_API bool ImageButton(const char* _id, const SDL2::SDL2ImageWrapper& texture,
        const glm::vec4& bgColor = glm::vec4(0),
        const glm::vec4& tintColor = glm::vec4(1));
    IMGUI_SDL2_API bool ImageButton(const char* _id, const SDL2::SDL2ImageWrapper& texture, const glm::vec2& size,
        const glm::vec4& bgColor = glm::vec4(0),
        const glm::vec4& tintColor = glm::vec4(1));

    // Draw_list overloads. All positions are in relative coordinates (relative to top-left of the current window)
    IMGUI_SDL2_API void DrawLine(const glm::vec2& a, const glm::vec2& b, const glm::vec4& col, float thickness = 1.0f);
}

#endif //# IMGUI_SDL2_H
