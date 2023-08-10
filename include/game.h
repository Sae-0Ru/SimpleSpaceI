#ifndef GAME_H
#define GAME_H

#include <unordered_set>

#include "logger.h"

class Timer;
class ButtonManager;
class InputHandler;
class GameObject;
class GameLogic;

/**
 * @class Game
 * @brief initialises and manages all relevant systems for the main game loop. 
 * 
 * @par Collaborations
 * most other classes in order to get all the functionality needed for the main game loop.
 * 
 * @par Class Hierarchy
 * Stringify(v)
 * |- Game
 * 
 * @par Design Pattern
 * - Mediator(???)
 * 
 * This class is the shell of the game. 
 * It holds the game together an invokes the right subsystem at the right time. 
 * 
 * @par Member Functions
 * - ToString()
 *      This function is needed for logging purposes that can give log-entries from this class a tag to which the entry can be backtracked to this class.
 *      @see Stringify(logger.h)
*/
class Game : public Stringify
{
public:
    Game();
    ~Game();

    void Run();
    void SetRunning(bool stillRunning) { _isRunning = stillRunning; }
    bool GetRunning() const { return _isRunning; }

    std::string ToString() const override { return " <Game> - "; }

private:
    void Input();
    void Update();
    void Render();

    bool _isRunning{false};

    SDL_Window* _pWindow;
    SDL_Renderer* _pRenderer;
    int block = 180;
    
    std::unique_ptr<Timer> _pTimer;
    std::shared_ptr<ButtonManager> _pButtonManager;
    std::unique_ptr<InputHandler> _pInputHandler;
    std::unordered_set<std::unique_ptr<GameObject>> _cGameObject;
    std::unordered_set<std::unique_ptr<GameObject>> _cProjectile;
    std::unique_ptr<GameLogic> _pLogic;
};

#endif