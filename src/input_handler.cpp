#include "input_handler.h"
#include "button.h"
#include "command.h"

void InputHandler::HandleInput()
{
/**
 * @brief catches events to be handled and initiates the processing through subsystems like ButtonManager.
 * 
 * @note By defining an interface like SetState, which lets you set the state through an input
 * we can eliminate an extra if-statement for deciding which functions to use on a button like Pressed()/Released()
*/
    SDL_Keycode button;
    SDL_Event event;
    while (SDL_PollEvent(&event) && (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP))
    {
        button = (SDL_Keycode)event.key.keysym.sym; 
        if (_pButtonManager->Contains(button))
            _pButtonManager->SetState(button, (event.type == SDL_KEYDOWN));
    }
}