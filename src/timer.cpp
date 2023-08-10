#include "timer.h"
#include "constant.h"

Timer::Timer()
{
/**
 * @brief constructs the instance by reserving enough space in the containers
 * for timestamps and intervals.
*/
    this->SetLogger("LogPerf");
    _cTimePoint.reserve(5);
    _cTimeDuration.reserve(5);
}

void Timer::Start(const TIME& T)
{
/**
 * @brief saves the current Ticks for a specified timestamp in ms.
 * 
 * @param T reference to a timestamp to be measured.
 *          @see TIME
*/
    _cTimePoint[T] = SDL_GetTicks();
}

void Timer::Stop(const TIME& T)
{
/**
 * @brief calculates the duration from this call back to when Start() was called with this input in ms.
 *
 * @param T reference to a timestamp to be measured.
 *          @see TIME
*/
    _cTimeDuration[T] = SDL_GetTicks() - _cTimePoint[T];
}

void Timer::Wait()
{
/**
 * @brief waits the amount of time to reach the targeted frame-rate
 * and keeps track of current frame, frames per second and correction for calculation all these values.
 * @see CONST (constant.h)
*/
    _cTimePoint[IDLE] = SDL_GetTicks();
    _cTimeDuration[IDLE] = (CONST::MS_PER_FRAME > _cTimeDuration[CYCLE]) ? CONST::MS_PER_FRAME - _cTimeDuration[CYCLE] : 0;

    _time += _cTimeDuration[CYCLE] + _cTimeDuration[IDLE];
    if (_time > CONST::MS_PER_SECOND)
    {
        _FPS = _frame;
        _frame = 0;
        _time -= CONST::MS_PER_SECOND;
    }
    ++_frame;
    
    uint32_t correction = SDL_GetTicks() - _cTimePoint[IDLE];
    _cTimeDuration[IDLE] = (_cTimeDuration[IDLE] > correction) ? _cTimeDuration[IDLE] - correction : 0;
    
    SDL_Delay(_cTimeDuration[IDLE]);
}

std::string Timer::ToString() const
{
    std::string msg = " <Timer> - ";
    msg += "FPS: " + Logger::Format(_FPS, 2);

    msg += " |+| Input: " + Logger::Format(_cTimeDuration[INPUT], 4);
    msg += " (" + Logger::Format((_cTimeDuration[CYCLE] != 0) ? 100 * _cTimeDuration[INPUT] / _cTimeDuration[CYCLE] : 0, 3) + "%)";

    msg += " | Update: " + Logger::Format(_cTimeDuration[UPDATE], 4);
    msg += " (" + Logger::Format((_cTimeDuration[CYCLE] != 0) ? 100 * _cTimeDuration[UPDATE] / _cTimeDuration[CYCLE] : 0, 3) + "%)";

    msg += " | Render: " + Logger::Format(_cTimeDuration[RENDER], 4);
    msg += " (" + Logger::Format((_cTimeDuration[CYCLE] != 0) ? 100 * _cTimeDuration[RENDER] / _cTimeDuration[CYCLE] : 0, 3) + "%)";

    msg += " |+| Cycle: " + Logger::Format(_cTimeDuration[CYCLE], 4);
    msg += " (" + Logger::Format(100 * _cTimeDuration[CYCLE] / CONST::MS_PER_FRAME, 3) + "%)";

    msg += " | Idle: " + Logger::Format(_cTimeDuration[IDLE], 4);
    msg += " (" + Logger::Format(100 * _cTimeDuration[IDLE] / CONST::MS_PER_FRAME, 3) + "%)";

    return msg;
}