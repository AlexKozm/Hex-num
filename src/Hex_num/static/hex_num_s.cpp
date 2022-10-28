#include "hex_num_s.h"
#include "Hex_num/base/hex_num.h"
#include "container_s.h"

typedef static_hex::Container Container;
typedef static_hex::Hex_num Hex_num;

Hex_num::Hex_num() : hex_num::Hex_num::Hex_num(new Container) {}
Hex_num::Hex_num(int hex) : hex_num::Hex_num(new Container, hex) {}
Hex_num::Hex_num(std::string hex) : hex_num::Hex_num(new Container, hex) {}
Hex_num::Hex_num(const hex_num::Hex_num &that) : hex_num::Hex_num(that) {};
Hex_num::~Hex_num() {
  delete cont;
  cont = nullptr;
};
