#ifndef PLAYER_H
#define PLAYER_H

#include "game_object.h"

class QuitCommand;
class MoveRightCommand;
class MoveLeftCommand;
class FireCommand;

/**
 * @class Player
 * @brief player is an active game-object, that is user controlled.
 * It does move horizontally and does shoot.
 * Only a factory should be allowed to produce instances of this class.
 *
 * @par Collaborations
 * This class collaborates with:
 * 
 * - GameObjectFactroy
 *      Holds a prototype of this class, which gets copied and made accessible for other classes like GameLogic.
 *      @see GameObjectFactory
 *  
 * - GameLogic
 *      manages creation, destruction and checks collisions of instances from this class.
 *      @see GameLogic
 * 
 * - Game
 *      holds instances of this class in a set for rendering that GameLogic has to manage.
 *      @see Game
 * 
 * - QuitCommand
 *      An instance can execute this command to end the game.
 *      @see QuitCommand(command.h)
 * 
 * - FireCommand
 *      Allows a connected instance to fire bullets
 *      @see FireCommand(command.h)
 *      @see Bullet 
 * 
 * - MoveLRightCommand
 *      Allows a connected instance to move right
 *      @see MoveLeftCommand(command.h)
 * 
 * - MoveLeftCommand
 *      Allows a connected instance to move left
 *      @see MoveLeftCommand(command.h)
 * 
 * @par Class Hierarchy
 * Stringify(v)
 * |- GameObject(v)
 *      |- Player
 *      |- Enemy
 *      |- Bullet
 *      |- Shield  
 * 
 * (v) <=> virtual class
 *
 * @par Design Pattern: 
 * - Concrete Prototype   
 * - Concrete FlyWeight
 * 
 * The idea was to create a concrete implementation of "GameObject" in order to customize this class 
 * in it's behavior and to select only the necessary features (from the parent class) that needs to be hold by this class.
 *
 * @par Member Functions
 * - Update()
 *      This function customizes the behavior of this game object like autonomous movement.
 *      Since the move-commands and fire-command handle the behavior of this class this method is empty.
 * 
 * - GetFriendly()
 *      This function is needed in order to determine how game-objects interact with each other.
 *      If the return value is the same for two arbitrary game-objects then they are considered to be on the same team not harming each other.
 *      If the return value is different, then the two game-object can collide with each other, which eventually is getting them destroyed by collision detection.  
 *      @see GameLogic
 * 
 * - ToString()
 *      This function is needed for logging purposes that can give log-entries from this class a tag to which the entry can be backtracked to this class.
 *      @see Stringify(logger.h)
 * 
 * - Clone()
 *      Copy function to be used on a pure pointer-level. This function causes the implementation of the Rule of Five. 
 */
class Player : public GameObject
{
public:
    ~Player() override;

    void Update() override {}
    bool GetFriendly() override { return true; }

    std::string ToString() const override { return " <Player> - "; }
    
private:
    std::shared_ptr<QuitCommand> _pQuitCmd;
    std::shared_ptr<MoveRightCommand> _pMoveRightCmd;
    std::shared_ptr<MoveLeftCommand> _pMoveLeftCmd;
    std::shared_ptr<FireCommand> _pFireCmd;

    Player(std::shared_ptr<QuitCommand> pQuitCmd, std::shared_ptr<FireCommand> pFireCmd);
    Player();
    Player(const Player &other);
    Player(Player&& other) = delete;
    Player& operator=(const Player& other) = delete;
    Player& operator=(const Player&& other) = delete;

    std::shared_ptr<MoveRightCommand> GetMoveRight() const { return _pMoveRightCmd; }
    std::shared_ptr<MoveLeftCommand> GetMoveLeft() const { return _pMoveLeftCmd; }
    std::shared_ptr<FireCommand> GetFireCmd() { return _pFireCmd; }
    std::unique_ptr<GameObject> Clone() override;
    friend class GameObjectFactory;
};

#endif