/**
 * @file menu.h
 * @brief Menu file
 */

#if !defined(MENU_H)
#define MENU_H

namespace input_menu {

/**
 * @class EOF_exeption
 * @brief Exeption for End Of File
 */
class EOF_exeption {};

/**
 * @brief Get int in [0; max) or throw exeption in case of eof
 * @details Get int in [0; max) or throw exeption in case of eof.
              If input is not a number or the number is not in [0; max),
              function will ask to enter number again.
 * @throw EOF_exeption
 * @param max Upper bound
 * @return int in [0; max) or -1 in case of eof
 */
int get_uint(int max);
/**
 * @brief Get double or throw exeption in case of eof
 * @details Get double or throw exeption in case of eof.
              If input is not a number function will ask to enter number again.
 * @throw EOF_exeption
 * @return Double from input
 */
double get_double();
int big_if(int num);
int menu();
} // namespace input_menu

#endif
