#ifndef GAME_OBJECT_FACTORY_H
#define GAME_OBJECT_FACTORY_H

#include <unordered_map>
#include <unordered_set>

#include "logger.h"

class ButtonManager;
class QuitCommand;
class FireCommand;
class GameObject;

/**
 * @enum TYPE
 * @brief lists an entry for every concrete implementation of GameObject preferably with the same name.
 * This is intended everyone using the factory below to specify the clone of which prototype to produce.
 * @see PLayer
 * @see Enemy
 * @see Bullet
 * @see Shield
*/
enum TYPE
{
    PLAYER = 0,
    ENEMY = 1,
    BULLET = 2,
    SHIELD = 3
};

/**
 * @class GameObjectFactory 
 * @brief creates prototypes for all game-objects to specified values in the constructor
 * and creates clones on demand.
 *
 * @par Collaborations
 * - GameLogic
 *      uses the factory to populate the "playing field" with game-objects.
 * 
 * - Player/Enemy/Bullet/Shield
 *      creates and holds an instance of these prototypes for cloning
 * 
 * @par Class Hierarchy
 * Stringify(v)
 * |- GameObjectFactory
 * 
 * (v) <=> virtual class
 *
 * @par Design Pattern: 
 * - Prototype-Factory
 * - Flyweight-Factory
 *
 * @par Member Functions
 * - ToString()
 *      This function is needed for logging purposes that can give log-entries from this class a tag to which the entry can be backtracked to this class.
 *      @see Stringify(logger.h)
 */
class GameObjectFactory : public Stringify
{
public:
    GameObjectFactory(std::shared_ptr<ButtonManager> pButtonManager, std::shared_ptr<QuitCommand> pQuitCmd, std::shared_ptr<FireCommand> pFireCmd);

    std::unique_ptr<GameObject> Get(const TYPE& T);

    std::string ToString() const override { return " <Factory> - "; }

private:
    std::unordered_map<TYPE, std::unique_ptr<GameObject>> _cPrototype;
};

#endif