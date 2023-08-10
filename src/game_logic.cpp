#include "game_logic.h"
#include "constant.h"
#include "game_object_factory.h"
#include "game_object.h"

GameLogic::GameLogic(std::unique_ptr<GameObjectFactory>&& pFactory, std::unordered_set<std::unique_ptr<GameObject>>& cGameObject) : _pFactory{std::move(pFactory)}
{
/**
 * @brief constructs the starting position of the game.
 * - two full rows of Enemy's in the top of the screen
 * - one full row of Shield's on the row above the bottom
 * - one Player on the bottom row.
 * 
 * @param pFactroy pointer to the factory for reproducing game-objects
 * @param cGameObject reference for the Container of game-objects for Player/Enemy/Shield
*/
    _enemyBlock = _ENEMY_BLOCK;

    int n = CONST::X_GRID_COUNT;
    int dx = CONST::GRID_WIDTH;
    int dy = CONST::GRID_HEIGHT;

    auto pPlayer = _pFactory->Get(PLAYER);
    pPlayer->SetPos(0, (n-1) * dy);
    cGameObject.insert( std::move(pPlayer) );


    std::unique_ptr<GameObject> pEnemy;
    for (int j = 0; j < 2; ++j)
        for (int i = 0; i < n; ++i)
        {
            ++_enemyCount;

            pEnemy = _pFactory->Get(ENEMY);
            pEnemy->SetPos(i * dx, j * dy);
            cGameObject.insert( std::move(pEnemy) );
        }

    std::unique_ptr<GameObject> pShield;
    for (int i = 0; i < n; ++i)
        {
            pShield = _pFactory->Get(SHIELD);
            pShield->SetPos(i * dx, (n-2) * dy);
            cGameObject.insert( std::move(pShield) );
        }
}

void GameLogic::HandleCollision(std::unordered_set<std::unique_ptr<GameObject>>& cGameObject, std::unordered_set<std::unique_ptr<GameObject>>& cProjectile)
{
/**
 * @brief checks which game-objects did collide on current frame
 * and reduce their HP in return.
 * If any game-object is sentenced for destruction(HP reaches zero) it is erased from the container.
 * 
 * @note Erasing a game-object from it's container deletes it because the game-objects are stored as unique pointers. 
 * 
 * @param cGameObject reference for the Container of game-objects for Player/Enemy/Shield
 * @param cProjectile reference for the Container of game-objects for Bullet
*/
    // GO <-> Bullet
    for (auto it1 = cGameObject.begin(); it1 != cGameObject.end(); ++it1)
        for (auto it2 = cProjectile.begin(); it2 != cProjectile.end(); ++it2)
            if ((*it1)->CollideWith(**it2) && ((*it1)->GetFriendly() != (*it2)->GetFriendly()))
            {
                (*it1)->SetHP();
                (*it2)->SetHP();
            }

    // Bullet <-> Bullet
    for (auto it1 = cProjectile.begin(); it1 != cProjectile.end(); ++it1)
        for (auto it2 = cProjectile.begin(); it2 != cProjectile.end(); ++it2)
            if ((it1 != it2) && (*it1)->CollideWith(**it2) && ((*it1)->GetFriendly() != (*it2)->GetFriendly()))
            {
                (*it1)->SetHP();
                (*it2)->SetHP();
            }

    // GO <-> GO
    for (auto it1 = cGameObject.begin(); it1 != cGameObject.end(); ++it1)
        for (auto it2 = cGameObject.begin(); it2 != cGameObject.end(); ++it2)
            if ((it1 != it2) && (*it1)->CollideWith(**it2) && ((*it1)->GetFriendly() != (*it2)->GetFriendly()))
            {
                (*it1)->SetHP(0);
                (*it2)->SetHP(0);
            }

    // CleanUp
    int minX = 0;
    int maxX = CONST::SCREEN_WIDTH - CONST::GRID_WIDTH;
    int minY = 0;
    int maxY = CONST::SCREEN_HEIGHT - CONST::GRID_HEIGHT;

    for (auto it = cGameObject.begin(); it != cGameObject.end(); )
        if (!((*it)->GetHP() > 0) || ((*it)->GetX() < minX || maxX < (*it)->GetX()) || ((*it)->GetY() < minY || maxY < (*it)->GetY()))
        {
            _enemyDestr += 1 * (!(*it)->GetFriendly());
            _enemyCount -= 1 * (!(*it)->GetFriendly());

            cGameObject.erase(it++);
        }
        else
            it++;

    for (auto it = cProjectile.begin(); it != cProjectile.end(); )
        if (!((*it)->GetHP() > 0) || ((*it)->GetX() < minX || maxX < (*it)->GetX()) || ((*it)->GetY() < minY || maxY < (*it)->GetY()))
            cProjectile.erase(it++);
        else
            it++;
}

void GameLogic::Update(std::unordered_set<std::unique_ptr<GameObject>>& cGameObject)
{
/**
 * @brief may reproduce an Enemy an placing him in the container.
 * 
 * @note the function below tackles different scenarios:
 * - if Enemy's are destroyed without having them reproduced increases the possibility of reproduction. (game needs to ramp up the stress)
 * - if Enemy's are not destroyed with reproducing decreases the possibility of reproduction. (game needs to lower the stress)
 * - if (Enemy reproduced ~ Enemy destroyed) then the possibility of reproduction is increased (game needs to keep up the stress)
 * - if the game goes on for a long time and the destruction of Enemy's add up then the possibility of reproduction is increased. (bringing the game to an end by overwhelming the player) 
 * 
 * @param cGameObject reference for the Container of game-objects for Player/Enemy/Shield
*/
    int x = _enemyCount / (_enemyDestr * (_enemyDestr > 0) + 1.0 * !(_enemyDestr > 0));
    int likelihood = 100 / (x * (x > 0) + 1.0 * !(x > 0));  
    if (!GetEnemyBlock() && std::experimental::randint(1, 100) <= likelihood)
    {
        ++_enemyCount;

        auto pEnemy = _pFactory->Get(ENEMY);
        pEnemy->SetPos(0, 0);
        cGameObject.insert( std::move(pEnemy) );
    }
}

bool GameLogic::GetEnemyBlock()
{ 
/**
 * @brief reduces and resets the cooldown.
 * @see GameObject
*/
    return (_enemyBlock > 0 || !(_enemyBlock = _ENEMY_BLOCK));
}