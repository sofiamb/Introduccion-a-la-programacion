#include <SDL.h>

bool running = true;

int main(int argc, char* args[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow(
        "Game Loop",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        0
    );

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    int x = 100;
    int y = 100;

    while (running)
    {
        // ------------------ INPUT 
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = false;
        }

        const Uint8* keyboard = SDL_GetKeyboardState(NULL);

        if (keyboard[SDL_SCANCODE_W]) y -= 1;
        if (keyboard[SDL_SCANCODE_S]) y += 1;
        if (keyboard[SDL_SCANCODE_A]) x -= 1;
        if (keyboard[SDL_SCANCODE_D]) x += 1;

        // ------------------  UPDATE 

        // acá podría ir física, IA, colisiones, etc.

        // ------------------ RENDER 

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_Rect player = { x, y, 50, 50 };

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &player);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}









