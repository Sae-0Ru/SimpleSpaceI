#include "game_object_factory.h"
#include "button.h"
#include "command.h"
#include "game_object.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include "shield.h"

 GameObjectFactory::GameObjectFactory(std::shared_ptr<ButtonManager> pButtonManager, std::shared_ptr<QuitCommand> pQuitCmd, std::shared_ptr<FireCommand> pFireCmd)
{
/**
 * @brief constructs concrete prototypes of game-objects and saves them internally
 * 
 * @note here using an enum over an enum class pays off.
 * we can use an array over a map to save the prototypes without forgetting which types were saved on which position.
 * since an enum type can be interpreted as an integer. And since all values are unique, we have an indirect 1 on 1 mapping. 
 * 
 * @param pButtonManager pointer to a ButtonManager in order to register necessary commands to keyboard button inputs
 * @param pQuitCmd pointer to QuitCommand which already has a connected instance of Game
 * @param pFireCmd pointer to FireCommand which already has a connected set for placing the fired projectiles into it. 
*/
    _cPrototype.reserve(4);

    pFireCmd->Set(this);
    auto pCopyFireCmd = std::make_shared<FireCommand>(pFireCmd);
    
    //
    auto pPlayer = std::unique_ptr<Player>(new Player(pQuitCmd, pFireCmd));
    pPlayer->SetBaseHP(3);
    pPlayer->SetFireBlock(90);
    pPlayer->SetMoveBlock(10);
    pPlayer->SetColor(50, 255, 150, 255);
    pPlayer->SetScaling(0.8);

    pButtonManager->Register(SDLK_d, pPlayer->GetMoveRight());
    pButtonManager->Register(SDLK_a, pPlayer->GetMoveLeft());
    pButtonManager->Register(SDLK_SPACE, pPlayer->GetFireCmd());

    _cPrototype.insert({PLAYER, std::move(pPlayer)});
    
    // 
    auto pEnemy = std::unique_ptr<Enemy>(new Enemy(pQuitCmd, pCopyFireCmd));
    pEnemy->SetBaseHP(1);
    pEnemy->SetProbabilityToFire(5);
    pEnemy->SetFireBlock(60);
    pEnemy->SetMoveBlock(45);
    pEnemy->SetColor(150, 50, 255, 255);
    pEnemy->SetScaling(0.8);

    _cPrototype.insert({ENEMY, std::move(pEnemy)});
    
    // 
    auto pBullet = std::unique_ptr<Bullet>(new Bullet());
    pBullet->SetBaseHP(1);
    pBullet->SetMoveBlock(10);
    pBullet->SetColor(255, 150, 50, 255);
    pBullet->SetScaling(0.4);

    _cPrototype.insert({BULLET, std::move(pBullet)});
    
    // 
    auto pShield = std::unique_ptr<Shield>(new Shield());
    pShield->SetBaseHP(5);
    pShield->SetMoveBlock(1000);
    pShield->SetColor(50, 150, 255, 255);
    pShield->SetScaling(0.9);

    _cPrototype.insert({SHIELD, std::move(pShield)});
}

std::unique_ptr<GameObject> GameObjectFactory::Get(const TYPE& T)
{
/**
 * @brief creates and releases a copy of the specified game-object wrapped in a unique pointer
 * 
 * @param T reference to an enum value which relates to a concrete game-object in the array hold by this factory
 * @return unique pointer to a clone of a prototype 
*/
    return _cPrototype[T]->Clone();
}