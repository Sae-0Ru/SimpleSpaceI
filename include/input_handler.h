#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "logger.h"

class ButtonManager;

/**
 * @class InputHandler
 * @brief handles the input.
 * 
 * @par Collaborations
 * - ButtonManager
 *      if a Button is affected by current poll of events the InputHandler initiates the change through the ButtonManager 
 * 
 * @par Class Hierarchy
 * Stringify(v)
 * |- InputHandler
 * 
 * @par Design Pattern
 * - (???)
 * 
 * Just refactored the loop for polling events.
 * 
 * @par Member Functions
 * - ToString()
 *      This function is needed for logging purposes that can give log-entries from this class a tag to which the entry can be backtracked to this class.
 *      @see Stringify(logger.h)
*/
class InputHandler : public Stringify
{
public:
    InputHandler(std::shared_ptr<ButtonManager> pButtonManager) : _pButtonManager{pButtonManager}  {}

    void HandleInput();

    std::string ToString() const override { return " <InputHandler> - "; }

private:
    std::shared_ptr<ButtonManager> _pButtonManager;
};

#endif