#if !defined(HEX_NUM_H)
#define HEX_NUM_H

#include <iostream>
#include <stdexcept>
#include <string>
#include "hex_num_abstract.h"

namespace static_hex {

class Container : public hex_num::Container {
  const static size_t stat_len = 31;
  char arr[stat_len] = {};

public:
  Container();
  char get(int pos) override;
  void set(int pos, char val) override;
  void set_minus() override;
  void unset_minus() override;
  hex_num::Container *get_new() override;
};

class Hex_num : public hex_num::Hex_num {
public:
  Hex_num();
  Hex_num(int hex);
  Hex_num(std::string hex);
  Hex_num(hex_num::Hex_num &base);
  // ~Hex_num();
};

} // namespace static_hex

#endif
