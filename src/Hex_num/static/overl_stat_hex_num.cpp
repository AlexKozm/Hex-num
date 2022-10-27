#include "overl_stat_hex_num.h"
#include "Hex_num/base/hex_num.h"
#include "iostream"
#include "hex_num_s.h"
#include <string>

namespace overl_stat_hex_num {

Hex_num::Hex_num() : static_hex::Hex_num::Hex_num() {}
Hex_num::Hex_num(int hex) : static_hex::Hex_num(hex) {}
Hex_num::Hex_num(std::string hex) : static_hex::Hex_num(hex) {}
Hex_num::Hex_num(const hex_num::Hex_num &that) : static_hex::Hex_num(that){};
Hex_num::~Hex_num(){};

bool Hex_num::operator==(const hex_num::Hex_num &hex) const {
  return hex_num::Hex_num::equal(*this, hex);
}

hex_num::Hex_num &Hex_num::operator<<(int n) {
  this->move_left(n);
  return *this;
}
hex_num::Hex_num &Hex_num::operator>>(int n) {
  this->move_right(n);
  return *this;
}

std::istream &operator>>(std::istream &is, hex_num::Hex_num &hex) {
  hex.input(is);
  return is;
}
std::ostream &operator<<(std::ostream &os, const hex_num::Hex_num &hex) {
  hex.output(os);
  return os;
}
hex_num::Hex_num operator+(const Hex_num &a, const Hex_num &b) {
  return static_hex::Hex_num::sum(a, b);
}

hex_num::Hex_num operator-(const Hex_num &a, const Hex_num &b) {
  return static_hex::Hex_num::dif(a, b);
}
} // namespace overl_stat_hex_num
