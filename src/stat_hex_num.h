#if !defined(HEX_NUM_H)
#define HEX_NUM_H

#include <iostream>
#include <stdexcept>
#include <string>
#include "hex_num_abstract.h"

namespace static_hex {


//TODO
class Container : public hex_num::Container {
  const static size_t stat_len = 7;
  char arr[stat_len] = {};

public:
  /**
   * @brief Init container with 0's
   */
  Container();
  // TODO
  void set_zeros() override;
  //TODO
  char get(int pos) const override;
  //TODO
  void set(int pos, char val) override;
  // TODO
  void force_set(int pos, char val) override;
  // TODO
  void set_minus() override;
  // //TODO
  // void unset_minus() override;
  //TODO
  hex_num::Container *get_new() const override;
  //TODO
  hex_num::Container *get_copy() const override;
  // TODO
  ~Container() override;
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
  //TODO
  Hex_num(hex_num::Hex_num &base);
  //TODO
  ~Hex_num();
};

} // namespace static_hex

#endif
