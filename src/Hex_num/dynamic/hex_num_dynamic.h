#include <vector>
#if !defined(HEX_NUM_DYNAMIC_H)
#define HEX_NUM_DYNAMIC_H

#include "Hex_num/base/hex_num.h"

namespace hex_num_dynamic {
using namespace std;

class Container : public hex_num::Container {
  const static int def_len = 3;
  vector<char> arr = vector<char>(def_len);

public:
  /**
   * @brief Init container with 0's
   */
  Container();
  Container(const Container &that);
  ~Container() override;

  void set_zeros() override;
  char get_val(int pos, char def = '0') const override;
  /**
   * @brief Return val on pos but without sign
   * @details 1. Return cell's val if cell is in container and has not store
   sign bit.
              2. Return val without sign bit if this cell store sign bit
              3. Return def char if container has not cell with that pos
   * @param pos
     @param def - default value that will be returned if container has no cell
                  on given pos
   * @return
   */
  char get_digit(int pos, char def) const override;
  bool get_sign() const override;
  void set_digit(int pos, char val) override;
  void set_val(int pos, char val) override;
  void set_minus() override;
  void unset_minus() override;
  hex_num::Container *get_new() const override;
  hex_num::Container *get_copy() const override;
};

class Hex_num : public hex_num::Hex_num {
public:
  /**
   * @brief Default constructor
   */
  Hex_num();
  /**
   * @brief Constructor with int hex init
   * @param hex
   */
  Hex_num(int hex);
  /**
   * @brief Constructor with string hex init
   * @param hex
   */
  Hex_num(std::string hex);
  Hex_num(const hex_num::Hex_num &that);
  Hex_num(hex_num::Hex_num &&that);
  /**
   * @brief Move assignment
   * @param a
   * @return Itself
   */
  Hex_num &operator=(hex_num::Hex_num &&a);
  /**
   * @brief Copy assignment
   * @param a
   * @return Itself
   */
  Hex_num &operator=(const hex_num::Hex_num &a);
  ~Hex_num();
};

} // namespace hex_num_dynamic

#endif
