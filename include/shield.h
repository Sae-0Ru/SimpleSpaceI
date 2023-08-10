#ifndef SHIELD_H
#define SHIELD_H

#include "game_object.h"

/**
 * @class Shield
 * @brief shields are a passive defensive game-object, that may protect the player.
 * It does not move or shoot.
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
 * @par Class Hierarchy
 * Stringify(v)
 * |- GameObject(v)
 *      |- Shield  
 *      |- Player
 *      |- Enemy
 *      |- Bullet
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
class Shield : public GameObject
{
public:
    ~Shield() = default;

    void Update() override {}
    bool GetFriendly() override { return true; }

    std::string ToString() const override { return " <Shield> - "; }

private:
    Shield() = default;
    Shield(const Shield &other);
    Shield(Shield&& other) = delete;
    Shield& operator=(const Shield& other) = delete;
    Shield& operator=(const Shield&& other) = delete;

    std::unique_ptr<GameObject> Clone() override;
    friend class GameObjectFactory;
};

#endif