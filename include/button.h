#ifndef BUTTON_H
#define BUTTON_H

#include <unordered_set>
#include <unordered_map>

#include "logger.h"

class Command;

/**
 * @class Button
 * @brief represents a keyboard button.
 * Acts as a subject that can notify attached observers if this button is pressed.
 * 
 * @par Collaborations
 * - ButtonManager
 *      creates and manages registrations to buttons.
 *      @see next class below
 * 
 * - Command(and all concrete implementations)
 *      a observer that can be attached to a button through ButtonManager
 *      @see Command
 * 
 * @par Class Hierarchy
 * Stringify(v)
 * |- Button
 * 
 * @par Design Pattern
 * - Observer
 * 
 * This class takes the role of the subject in the Observer-Pattern
 * 
 * @par Member Functions
 * - ToString()
 *      This function is needed for logging purposes that can give log-entries from this class a tag to which the entry can be backtracked to this class.
 *      @see Stringify(logger.h)
*/
class Button : public Stringify
{
public:
    Button(SDL_Keycode B);

    void Attach(std::shared_ptr<Command> pCmd);
    void Detach(std::shared_ptr<Command> pCmd);
    void SetState(const bool& isPressed) { Log(ToString() + "::SetState - to " + std::to_string(isPressed)); _isPressed = isPressed; }
    void Notify();

    std::string ToString() const override { return " <BUTTON" + Logger::Format(_BUTTON) + "> - "; }

private:
    bool _isPressed{false};
    const SDL_Keycode _BUTTON;
    std::unordered_map<Command*, std::weak_ptr<Command>> _cListener;
};

class Command;

/**
 * @class ButtonManager
 * @brief initialises and manages all relevant Buttons which can be called through a SDL_Keycode
 * It provides an interface for registering Commands to Buttons 
 * and for initiating the Buttons to send notifications to attached Commands.
 * 
 * @par Collaborations
 * most other classes in order to get all the functionality needed for the main game loop.
 * 
 * @par Class Hierarchy
 * Stringify(v)
 * |- Game
 * 
 * @par Design Pattern
 * - Observer
 * - Facade
 * 
 * From the Observer-Pattern this class takes the role of the Manager, that organizes the communication between Subjects and Observers.
 * From the Facade-Pattern we abstract the internal workings of Button away from the user. 
 * The intend is that the user only needs the SDL_Keycode and the ButtonManager organizes the communication to the intended Button.
 * 
 * @par Member Functions
 * - ToString()
 *      This function is needed for logging purposes that can give log-entries from this class a tag to which the entry can be backtracked to this class.
 *      @see Stringify(logger.h)
*/
class ButtonManager : public Stringify
{
public:
    ButtonManager();

    void Register(const SDL_Keycode& B, std::shared_ptr<Command> pCmd);
    void Unregister(const SDL_Keycode& B, std::shared_ptr<Command> pCmd);
    bool Contains(const SDL_Keycode& B) const { return _cButtonRegister.count(B) > 0; }
    void SetState(const SDL_Keycode& B, const bool& isPressed);
    void Update();

    std::string ToString() const override { return " <ButtonManager> (Buttons: " + std::to_string(_cButtonRegister.size()) + ") - "; }

private:
    void Add(const SDL_Keycode& B);
    std::unordered_map<SDL_Keycode, std::shared_ptr<Button>> _cButtonRegister;
    std::unordered_set<std::shared_ptr<Button>> _cButtonUpdate;
};

#endif