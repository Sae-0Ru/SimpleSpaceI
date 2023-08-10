#ifndef COMMAND_H
#define COMMAND_H

#include <unordered_set>

#include "logger.h"

class Game;
class GameObject;

/**
 * @class Command
 * @brief initialises and manages all relevant systems for the main game loop. 
 * 
 * @par Collaborations
 * - Button/ButtonManager
 *      Commands act as an observer and can be attached to a Button(subject).
 * 
 * - GameObject(Player/Enemy)
 *      Commands direct the behavior of GameObjects.
 * 
 * @par Class Hierarchy
 * Stringify(v)
 * |- Command (v)
 * 
 * @par Design Pattern
 * - Observer
 * - Command
 * 
 * This class acts as an observer from the Observer-Pattern.
 * From the Command-Pattern we encapsulated a specific request that determines that behavior of GameObjects
 * 
 * @par Member Functions
 * - ToString()
 *      This function is needed for logging purposes that can give log-entries from this class a tag to which the entry can be backtracked to this class.
 *      @see Stringify(logger.h)
*/
class Command : public Stringify
{
public:
    virtual void Execute() = 0;
    virtual std::string ToString() const override { return " <CMD> - ";}
};

/**
 * @class QuitCommand
 * @brief concrete implementation of Command.
 * This commands is responsible for quitting the main game loop on different occasions it is called.
 * 
 * @par Class Hierarchy
 * Stringify(v)
 * |- Command (v)
 *      |- QuitCommand
 *      |- MoveUpCommand
 *      |- MoveDownCommand
 *      |- MoveLeftCommand
 *      |- MoveRightCommand
 *      |- FireCommand
*/
class QuitCommand : public Command
{
public:
    QuitCommand(Game* pGame) : pGame{pGame} {}

    void Execute() override;
    std::string ToString() const override { return " <QUIT_CMD> - "; }

private:
    Game* pGame;
};

/**
 * @class MoveUpCommand
 * @brief concrete implementation of Command.
 * This commands is responsible for moving the GameObject one cell up.
 * 
 * @par Class Hierarchy
 * Stringify(v)
 * |- Command (v)
 *      |- QuitCommand
 *      |- MoveUpCommand
 *      |- MoveDownCommand
 *      |- MoveLeftCommand
 *      |- MoveRightCommand
 *      |- FireCommand
*/
class MoveUpCommand : public Command
{
public:
    MoveUpCommand(GameObject* pGameObj) : pGameObj{pGameObj} {}

    void Swap(GameObject* pGameObj) { this->pGameObj = pGameObj; }
    void Execute() override;
    std::string ToString() const override { return " <MOVE_UP_CMD> - "; }

private:
    GameObject* pGameObj;
};

/**
 * @class MoveDownCommand
 * @brief concrete implementation of Command.
 * This commands is responsible for moving the GameObject one cell down.
 * 
 * @par Class Hierarchy
 * Stringify(v)
 * |- Command (v)
 *      |- QuitCommand
 *      |- MoveUpCommand
 *      |- MoveDownCommand
 *      |- MoveLeftCommand
 *      |- MoveRightCommand
 *      |- FireCommand
*/
class MoveDownCommand : public Command
{
public:
    MoveDownCommand(GameObject* pGameObj) : pGameObj{pGameObj} {}

    void Swap(GameObject* pGameObj) { this->pGameObj = pGameObj; }
    void Execute() override;
    std::string ToString() const override { return " <MOVE_DOWN_CMD> - "; }

private:
    GameObject* pGameObj;
};

/**
 * @class MoveRightCommand
 * @brief concrete implementation of Command.
 * This commands is responsible for moving the GameObject one cell right.
 * 
 * @par Class Hierarchy
 * Stringify(v)
 * |- Command (v)
 *      |- QuitCommand
 *      |- MoveUpCommand
 *      |- MoveDownCommand
 *      |- MoveLeftCommand
 *      |- MoveRightCommand
 *      |- FireCommand
*/
class MoveRightCommand : public Command
{
public:
    MoveRightCommand(GameObject* pGameObj) : pGameObj{pGameObj} {}

    void Swap(GameObject* pGameObj) { this->pGameObj = pGameObj; }
    void Execute() override;
    std::string ToString() const override { return " <MOVE_RIGHT_CMD> - "; }

private:
    GameObject* pGameObj;
};

/**
 * @class MoveLeftCommand
 * @brief concrete implementation of Command.
 * This commands is responsible for moving the GameObject one cell left.
 * 
 * @par Class Hierarchy
 * Stringify(v)
 * |- Command (v)
 *      |- QuitCommand
 *      |- MoveUpCommand
 *      |- MoveDownCommand
 *      |- MoveLeftCommand
 *      |- MoveRightCommand
 *      |- FireCommand
*/
class MoveLeftCommand : public Command
{
public:
    MoveLeftCommand(GameObject* pGameObj) : pGameObj{pGameObj} {}

    void Swap(GameObject* pGameObj) { this->pGameObj = pGameObj; }
    void Execute() override;
    std::string ToString() const override { return " <MOVE_LEFT_CMD> - "; }

private:
    GameObject* pGameObj;
};


class GameObjectFactory;

/**
 * @class QuitCommand
 * @brief concrete implementation of Command.
 * This commands is responsible for firing a bullet 
 * (create a Bullet, decides its movement and moving it to the current position of the shooter).
 * 
 * @par Class Hierarchy
 * Stringify(v)
 * |- Command (v)
 *      |- QuitCommand
 *      |- MoveUpCommand
 *      |- MoveDownCommand
 *      |- MoveLeftCommand
 *      |- MoveRightCommand
 *      |- FireCommand
 * 
 * @note For the FireCommand we have unique requirements compared to other concrete implementations.
 * Here we need the GameObject that fires, the factory to produce a Bullet and the Container for the Bullet.
 * Since all these components are in different places and I want the factory to produce many copies of GameObject with this command
 * I need a additional Copy-Policy in order to pass all members on that can be reused.
*/
class FireCommand : public Command
{
public:
    FireCommand(std::unordered_set<std::unique_ptr<GameObject>>& cProjectile) : _cProjectile{cProjectile} {}

    FireCommand(const FireCommand& other);
    FireCommand(std::shared_ptr<FireCommand> pOther) : FireCommand(*pOther) {}
    FireCommand& operator=(const FireCommand& other) = delete;

    void Swap(GameObject* pGameObj) { this->pGameObj = pGameObj; }
    void Set(GameObjectFactory* pFactory) { this->pFactory = pFactory; }

    GameObject* GetObject() { return pGameObj; }
    GameObjectFactory* GetFactory() { return pFactory; }
    std::unordered_set<std::unique_ptr<GameObject>>& GetContainer() { return _cProjectile; }

    void Execute() override;
    std::string ToString() const override { return " <SHOOT_CMD> - "; }

private:
    GameObject* pGameObj;
    GameObjectFactory* pFactory;
    std::unordered_set<std::unique_ptr<GameObject>>& _cProjectile;

    FireCommand(FireCommand&& other) = delete;
    FireCommand& operator=(FireCommand&& other) = delete;
};

#endif