#include "game.h"
#include "constant.h"
#include "timer.h"
#include "button.h"
#include "command.h"
#include "input_handler.h"
#include "game_object.h"
#include "game_object_factory.h"
#include "game_logic.h"

Game::Game()
{
/**
 * @brief initialises all needed components for the main game loop.
*/
    this->SetLogger("LogResult");

    _pTimer = std::make_unique<Timer>();

    auto pFireCmd = std::make_shared<FireCommand>(_cProjectile);
    auto pQuitCmd = std::make_shared<QuitCommand>(this);
    _pButtonManager = std::make_shared<ButtonManager>();
    _pButtonManager->Register(SDLK_ESCAPE, pQuitCmd);

    auto pFactory = std::make_unique<GameObjectFactory>(_pButtonManager, pQuitCmd, pFireCmd);
    _pInputHandler = std::make_unique<InputHandler>(_pButtonManager);
    
    _pLogic = std::make_unique<GameLogic>(std::move(pFactory), _cGameObject);

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(CONST::SCREEN_WIDTH, CONST::SCREEN_HEIGHT, SDL_WINDOW_BORDERLESS, &_pWindow, &_pRenderer);
    SDL_SetRenderDrawColor(_pRenderer, 0, 0, 0, 255);
    SDL_RenderPresent(_pRenderer);
}

Game::~Game()
{
/**
 * @brief destructs all SDL components.
 * 
 * @note I could have wrapped these components so that a smart pointer could be used,
 * but since SDL is a common library so people using know that they have to manage these components by hand.
 * So I decided against creating another another layer of abstraction and use this Destructor instead.
*/
    SDL_DestroyRenderer(_pRenderer);
    SDL_DestroyWindow(_pWindow);
    SDL_Quit();
}

void Game::Run()
{
/**
 * @brief runs the main game loop
*/
    SetRunning(true);
    while (GetRunning())
    {
        _pTimer->Start(CYCLE);
        _pTimer->Log(_pTimer->ToString());

        _pTimer->Start(INPUT);
        Input();
        _pTimer->Stop(INPUT);

        _pTimer->Start(UPDATE);
        Update();
        _pTimer->Stop(UPDATE);

        _pTimer->Start(RENDER);
        Render();
        _pTimer->Stop(RENDER);
        _pTimer->Stop(CYCLE);

        _pTimer->Wait();
    }

    Log(ToString() + "Your Score: " + std::to_string(_pLogic->GetScore()));
}

void Game::Input()
{
/**
 * @brief handles thr input-phase of the main game loop.
*/
    _pInputHandler->HandleInput();
}

void Game::Update()
{
/**
 * @brief handles the update-phase of the main game loop. 
*/
    _pButtonManager->Update();

    for (auto it = _cGameObject.begin(); it != _cGameObject.end(); ++it)
        (*it)->Update();
 
    for (auto it = _cProjectile.begin(); it != _cProjectile.end(); ++it)
        (*it)->Update();

    _pLogic->HandleCollision(_cGameObject, _cProjectile);
    _pLogic->Update(_cGameObject);
}

void Game::Render()
{
/**
 * @brief handles the render-phase of the main game loop.
*/
    SDL_RenderClear(_pRenderer);

    for (auto it = _cGameObject.begin(); it != _cGameObject.end(); ++it)
        (*it)->Render(_pRenderer);

    for (auto it = _cProjectile.begin(); it != _cProjectile.end(); ++it)
        (*it)->Render(_pRenderer);

    _pLogic->Render();

    SDL_SetRenderDrawColor(_pRenderer, 0, 0, 0, 255);
    SDL_RenderPresent(_pRenderer);
}