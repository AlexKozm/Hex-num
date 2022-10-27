#include "Hex_num/base/hex_num.h"
#include <optional>
#include <vector>
#if !defined(OVERL_STAT_HEX_NUM_H)
#define OVERL_STAT_HEX_NUM_H

#include "hex_num_s.h"

namespace overl_stat_hex_num {

class Hex_num : public static_hex::Hex_num {
  protected:
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
  Hex_num(const hex_num::Hex_num &that);
  //TODO
  ~Hex_num();

  bool operator==(const hex_num::Hex_num &hex) const;
  hex_num::Hex_num &operator<<(int n);
  hex_num::Hex_num &operator>>(int n);
  friend std::istream &operator>>(std::istream &is, hex_num::Hex_num &hex);
  friend std::ostream &operator<<(std::ostream &os, const hex_num::Hex_num &hex);
  friend hex_num::Hex_num operator+(const Hex_num &a, const Hex_num &b);
  friend hex_num::Hex_num operator-(const Hex_num &a, const Hex_num &b);
};

} // namespace overl_stat_hex_num

#endif
