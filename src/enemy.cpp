#include "enemy.h"
#include "command.h"
#include "constant.h"

Enemy::Enemy(std::shared_ptr<QuitCommand> pQuitCmd, std::shared_ptr<FireCommand> pFireCmd) : _pQuitCmd{pQuitCmd}, _pFireCmd{pFireCmd}
{
/** 
 * @brief Constructor
 * Since an enemy has a game-ending condition a QuitCommand is needed, which must be already connected the the game-instance.
 * In order for the enemy to fight back a FireCommand is needed, which must be already connected to the set of projectiles
 * in which to place the fired projectiles.
 * @see QuitCommand(command.h)
 * @see FireCommand(command.h)
 * 
 * @param pQuitCmd pointer to a QuitCommand for the game  
 * @param pFireCmd pointer to a FireCommand for this instance
 */
    _pFireCmd->Swap(this);
}

Enemy::Enemy(const Enemy& other)
{
/**
 * @brief Copy-Constructor (Rule of Five)
 * Basic properties for rendering like offset, color, rect need to be copied.
 * Additionally all commands for game-ending and firing are needed.
 * Finally the values for steering movement and random firing are needed as well.
 *
 * @param other Reference to a source which members are to be copied
 */
    this->_pQuitCmd = other._pQuitCmd;

    this->_pFireCmd = std::make_shared<FireCommand>(other._pFireCmd);
    this->_pFireCmd->Swap(this);

    this->_pBaseHP = other._pBaseHP;
    this->_pProbabilityToFire = other._pProbabilityToFire;
    this->_pBlockFire = other._pBlockFire;
    this->_pBlockMove = other._pBlockMove;
    this->_pOffsetX = other._pOffsetX;
    this->_pOffsetY = other._pOffsetY;
    this->_pColor = other._pColor;
    this->_rect = other._rect;
}

void Enemy::Update()
{
/** 
 * @brief This method determines the movement and firing of an instance as well as a game-over condition.
 * The movement should be in a zig-zag style
 *      #->->->v#
 *      #v<-<-<-#
 *      #->->->v#
 * The firing should be random to a given percentage for a given period of time (if the chance misses then the cooldown is applied as well).
 * The game-over condition is reached if an enemy enters the row of the player (the last row).
 * 
 * @note The cooldown is managed by the parent GameObject meaning that an action is to take if the Get[...]Block() function allows it.
 * But the unique situation with the Command that checks this condition too require to reset _blockFire = 0 in order to work properly.
 * 
 * @note this function must be called one per frame
 * 
 * @warning the members for cooldown (for example _blockFore) should not be touched by the concrete class. The related Getter (here GetFireBlock)
 * should be used.
 * @see GameObject
 * @see FireCommand(command.h)
 */
    bool isOnLowerEdge = (GetY() == CONST::SCREEN_HEIGHT -  CONST::GRID_HEIGHT);
    if (isOnLowerEdge) _pQuitCmd->Execute();
    if (!GetFireBlock() && std::experimental::randint(1, 100) <= *_pProbabilityToFire) {_blockFire = 0; _pFireCmd->Execute();}
    if (GetMoveBlock()) return;

    int x = GetX();
    int y = GetY();

    bool isOnRightEdge = (x == CONST::SCREEN_WIDTH -  CONST::GRID_WIDTH);
    bool isOnLeftEdge = (x == 0);

    int dx = CONST::GRID_WIDTH * (((y % 2 == 0) && !isOnRightEdge) - ((y % 2 != 0) && !isOnLeftEdge));
    int dy = CONST::GRID_HEIGHT * ((isOnLeftEdge || isOnRightEdge) && !dx);

    SetPos(x + dx, y + dy);
}

std::unique_ptr<GameObject> Enemy::Clone() 
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
    auto pCopy = new Enemy(*this);
    pCopy->_HP = *pCopy->_pBaseHP;
    return std::unique_ptr<GameObject>(pCopy);
}