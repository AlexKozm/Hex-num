#if !defined(HEX_NUM_ABSTRACT_H)
#define HEX_NUM_ABSTRACT_H

#include <iostream>
#include <stdexcept>
#include <string>

namespace hex_num {

/**
 * @class Container
 * @brief Abstract class for container
 */
class Container {
  size_t len = 0; // current len of container

public:
  /**
   * @brief Get len of the Container
   * @return Length
   */
  size_t get_len();
  /**
   * @brief Set len of the container
   * @param len
   */
  void set_len(size_t len);
  /**
   * @brief Return hex as a char
   * @details Return (hex % 16) and cast ro right char symbol
   * @param hex Should be >= 0
   * @return Hex as a char
   */
  static char hex_remains_to_char(int hex);
  /**
   * @brief Return hex char as int
   * @param hex Should be in 0..9A..F or throws an exception
   * @throw Wrong_format_exception
   * @return int hex
   */
  static int int_hex_from_char(char hex);
  /**
   * @brief Get char on pos in container
   * @param pos
   * @return Char on pos in container
   */
  virtual char get(int pos) = 0;
  /**
   * @brief Set val
   * @param pos
   * @param val
   */
  virtual void set(int pos, char val) = 0;
  /**
   * @brief Make num negative
   */
  virtual void set_minus() = 0;
  /**
   * @brief Make num positive
   */
  virtual void unset_minus() = 0;
  // TODO write a doc. Will be done at sum and dif realization
  virtual Container *get_new() = 0;
};

/**
 * @class Hex_num
 * @brief Class with abstract container
 * @details
 * @todo make abstract
 */
class Hex_num {

protected:
  Container *arr = nullptr;
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

public:
  /**
   * @class Wrong_format_exception
   * @brief Exception for wrong format
   */
  class Wrong_format_exception : public std::runtime_error {
  public:
    /**
     * @brief Constructor with message
     * @param msg
     */
    Wrong_format_exception(std::string msg);
  };

  // TODO
  void move_left(int n);
  // TODO
  void move_right(int n);
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
  void input(std::istream &inp);
  // TODO
  void output(std::ostream &out);
  /**
   * @brief Print Hex_num in direct code with hex num
   * @param out
   */
  void print_container(std::ostream &out);
  // TODO
  static bool equal(Hex_num const &a, Hex_num const &b);
  // TODO
  static Hex_num *sum(Hex_num const &a, Hex_num const &b);
  // TODO
  static Hex_num *dif(Hex_num const &a, Hex_num const &b);

  // virtual ~Hex_num() = 0;
};

} // namespace hex_num
#endif
