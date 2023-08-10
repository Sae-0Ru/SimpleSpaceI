#include "bullet.h"
#include "constant.h"

Bullet::Bullet(const Bullet &other)
{
/**
 * @brief Copy-Constructor (Rule of Five)
 * this class has to copy properties for rendering like offset, color, rect.
 * Finally the values for steering movement is needed as well.
 *
 * @param other Reference to a source which members are to be copied
 */

    this->_pBaseHP = other._pBaseHP;
    this->_pBlockMove = other._pBlockMove;
    this->_pOffsetX = other._pOffsetX;
    this->_pOffsetY = other._pOffsetY;
    this->_pColor = other._pColor;
    this->_rect = other._rect;  
}

void Bullet::Update()
{
/** 
 * @brief This method determines the movement of the class.
 * An instance should move only vertically depending on who fired it.
 * - player(GetFriendly() == true): move up
 * - enemy(GetFriendly() == false): move down
 *
 * @note this function must be called one per frame
 */
    if (GetMoveBlock()) return; // Check if we can move again
    
    int x = GetX();
    int y = GetY();

    int dy = CONST::GRID_HEIGHT * (!GetFriendly() - GetFriendly()); // move upwards if bullet is from a friendly source else downwards

    SetPos(x, y + dy);
}

std::unique_ptr<GameObject> Bullet::Clone() 
{
/** 
 * @brief method for creating a copy of itself wrapped in a unique pointer
 * This method enables copying on a pure pointer-level.
 * 
 * @note need to ensure that only this method creates "living" copies, so the _HP( = -1) member gets set here to default value.
 * With this function the factory is able to produce more copies of a prototype.
 * @see GameObject
 * @see GameObjectFactroy
 * 
 * @return copy of itself wrapped in a unique pointer
 */
    auto pCopy = new Bullet(*this);
    pCopy->_HP = *pCopy->_pBaseHP;
    return std::unique_ptr<GameObject>(pCopy);
}