#include "logger.h"

Logger::Logger(const std::string& fileName)
{
/**
 * @brief creates and opens a file-stream with the desired name
 * as a .txt-file
 * 
 * @param fileName reference to a string that contains the name of the file. 
*/
    _pName = std::make_unique<std::string>(fileName + ".txt");
    _pFile = new std::ofstream(*_pName, std::ios::trunc);
}

Logger::~Logger()
{
/**
 * @brief closes and destroys the stream.
*/
    if (_pFile->is_open()) 
        _pFile->close();

    delete _pFile;
}

void Logger::Log(const std::string& msg) 
{
/**
 * @brief log a message to the file-stream.
 * 
 * @note Despite SDL beeing parallel my program is linear.
 * So there can not be a data race even if the file-stream is not closed.
 * Reason for that is to improve performance by eliminating the task of finding the new line to write into over and over again. 
 * 
 * @param msg reference to a string that should be logged 
*/
    if (!_pFile->is_open()) 
        _pFile->open(*_pName, std::ios::app);

    *_pFile << msg << "\n";
    _pFile->flush();
    // _pFile->close();
}

std::string Logger::Format(const int& number, int&& digits = 0)
{
/**
 * @brief formats a number to the specified digits into a string.
 * (number = 23, digits = 5) -> "---23"
 * (number = 23, digits = 1) -> "23"
 * 
 * @param number reference to the integer that should be formatted.
 * @param digits rval-reference to the number of digits the number needs to fill
 * 
 * @return string containing the formatted number as a string with the specified length provided by digits
*/
    std::stringstream ss;
    ss << std::setw(digits) << std::setfill('-') << number;

    return ss.str();
}

std::string Logger::Format(const SDL_Keycode& B)
{
/**
 * @brief formats a SDL_Keycode to the keyboard button it represents.
 * 
 * @param B reference to a SDL_Keycode that should be formatted.
 * 
 * return string containing the formatted SDL_Keycode as the keyboard button if the case is contained below.
*/
    switch(B) 
    {
        case 27 : return "(ESC)";
        case 119 : return "(W)";
        case 97 : return "(A)";
        case 115 : return "(S)";
        case 100 : return "(D)";
        case 32 : return "(SPACE)";
        default: return "(NOT REGISTERED)"; 
    }
}