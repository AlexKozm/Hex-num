#if !defined(HEX_NUM_H)
#define HEX_NUM_H

#include "hex_num.h"

namespace static_hex {

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
  ~Hex_num();
};

} // namespace static_hex

#endif
