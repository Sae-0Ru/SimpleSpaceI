#ifndef LOGGER_H
#define LOGGER_H

#include <memory>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>

#include <SDL2/SDL.h>

/**
 * @class Logger
 * @brief handles the file-stream an provides access to to it.
 * 
 * @par Collaborations
 * - Stringify
 *      creates an interface for hiding the management of Logger and the file-stream.
 * 
 * @par Class Hierarchy
 * none
 * 
 * @par Design Pattern
 * (???)
 * 
 * Since SDL seems to block my console-output I needed an alternative for using <iostream> to look into my program. 
*/
class Logger
{
public:
    Logger() : Logger("Log") {}
    Logger(const std::string& fileName);
    ~Logger();

    void Log(const std::string& msg);
    
    static std::string Format(const int& number, int&& digits);
    static std::string Format(const SDL_Keycode& B);

private:
    std::ofstream* _pFile = nullptr;
    std::unique_ptr<std::string> _pName;
};

/**
 * @class Stringify
 * @brief provides an interface for hiding the management of Logger and the file-stream.
 * 
 * @par Collaborations
 * All other classes that want to be "logggable".
 * 
 * @par Class Hierarchy
 * none
 * 
 * @par Design Pattern
 * (???)
 * 
 * I intended for a simple interface. 
 * It should create a logger by only giving a name,
 * spread the logger for many to write on one file,
 * log an entry by a function-call and give the message
 * and for a class that implements this interface a way to represent itself in the logger.
*/
class Stringify
{
public:
    void SetLogger(const std::string& fileName = "Log") { _pLogger = std::make_shared<Logger>(fileName); }
    void SetLogger(std::shared_ptr<Logger> pLogger) { _pLogger = pLogger; }
    std::shared_ptr<Logger> GetLogger() const { return _pLogger; }

    void Log(const std::string& msg) { if (_pLogger) _pLogger->Log(msg); }
    virtual std::string ToString() const = 0; // { std::string msg = ""; return msg; }

protected:
    std::shared_ptr<Logger> _pLogger = nullptr;
};

#endif 