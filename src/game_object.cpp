#include "game_object.h"
#include "constant.h"
#include "button.h"
#include "command.h"

void GameObject::Render(SDL_Renderer* pRenderer)
{
/**
 * @brief renders the game_object.
 * 
 * @note This function must be called once per frame.
 * @note decreasing the cooldown members _blockFire and _blockMove is not really the task of this function
 * but I wanted to hide this task from children that might forget to implement it.
 * And I wanted a place to reliably decrease them so for me this was a fair compromise.
 * 
 * @param pRenderer pointer to the renderer-object
*/
    _blockFire -= 1 * (_blockFire > 0);
    _blockMove -= 1 * (_blockMove > 0);

    _rect.x = _xPos + *_pOffsetX;
    _rect.y = _yPos + *_pOffsetY;

    SDL_SetRenderDrawColor(pRenderer, _pColor->r, _pColor->g, _pColor->b, _pColor->a);
    SDL_RenderFillRect(pRenderer, &_rect);
}

bool GameObject::CollideWith(const GameObject& other) const 
{ 
/**
 * @brief checks if two instances collide with each other 
 * by comparing the the upper left grid cell coordinates.
 * 
 * @note comparing integer values with equality is safe
 * 
 * @param other reference to another game-object
 * @return true if the two instances overlaps with each other, false otherwise.
*/
    return (this->_xPos == other._xPos) && (this->_yPos == other._yPos); 
}

void GameObject::SetHP(const int& HP) 
{ 
/**
 * @brief resets the HP-value
 * 
 * @note I wanted a shortcut for decreasing the value by one besides resetting the value.
 * Since game-objects get destroyed if ther HP reaches 0 negative values are overkill. 
 * Therefore I chose -1 to be the magic number that is the default value if no input would be given
 * to change this functions inner workings to decreasing the HP-value by 1 instead of resetting it.
 * 
 * @param HP if HP != -1 this parameter will the the set the HP-value of this instance.
 * Otherwise the HP-value gets reduced by 1.
*/
    _HP = (_HP - 1) * (HP == -1) + (HP) * ( HP > -1); 
}

bool GameObject::GetFireBlock()
{
/**
 * @brief checks wether this instance can take another action.
 * 
 * @note We have to remember that each frame _blockFire is reduced by 1.
 * Case 1 (_blockFire > 0):
 *      _blockFire > 0 evaluates to true, so only the left side of the return statement is executed 
 *      making this function only compair the cooldown-value nothing else. 
 * Case 2 (_blockFire == 0):
 *      _blockFire > 0 evaluated to false, so the right side of the return statement is executed as well.
 *      (_blockFire = *_pBlockFire) resets the value for the cooldown starting the count down all over.
 *      In oder to return "false" signaling that _blockFire reached 0 
 *      negating the above to !(_blockFire = *_pBlockFire) returns false in this case and in conclusion returning false || false (= false).
 * 
 * @warning for this function to work properly 
 * the value behind _pBlockFire must be greater than 0.
 * 
 * @return true if cooldown has not reached zero yet, false otherwise.
*/
    return (_blockFire > 0 || !(_blockFire = *_pBlockFire));
}

bool GameObject::GetMoveBlock()
{
/**
 * @brief checks wether this instance can take another action.
 * 
 * @note We have to remember that each frame _blockFire is reduced by 1.
 * Case 1 (_blockFire > 0):
 *      _blockFire > 0 evaluates to true, so only the left side of the return statement is executed 
 *      making this function only compair the cooldown-value nothing else. 
 * Case 2 (_blockFire == 0):
 *      _blockFire > 0 evaluated to false, so the right side of the return statement is executed as well.
 *      (_blockFire = *_pBlockFire) resets the value for the cooldown starting the count down all over.
 *      In oder to return "false" signaling that _blockFire reached 0 
 *      negating the above to !(_blockFire = *_pBlockFire) returns false in this case and in conclusion returning false || false (= false).
 * 
 * @warning for this function to work properly 
 * the value behind _pBlockFire must be greater than 0.
 * 
 * @return true if cooldown has not reached zero yet, false otherwise.
*/
    return (_blockMove > 0 || !(_blockMove = *_pBlockMove));
}

void GameObject::SetColor(const int& r, const int& g, const int& b, const int& a)   
{
/**
 * @brief sets the SDL_Color 
 * 
 * @param r RGB-value for the red-channel between 0 and 255
 * @param g RGB-value for the green-channel between 0 and 255
 * @param b RGB-value for the blue-channel between 0 and 255
 * @param a RGB-value for the alpha-channel between 0 and 255
*/
    _pColor = std::make_shared<SDL_Color>();
    _pColor->r = r;
    _pColor->g = g;
    _pColor->b = b;
    _pColor->a = a;
}

void GameObject::SetScaling(const float& scale)   
 {
    /**
     * @brief sets the scaling 
     * and calculates the needed offset for central positioning in a grid cell
     * 
     * @note as one of the safety-guards the x,y-coordinates of the SDL_Rect are set both to -1 (init-values for _xPos and _yPos), 
     * positioning the SDL_Rect outside of the "playground" making it liable for destruction.
     * This measure is intended to prevent the prototype from partaking in the game and enforce resetting its clones to a proper position.
     * @see GameLogic
     * 
     * @param scale factor to scale the SDL_Rect in dependance of the grid cells height ans width.
     * it is intended for values in the range of [0, 1] but can handle values outside of this range too. 
     * Then rectangles might overlap on the screen.
    */
    _rect.x = _xPos;
    _rect.y = _yPos;
    _rect.w = CONST::GRID_WIDTH * scale;
    _rect.h = CONST::GRID_HEIGHT * scale;
    
    // linear interpolation from left corner to mid-point evaluated at scale. 0 meaning mid-point and 1 meaning upper left corner of a grid cell.
    _pOffsetX = std::make_shared<int>((scale) * 0 + (1 - scale) * CONST::GRID_WIDTH / 2);
    _pOffsetY = std::make_shared<int>((scale) * 0 + (1 - scale) * CONST::GRID_HEIGHT / 2);
 }