#if !defined(CONTAINER_D_H)
#define CONTAINER_D_H

#include "Hex_num/base/hex_num.h"
#include <vector>

namespace hex_num_dynamic {

class Container : public hex_num::Container {
  const static int def_len = 3;
  std::vector<char> arr = std::vector<char>(def_len);

public:
  /**
   * @brief Init container with 0's
   */
  Container();
  Container(const Container &that);
  Container(Container &&that);
  Container &operator=(const Container &that);
  Container &operator=(Container &&that);
  ~Container() override = default;

  void set_zeros() override;
  bool get_sign() const override;
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
  void set_digit(int pos, char val) override;
  void set_val(int pos, char val) override;
  void set_minus() override;
  void unset_minus() override;
  hex_num::Container *get_new() const override;
  hex_num::Container *get_copy() const override;
};
} // namespace hex_num_dynamic

#endif
