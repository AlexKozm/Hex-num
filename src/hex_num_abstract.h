#if !defined(HEX_NUM_H)
#define HEX_NUM_H

#include <iostream>
#include <stdexcept>
#include <string>

namespace hex_num {

/**
 * @class Container
 * @brief Abstract class for container
 */
class Container {
public:
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
  virtual Container *get_new() = 0;
};

/**
 * @class Hex_num
 * @brief Class with abstract container
 * @details
 */
class Hex_num {
protected:
  Container *arr;
  Hex_num(Container *arr);
  Hex_num(Container *arr, int hex);
  Hex_num(Container *arr, std::string hex);

public:
  void move_left();
  void move_right();
  bool evenness();
  void input(std::istream inp);
  void output(std::istream out);
  static bool equal(Hex_num const &a, Hex_num const &b);
  static Hex_num *sum(Hex_num const &a, Hex_num const &b);

  // virtual ~Hex_num() = 0;
};

} // namespace hex_num
#endif
