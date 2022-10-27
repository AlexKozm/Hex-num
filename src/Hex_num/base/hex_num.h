#if !defined(HEX_NUM_ABSTRACT_H)
#define HEX_NUM_ABSTRACT_H

#include <iostream>
#include <stdexcept>
#include <string>
#include "container.h"

namespace hex_num {
/**
 * @class Hex_num
 * @brief Base class for hex_num 
 */
class Hex_num {

protected:
  Container *cont = nullptr;
  /**
   * @brief Create Hex_num with given Container arr
   * @param arr
   */
  Hex_num(Container *arr);
  /**
   * @brief Create Hex_num with given Container arr and init it with hex int or
   * throw an error
   * @param arr
   * @param hex
   */
  Hex_num(Container *arr, int hex);
  /**
   * @brief Create Hex_num with given Container arr and init it with string or
   * throw an error
   * @param arr
   * @param hex
   */
  Hex_num(Container *arr, std::string hex);
  /**
   * @brief Convert string to arr
   * @details Convert string to arr. In case of error throws an exception
              and object stays in undefined state
   * @throw Wrong_format_exception
   * @param str
   */
  void str_to_arr(std::string str);

  /**
   * @brief Replace -0 to 0
     @details In input and maybe in calculation we can get -0 value in 
              direct code. Because direct code should not contain -0
              we should call this function to replace -0 with 0
   */
  void check_for_minus_zero();

public:
  /**
   * @brief Copy constructor
   * @param that
   */
  Hex_num(const Hex_num &that);
  /**
   * @brief Move constructor
   * @param that 
   */
  Hex_num(Hex_num &&that);
  /**
   * @brief Move assignment
   * @param a 
   * @return Itself
   */
  Hex_num &operator=(Hex_num &&a);
  /**
   * @brief Copy assignment
   * @param a 
   * @return Itself
   */
  Hex_num &operator=(const Hex_num &a);

  /**
   * @brief Convert reverse code to additional code
   * @return Itself
   */
  Hex_num *to_additional_code();
  /**
   * @brief Reverce all bits except sign bit
   * @return Itself
   */
  Hex_num *reverse_code();
  /**
   * @brief Convert additional code number to reverse code number
   * @return Itself
   */
  Hex_num *from_add_to_rev_code();
  /**
   * @brief Return sum of a and b
   * @param a In additional code
   * @param b In additional code
   * @return Sum in additional code
   */
  static Hex_num sum_of_additonals(const Hex_num &a, const Hex_num &b);
  /**
   * @brief Moves chars n times to left. Empty cells fills with '0'. Saves num
   *        sign.
   * @param n
   * @return Itself
   */
  Hex_num move_left(unsigned n);
  /**
   * @brief Moves chars n times to right. Empty cells fills with '0'. Saves num
   *        sign.
   * @param n
   * @return Itself
   */
  Hex_num move_right(unsigned n);
  /**
   * @brief Is number even
   * @return 1 if even, else 0
   */
  bool evenness();
  /**
   * @brief Input str from istream and convert it to Hex_num
   * @details Input str from istream and convert it to Hex_num.
              In case of error throws an exception
              and object stays in undefined state
   * @throw Wrong_format_exception
   * @param inp
   */
  std::istream &input(std::istream &inp);
  /**
   * @brief Output string representation in hex format to stream
   * @param out
   */
  std::ostream &output(std::ostream &out) const;
  /**
   * @brief Print Hex_num in direct code with hex num
   * @param out
   */
  void print_container(std::ostream &out);
  /**
   * @brief Checks for equality a and b
   * @param a 
   * @param b 
   * @return if a == b
   */
  static bool equal(const Hex_num &a, const Hex_num &b);
  /**
   * @brief Return sum of a and b
   * @param a 
   * @param b 
   * @return New Hex_num
   */
  static Hex_num sum(const Hex_num &a, const Hex_num &b);
  /**
   * @brief Return difference of a and b
   * @param a 
   * @param b 
   * @return New Hex_num
   */
  static Hex_num dif(Hex_num const &a, Hex_num const &b);

  virtual ~Hex_num();
};

} // namespace hex_num
#endif
