#ifndef TIMER_H
#define TIMER_H

#include <vector>

#include "logger.h"

/**
 * @enum TIME
 * @brief lists an entry for every part of the main game loop that should be measured.
 * 
 * @note it's main purpose is enabling using an array over a map as a container for saving timestamps
 * without compromising relation between the timestamp and it's meaning.
*/
enum TIME
{
    CYCLE = 0,
    INPUT = 1,
    UPDATE = 2,
    RENDER = 3,
    IDLE = 4
};

/**
 * @class Timer
 * @brief initialises and manages all relevant systems for the main game loop. 
 * 
 * @par Collaborations
 * - Game
 *      uses this class like a stopwatch to measure different parts of the main game loop.       
 * 
 * @par Class Hierarchy
 * Stringify(v)
 * |- Timer
 * 
 * @par Design Pattern
 * - (???)
 * 
 * I thought of this like a stopwatch and what features I need in order to measure time accurately. 
 * 
 * @par Member Functions
 * - ToString()
 *      This function is needed for logging purposes that can give log-entries from this class a tag to which the entry can be backtracked to this class.
 *      @see Stringify(logger.h)
*/
class Timer : public Stringify
{
public:
    Timer();

    void Start(const TIME& T);
    void Stop(const TIME& T);
    void Wait();

    std::string ToString() const override;
private:
    std::vector<uint32_t> _cTimePoint;
    std::vector<uint32_t> _cTimeDuration;
    uint32_t _time{0};
    uint8_t _frame{0};
    uint8_t _FPS{0};
};

#endif