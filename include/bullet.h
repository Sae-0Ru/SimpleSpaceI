#ifndef BULLET_H
#define BULLET_H

#include "game_object.h"

/**
 * @class Bullet
 * @brief bullets are an active game-object, that damages all game-objects.
 * It does move vertically but does not shoot.
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
 * - FireCommand
 *      This command can order the factory to produce an instance of this class an insert it to the set of projectiles hold by Game.
 *      @see FireCommand(command.h) 
 * 
 * @par Class Hierarchy
 * Stringify(v)
 * |- GameObject(v)
 *      |- Bullet
 *      |- Player
 *      |- Enemy
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
class Bullet : public GameObject
{
public:
    ~Bullet() = default;

    void Update() override;
    bool GetFriendly() override { return _isFriendly; }

    std::string ToString() const override { return " <Bullet> - "; }

private:
    Bullet() = default;
    Bullet(const Bullet &other);
    Bullet(Bullet&& other) = delete;
    Bullet& operator=(const Bullet& other) = delete;
    Bullet& operator=(const Bullet&& other) = delete;

    std::unique_ptr<GameObject> Clone() override;
    friend class GameObjectFactory;
};

#endif