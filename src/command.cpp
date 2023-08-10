#include "command.h"
#include "constant.h"
#include "game.h"
#include "game_object.h"
#include "game_object_factory.h"

void QuitCommand::Execute()
{ 
/**
 * @brief executes the Command by quitting the main game loop.
*/
    pGame->SetRunning(false); 
}



void MoveUpCommand::Execute()
{
/**
 * @brief executes the Command by moving the GameObject one cell up.
 * 
 * @note GetMoveBlock() manages the cooldown after an action had taken place.
 * Only if this function does not block the action it can be executed.
*/
    if (pGameObj->GetMoveBlock()) return;
    
    int x = pGameObj->GetX();
    int y = pGameObj->GetY();
    int dy = CONST::GRID_HEIGHT;

    pGameObj->SetPos(x, y - dy);
}



void MoveDownCommand::Execute()
{
/**
 * @brief executes the Command by moving the GameObject one cell down.
 * 
 * @note GetMoveBlock() manages the cooldown after an action had taken place.
 * Only if this function does not block the action it can be executed.
*/
    if (pGameObj->GetMoveBlock()) return;

    int x = pGameObj->GetX();
    int y = pGameObj->GetY();
    int dy = CONST::GRID_HEIGHT;

    pGameObj->SetPos(x, y + dy);
}



void MoveRightCommand::Execute()
{
/**
 * @brief executes the Command by moving the GameObject one cell right.
 * 
 * @note GetMoveBlock() manages the cooldown after an action had taken place.
 * Only if this function does not block the action it can be executed.
*/
    if (pGameObj->GetMoveBlock()) return;

    int x = pGameObj->GetX();
    int y = pGameObj->GetY();

    bool isOnRightEdge = (x == CONST::SCREEN_WIDTH - CONST::GRID_WIDTH);
    int dx = CONST::GRID_WIDTH * (!isOnRightEdge);

    pGameObj->SetPos(x + dx, y);
}



void MoveLeftCommand::Execute()
{
/**
 * @brief executes the Command by moving the GameObject one cell left.
 * 
 * @note GetMoveBlock() manages the cooldown after an action had taken place.
 * Only if this function does not block the action it can be executed.
*/
    if (pGameObj->GetMoveBlock()) return;

    int x = pGameObj->GetX();
    int y = pGameObj->GetY();

    bool isOnLeftEdge = (x == 0);
    int dx = CONST::GRID_WIDTH * (!isOnLeftEdge);

    pGameObj->SetPos(x - dx, y);
}



FireCommand::FireCommand(const FireCommand& other) : _cProjectile{other._cProjectile}
{
/**
 * @brief Copy-Constructor (Rule of Five)
 * 
 * @param other reference to another FireCommand to be copied
*/
    this->pGameObj = other.pGameObj;
    this->pFactory = other.pFactory;
}

void FireCommand::Execute()
{
/**
 * @brief executes the Command by firing a bullet.
 * 
 * @note GetFireBlock() manages the cooldown after an action had taken place.
 * Only if this function does not block the action it can be executed.
*/
    if (pGameObj->GetFireBlock()) return;
    if (!this->GetLogger()) this->SetLogger(pGameObj->GetLogger());
    
    auto pBullet = pFactory->Get(BULLET);
    pBullet->SetFriendly(pGameObj->GetFriendly());
    pBullet->SetPos(pGameObj->GetX(), pGameObj->GetY());

    _cProjectile.insert( std::move(pBullet) );
}