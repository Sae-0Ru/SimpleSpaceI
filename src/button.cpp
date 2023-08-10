#include "button.h"
#include "command.h"

Button::Button(SDL_Keycode B) : _BUTTON{B} 
{
/**
 * @brief constructs the object and preparing for attaching at least one Command to this Button.
*/
    _cListener.reserve(1);
}

void Button::Attach(std::shared_ptr<Command> pCmd)
{
/**
 * @brief attaching a Command to notified at the right time.
 * 
 * @note for me it was important not to raise the instance-count of the shared pointer but to use the underlying object as well.
 * For this and safety I saved the raw pointer in combination with the weak pointer.
 * 
 * @param pCmd pointer to a Command
*/
    _cListener.insert({ pCmd.get(), std::weak_ptr<Command>(pCmd) });
}

void Button::Detach(std::shared_ptr<Command> pCmd)
{
/**
 * @brief detaching a Command
 * 
 * @param pCmd pointer to a Command
*/
    _cListener.erase(pCmd.get());
}

void Button::Notify()
{
/**
 * @brief notifies all Commands
 * 
 * @note In order to prevent to 2-way communication between Button and Command
 * I used the raw-pointer + weak-pointer combination.
 * By checking with the weak-pointer if the Command to be notified still exists 
 * I can guarantee that the call of Execute() with the raw pointer does not run into a segmentation fault.
 * I can use this for automatic clean-up of the map too. 
*/
    for (auto it = _cListener.begin(); it != _cListener.end();)
        if (it->second.expired())
            _cListener.erase(it++);
        else
            (it++)->first->Execute();
}



ButtonManager::ButtonManager()
{
/**
 * @brief constructs all needed Buttons and reserve in both Containers appropiate space.
*/
    _cButtonRegister.reserve(6);
    Add(SDLK_ESCAPE);
    Add(SDLK_w);
    Add(SDLK_s);
    Add(SDLK_a);
    Add(SDLK_d);
    Add(SDLK_SPACE);

    _cButtonRegister.reserve(_cButtonRegister.size());
}

void ButtonManager::Register(const SDL_Keycode &B, std::shared_ptr<Command> pCmd)
{
/**
 * @brief registers a Command to a Button
 * 
 * @warning this function takes into account that the referred Button to the SDL_Keycode is already added.
 * If not please add the needed Button in the Constructor of this class else the program will crash.
 * 
 * @param B reference to a SDL_Keycode that represents a Button
 * @param pCmd pointer to a Command
*/
    _cButtonRegister[B]->Attach(pCmd);
}

void ButtonManager::Unregister(const SDL_Keycode& B, std::shared_ptr<Command> pCmd)
{
/**
 * @brief unregisters a Command to a Button
 * 
 * @param B reference to a SDL_Keycode that represents a Button
 * @param pCmd pointer to a Command
*/
    _cButtonRegister[B]->Detach(pCmd);
}

void ButtonManager::SetState(const SDL_Keycode& B, const bool& isPressed) 
{ 
/**
 * @brief changes the State of the called Button from pressed to unpressed or the other way around.
 * 
 * @note Besides changing the state of the Button we optimize which Buttons get called during Update().
 * If state changes to true, then Button is added to the container
 * else the Button is erased from the Container.
 * The risk for duplicated is eliminated by starting with an empty container and by using a set.  
 * 
 * @param B reference to a SDL_Keycode that represents a Button
 * @param isPressed new state of the called Button
*/
    _cButtonRegister[B]->SetState(isPressed);

    if (isPressed)
        _cButtonUpdate.insert(_cButtonRegister[B]);
    else 
        _cButtonUpdate.erase(_cButtonRegister[B]); 
}

void ButtonManager::Update() 
{ 
/**
 * @brief calls notify on all Buttons which are pressed.
*/
    for (auto it = _cButtonUpdate.begin(); it != _cButtonUpdate.end(); ++it) 
        (*it)->Notify(); 
}

void ButtonManager::Add(const SDL_Keycode& B)
{
/**
 * @brief creates a new Button a inserts it in the register with its SDL_Keycode.
 * 
 * @note since we use a map to save the newly created Button together with the SDL_Keycode
 * saving the SDL_Keycode inside the Button too is a bit of a waste of memory. 
 * But I find it organized to have the Button actually know what keyboard button it represents. 
 * 
 * @param B reference to a SDL_Keycode that represents a Button
*/
    _cButtonRegister[B] = std::make_shared<Button>(B);
}