#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <unordered_set>
#include <experimental/random>

#include <SDL2/SDL.h>

#include "logger.h"

class GameObject;
class GameObjectFactory;

/**
 * @class GameLogic
 * @brief handles the (re-)production of game-objects like player and enemy. 
 * 
 * @par Collaborations
 * - Game
 *      holds the container for game-objects to placed into by this function.
 * 
 * - GameObjectFactory
 *      dependant on interval values asks the factory to (re-) produce game-objects.
 * 
 * @par Class Hierarchy
 * Stringify(v)
 * |- GameLogic
 * 
 * @par Design Pattern
 * - Mediator(???)
 * 
 * This class decides when which game-object is produced and for this task it handles the communication between the factory and the containers hold by Game.
 * Because of debugging reasons the containers for the game-object are with Game and the operation of methods of GameLogic on these are that of pure functions. 
 * 
 * @par Member Functions
 * - ToString()
 *      This function is needed for logging purposes that can give log-entries from this class a tag to which the entry can be backtracked to this class.
 *      @see Stringify(logger.h)
 * 
 * @note I needed a cooldown for an Enemy to be reproduced. To be conform with GameObject this will be done by the Render() method
 * which needs to be called in the render-phase of the main game loop even though this function does not render anything to the screen.
*/
class GameLogic : public Stringify
{
public:
    GameLogic(std::unique_ptr<GameObjectFactory>&& pFactory, std::unordered_set<std::unique_ptr<GameObject>>& cGameObject);

    void HandleCollision(std::unordered_set<std::unique_ptr<GameObject>>& cGameObject, std::unordered_set<std::unique_ptr<GameObject>>& cProjectile);
    void Update(std::unordered_set<std::unique_ptr<GameObject>>& cGameObject);
    void Render() { _enemyBlock -= 1 * (_enemyBlock > 0); }
    int GetScore() { return _enemyDestr * 100; }

    std::string ToString() const override { return " <GameLogic> - "; }

private:
    int _enemyDestr{0}; 
    int _enemyCount{0};
    int _enemyBlock{0};
    const int _ENEMY_BLOCK{60};
    std::unique_ptr<GameObjectFactory> _pFactory;

    bool GetEnemyBlock();
};

#endif