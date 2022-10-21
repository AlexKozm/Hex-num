#include "overl_dyn_hex_num.h"
#include "Hex_num/base/hex_num.h"
#include "iostream"
#include "hex_num_dynamic.h"
#include <string>

using namespace std;
namespace overl_dyn_hex_num {

Hex_num::Hex_num() : hex_num_dynamic::Hex_num::Hex_num() {}
Hex_num::Hex_num(int hex) : hex_num_dynamic::Hex_num(hex) {}
Hex_num::Hex_num(std::string hex) : hex_num_dynamic::Hex_num(hex) {}
Hex_num::Hex_num(const Hex_num &that) : hex_num_dynamic::Hex_num(that){}
Hex_num::Hex_num(Hex_num &&that) : hex_num_dynamic::Hex_num(that){}
Hex_num &Hex_num::operator=(const hex_num::Hex_num &a) {
  hex_num::Hex_num::operator=(a);
  return *this;
}
Hex_num &Hex_num::operator=(hex_num::Hex_num &&a) {
  hex_num::Hex_num::operator=(a);
  return *this;
}
Hex_num::~Hex_num(){}

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

istream &operator>>(istream &is, hex_num::Hex_num &hex) {
  hex.input(is);
  return is;
}
ostream &operator<<(ostream &os, const hex_num::Hex_num &hex) {
  hex.output(os);
  return os;
}
ostream &operator<<(ostream &os, const hex_num::Hex_num &&hex) {
  hex.output(os);
  return os;
}
hex_num::Hex_num operator+(const Hex_num &a, const Hex_num &b) {
  return hex_num_dynamic::Hex_num::sum(a, b);
}

hex_num::Hex_num operator-(const Hex_num &a, const Hex_num &b) {
  return hex_num_dynamic::Hex_num::dif(a, b);
}
} // namespace overl_stat_hex_num
