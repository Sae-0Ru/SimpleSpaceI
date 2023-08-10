#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <unordered_set>

#include "logger.h"

/**
 * @class GameObject (virtual)
 * @brief this class sets the basic infrastructure for ever game-object like offset, proportions, color.
 * It defines concepts like position, disposition or cooldown 
 * in order to give the each implementation the ability to customize movement(-speed), firing(-speed) and opposing game-objects.
 * It even provides each implementation the ability to render itself 
 * and hides it inner workings so each implementation can just focus on customizing its behavior.
 *
 * @par Collaborations
 * This class can't collaborate with anything since it's a virtual function.
 * Although each appearance of a concrete implementation gets saved as a pointer it's parent(this class).
 * @see Player
 * @see Enemy
 * @see Bullet
 * @see Shield
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
 * - Prototype   
 * - FlyWeight
 * 
 * The idea was to create a class that shares common properties via a pointer to the prototype saving memory cost for each copy in return.
 * All unique members on the other hand are not saved in a pointer. This hopefully helps divide the line in what must be shared and what not.
 *
 * @par Member Functions
 * - Update()
 *      This function customizes the behavior of this game object like autonomous movement. Since this class can't decide the behavior
 *      it hands the task to his children.
 * 
 * - GetFriendly()
 *      This function decides the disposition of this class.
 *      Since disposition should be a custom trait for each children so it hands on the task of implementing this function.
 * 
 * - ToString()
 *      This function is needed for logging purposes that can give log-entries from this class a tag to which the entry can be backtracked to this class.
 *      @see Stringify(logger.h)
 * 
 * - Clone()
 *      Copy function to be used on a pure pointer-level. This function causes the implementation of the Rule of Five.
 *      The children might add new members that can't be overlooked so each should implement this function of their own.
 * 
 * - protected Setters(): (SetBaseHP, SetProbabilityToFire, SetFireBlock, SetMoveBlock, SetColor, SetScaling)
 *      These function allow the factory to set basic common features of each prototype. 
 *      Not all Setters must be used by the factory only what is intended for the implementation to use.       
 */
class GameObject : public Stringify
{  
public:
    virtual ~GameObject() = default;

    void Render(SDL_Renderer* pRenderer);
    virtual void Update() = 0;
    virtual bool GetFriendly() = 0;
    void SetFriendly(bool isFriendly) { _isFriendly = isFriendly; }

    int GetX() const { return _xPos; }
    int GetY() const { return _yPos; }
    void SetPos(const int& x, const int& y) { _xPos = x; _yPos = y; }
    void ReversePos() { _xPos = _rect.x; _yPos = _rect.y; }

    bool CollideWith(const GameObject& other) const;
    void SetHP(const int& HP = -1);
    int GetHP() const { return _HP; }

    bool GetFireBlock();
    bool GetMoveBlock();

    virtual std::string ToString() const override { return " <GameObject> - "; }

protected:
    int _HP{0};
    bool _isFriendly;
    int _xPos{-1};
    int _yPos{-1};
    int _blockMove{0};
    int _blockFire{0};

    std::shared_ptr<int> _pBaseHP;
    std::shared_ptr<int> _pProbabilityToFire;
    std::shared_ptr<int> _pBlockFire;
    std::shared_ptr<int> _pBlockMove;
    std::shared_ptr<int> _pOffsetX;
    std::shared_ptr<int> _pOffsetY;
    std::shared_ptr<SDL_Color> _pColor;
    SDL_Rect _rect;

    void SetBaseHP(const int& HP) { _pBaseHP = std::make_shared<int>(HP); }
    void SetProbabilityToFire(const int& likelihood) { _pProbabilityToFire = std::make_shared<int>(likelihood); }
    void SetFireBlock(const int& block) { _pBlockFire = std::make_shared<int>(block); }
    void SetMoveBlock(const int& block) { _pBlockMove = std::make_shared<int>(block); }
    void SetColor(const int& r, const int& g, const int& b, const int& a);
    void SetScaling(const float& scale = 1.);
    virtual std::unique_ptr<GameObject> Clone() = 0;
    friend class GameObjectFactory;
};

#endif