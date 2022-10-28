#if !defined(CONTAINER_S_H)
#define CONTAINER_S_H 

#include "hex_num.h"

namespace static_hex {


class Container : public hex_num::Container {
  const static size_t stat_len = 7;
  char arr[stat_len] = {};

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
   * @details 1. Return cell's val if cell is in container and has not store sign bit.
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

} // namespace static_hex

#endif
