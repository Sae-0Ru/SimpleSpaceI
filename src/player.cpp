#include "player.h"
#include "command.h"

Player::Player(std::shared_ptr<QuitCommand> pQuitCmd, std::shared_ptr<FireCommand> pFireCmd) : _pQuitCmd{pQuitCmd}, _pFireCmd{pFireCmd}
{
/** 
 * @brief Constructor
 * Since an enemy has a game-ending condition a QuitCommand is needed, which must be already connected the the game-instance.
 * In order for the player to fight back a FireCommand is needed, which must be already connected to the set of projectiles
 * in which to place the fired projectiles.
 * @see QuitCommand(command.h)
 * @see FireCommand(command.h)
 * 
 * @param pQuitCmd pointer to a QuitCommand for the game  
 * @param pFireCmd pointer to a FireCommand for this instance
 */
    _pMoveRightCmd = std::make_shared<MoveRightCommand>(this);
    _pMoveLeftCmd = std::make_shared<MoveLeftCommand>(this);
    _pFireCmd->Swap(this);
}

Player::Player(const Player& other)
{
/**
 * @brief Copy-Constructor (Rule of Five)
 * Basic properties for rendering like offset, color, rect need to be copied.
 * Additionally all commands for game-ending, firing and movement are needed.
 * Finally the values for steering movement and random firing are needed as well.
 * 
 * @warning Using this constructor on an existing instance makes it unusable.
 * The movement- and fire-pointer are copied, but the connected instance of player is swapped.
 * So making a copy "steals" the movement- and fire-option from the source. 
 *
 * @param other Reference to a source which members are to be copied
 */
    this->_pQuitCmd = other._pQuitCmd;

    this->_pMoveRightCmd = other._pMoveRightCmd;
    this->_pMoveRightCmd->Swap(this);

    this->_pMoveLeftCmd = other._pMoveLeftCmd;
    this->_pMoveLeftCmd->Swap(this);

    this->_pFireCmd = other._pFireCmd;
    this->_pFireCmd->Swap(this);

    this->_pBaseHP = other._pBaseHP;
    this->_pBlockFire = other._pBlockFire;
    this->_pBlockMove = other._pBlockMove;
    this->_pOffsetX = other._pOffsetX;
    this->_pOffsetY = other._pOffsetY;
    this->_pColor = other._pColor;
    this->_rect = other._rect;
}

Player::~Player()
{
/**
* @brief Destructor (Rule of Five)
*
* If the player gets destroyed then the game should end.
* @see QuitCommand(command.h)
*/
    _pQuitCmd->Execute();
}

std::unique_ptr<GameObject> Player::Clone() 
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
    auto pCopy = new Player(*this); 
    pCopy->_HP = *pCopy->_pBaseHP;
    return std::unique_ptr<GameObject>(pCopy);
}