#include "Hex_num/base/hex_num_abstract.h"
#include <optional>
#include <vector>
#if !defined(OVERL_dyn_HEX_NUM_H)
#define OVERL_dyn_HEX_NUM_H

#include "hex_num_dynamic.h"

using namespace std;
namespace overl_dyn_hex_num {

class Hex_num : public hex_num_dynamic::Hex_num {
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
  friend istream &operator>>(istream &is, hex_num::Hex_num &hex);
  friend ostream &operator<<(ostream &os, const hex_num::Hex_num &hex);
  friend ostream &operator<<(ostream &os, hex_num::Hex_num &&hex);
  friend hex_num::Hex_num operator+(const Hex_num &a, const Hex_num &b);
  friend hex_num::Hex_num operator-(const Hex_num &a, const Hex_num &b);
};

} // namespace overl_dyn_hex_num

// ostream &::operator<<(ostream &os, hex_num::Hex_num hex);

#endif
