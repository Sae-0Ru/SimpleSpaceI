#include "shield.h"

Shield::Shield(const Shield &other)
{
/**
 * @brief Copy-Constructor (Rule of Five)
 * Since this class does not move or fire it only has to copy
 * properties for rendering like offset, color, rect.
 * Besides that only BaseHP ist needed in order to determine how much HP it starts with.
 *
 * @param other Reference to a source which members are to be copied
 */
    this->_pBaseHP = other._pBaseHP;
    this->_pOffsetX = other._pOffsetX;
    this->_pOffsetY = other._pOffsetY;
    this->_pColor = other._pColor;
    this->_rect = other._rect;  
}

std::unique_ptr<GameObject> Shield::Clone()
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
    auto pCopy = new Shield(*this);
    pCopy->_HP = *pCopy->_pBaseHP;
    return std::unique_ptr<GameObject>(pCopy);
}