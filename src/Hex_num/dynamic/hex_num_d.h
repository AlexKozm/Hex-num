#if !defined(HEX_NUM_DYNAMIC_H)
#define HEX_NUM_DYNAMIC_H

#include <vector>
#include "Hex_num/base/hex_num.h"
#include "container_d.h"

namespace hex_num_dynamic {

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
  ~Hex_num();
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

};

// hex_num::Hex_num operator<<(const hex_num::Hex_num &hex, int n);
// hex_num::Hex_num operator>>(const hex_num::Hex_num &hex, int n);
// bool operator==(const hex_num::Hex_num &hex1, const hex_num::Hex_num &hex2);
// std::istream &operator>>(std::istream &is, hex_num::Hex_num &hex);
// std::ostream &operator<<(std::ostream &os, const hex_num::Hex_num &hex);
// std::ostream &operator<<(std::ostream &os, hex_num::Hex_num &&hex);
// hex_num::Hex_num operator+(const Hex_num &a, const Hex_num &b);
// hex_num::Hex_num operator-(const Hex_num &a, const Hex_num &b);

} // namespace hex_num_dynamic

#endif
