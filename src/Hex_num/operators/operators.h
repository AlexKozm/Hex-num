#if !defined(OPETATORS_H)
#define OPETATORS_H

#include <vector>
#include "Hex_num/base/hex_num.h"
#include "container_d.h"

namespace hex_num {

hex_num::Hex_num operator<<(const hex_num::Hex_num &hex, int n);
hex_num::Hex_num operator>>(const hex_num::Hex_num &hex, int n);
bool operator==(const hex_num::Hex_num &hex1, const hex_num::Hex_num &hex2);
std::istream &operator>>(std::istream &is, hex_num::Hex_num &hex);
std::ostream &operator<<(std::ostream &os, const hex_num::Hex_num &hex);
std::ostream &operator<<(std::ostream &os, hex_num::Hex_num &&hex);
hex_num::Hex_num operator+(const hex_num::Hex_num &a, const hex_num::Hex_num &b);
hex_num::Hex_num operator-(const hex_num::Hex_num &a, const hex_num::Hex_num &b);

} // namespace hex_num_dynamic

#endif
