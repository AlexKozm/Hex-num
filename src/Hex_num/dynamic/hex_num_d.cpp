#include "hex_num_d.h"
// #include "vector"
#include <array>
#include <tuple>
#include <utility>
#include <vector>
#include <iostream>

namespace hex_num_dynamic {

Hex_num::Hex_num() : hex_num::Hex_num::Hex_num(new Container) {}
Hex_num::Hex_num(int hex) : hex_num::Hex_num(new Container, hex) {}
Hex_num::Hex_num(std::string hex) : hex_num::Hex_num(new Container, hex) {}
Hex_num::Hex_num(const hex_num::Hex_num &that) : hex_num::Hex_num(that) {
  std::cout << "Copy constructor of dynamic class" << std::endl;
};
Hex_num::Hex_num(hex_num::Hex_num &&that) : hex_num::Hex_num(that) {
  std::cout << "Move constructor of dynamic class" << std::endl;
};
Hex_num &Hex_num::operator=(const hex_num::Hex_num &a) {
  std::cout << "Copy assignment of dyn class" << std::endl;
  hex_num::Hex_num::operator=(a);
  return *this;
}
Hex_num &Hex_num::operator=(hex_num::Hex_num &&a) {
  std::cout << "Move assignment of dyn class" << std::endl;
  hex_num::Hex_num::operator=(std::move(a));
  return *this;
}
Hex_num::~Hex_num() {
  delete cont;
  cont = nullptr;
};

//-------------------------------------------------------------


// hex_num::Hex_num operator<<(const hex_num::Hex_num &hex, int n) {
//   return Hex_num(hex).move_left(n);
// }
// hex_num::Hex_num operator>>(const hex_num::Hex_num &hex, int n) {
//   return Hex_num(hex).move_right(n);
// }
//
// bool operator==(const hex_num::Hex_num &hex1, const hex_num::Hex_num &hex) {
//   return hex_num::Hex_num::equal(hex1, hex);
// }
//
// std::istream &operator>>(std::istream &is, hex_num::Hex_num &hex) {
//   hex.input(is);
//   return is;
// }
// hex_num::Hex_num operator+(const Hex_num &a, const Hex_num &b) {
//   return Hex_num::sum(a, b);
// }
//
// hex_num::Hex_num operator-(const Hex_num &a, const Hex_num &b) {
//   return hex_num_dynamic::Hex_num::dif(a, b);
// }
// std::ostream &operator<<(std::ostream &os, const hex_num::Hex_num &hex) {
//   hex.output(os);
//   return os;
// }
// std::ostream &operator<<(std::ostream &os, hex_num::Hex_num &&hex) {
//   hex.output(os);
//   return os;
// }

} // namespace hex_num_dynamic

