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
  size_t get_len() const;
  /**
   * @brief Set len of the container
   * @param len New length of the container
   */
  void set_len(size_t len);
  /**
   * @brief Set to all container cells '0' value
   */
  virtual void set_zeros() = 0;
  /**
   * @brief Make num negative
   */
  virtual void set_minus() = 0;
  /**
   * @brief Make num positive
   */
  virtual void unset_minus() = 0;
  /**
   * @brief Return sign
   * @return Return 0 if sing is + or 0 and return 1 if sign is -
   */
  virtual bool get_sign() const = 0;
  /**
   * @brief Get char on pos in container
   * @param pos
   * @return Char on pos in container
   */
  virtual char get(int pos) const = 0;
  /**
   * @brief Return val on pos but without sign
   * @details 1. Return val if it is in container.
              2. Return val without sign bit if this cell store sign bit
              3. Return def char if container has not cell with that pos
   * @param pos
     @param def - default value that will be returned if container has no cell
                  on given pos
   * @return
   */
  virtual char weak_get(int pos, char def) const = 0;
  /**
   * @brief Set val but not sign
     @details Set val if it does not touch sign bit else throw an exception
   * @param pos
   * @param val
   */
  virtual void set(int pos, char val) = 0;
  /**
   * @brief Set val to pos even if it touchs number sign
     @details Set val to pos even if it touchs number sign, does nothing if
              container has not cell with such pos
   * @param pos
   * @param val
   */
  virtual void force_set(int pos, char val) = 0;
  // TODO write a doc. Will be done at sum and dif realization
  virtual Container *get_new() const = 0;
  // TODO
  virtual Container *get_copy() const = 0;
  /**
   * @brief Return hex as a char
   * @details Return (hex % 16) and cast ro right char symbol
   * @param hex Should be >= 0
   * @return Hex as a char
   */
  static char int_to_char(int hex);
  /**
   * @brief Return hex char as int
   * @param hex Should be in 0..9A..F or throws an exception
   * @throw Wrong_format_exception
   * @return int hex
   */
  static int char_to_int(char hex);
  // TODO
  virtual ~Container();
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
  // TODO
  Hex_num(const Hex_num &that);
  /**
   * @brief Convert string to arr
   * @details Convert string to arr. In case of error throws an exception
              and object stays in undefined state
   * @throw Wrong_format_exception
   * @param str
   */
  void str_to_arr(std::string str);
  /**
   * @brief Make num positive
   */
  void unset_minus();

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
  /**
   * @brief Output string representation in hex format to stream
   * @param out
   */
  void output(std::ostream &out);
  /**
   * @brief Print Hex_num in direct code with hex num
   * @param out
   */
  void print_container(std::ostream &out);
  // TODO
  Hex_num *to_additional_code();
  // TODO
  Hex_num *reverse_code();
  // TODO
  Hex_num *from_add_to_rev_code();
  // TODO
  static Hex_num sum_of_additonals(const Hex_num &a, const Hex_num &b);
  // TODO
  static bool equal(const Hex_num &a, const Hex_num &b);
  // TODO
  static Hex_num sum(const Hex_num &a, const Hex_num &b);
  // TODO
  static Hex_num dif(Hex_num const &a, Hex_num const &b);

  virtual ~Hex_num();
};

} // namespace hex_num
#endif
