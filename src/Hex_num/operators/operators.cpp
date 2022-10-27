#include "hex_num.h"
#include <iostream>

namespace hex_num {

hex_num::Hex_num operator<<(const hex_num::Hex_num &hex, int n) {
  return Hex_num(hex).move_left(n);
}
Hex_num operator>>(const Hex_num &hex, int n) {
  return Hex_num(hex).move_right(n);
}

bool operator==(const hex_num::Hex_num &hex1, const hex_num::Hex_num &hex) {
  return hex_num::Hex_num::equal(hex1, hex);
}

std::istream &operator>>(std::istream &is, hex_num::Hex_num &hex) {
  hex.input(is);
  return is;
}
hex_num::Hex_num operator+(const hex_num::Hex_num &a, const hex_num::Hex_num &b) {
  return Hex_num::sum(a, b);
}

hex_num::Hex_num operator-(const hex_num::Hex_num &a, const hex_num::Hex_num &b) {
  return Hex_num::dif(a, b);
}
std::ostream &operator<<(std::ostream &os, const hex_num::Hex_num &hex) {
  hex.output(os);
  return os;
}
std::ostream &operator<<(std::ostream &os, hex_num::Hex_num &&hex) {
  hex.output(os);
  return os;
}
} // namespace hex_num_dynamic

