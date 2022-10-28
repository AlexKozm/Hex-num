#include "hex_num_d.h"

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

} // namespace hex_num_dynamic

