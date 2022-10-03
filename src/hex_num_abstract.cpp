#include "hex_num_abstract.h"
#include "string"
#include <stdexcept>
#include <string>

using namespace hex_num;
using namespace std;

//-----------------Container-----------------------------------
size_t Container::get_len() { return len; }
void Container::set_len(size_t len) { this->len = len; }
//-------------------------------------------------------------

//-----------------Hex_num constructors------------------------
Hex_num::Hex_num(Container *arr) : arr(arr) {}

Hex_num::Hex_num(Container *arr, int hex) : arr(arr) {
  if (hex < 0) {
    arr->set_minus();
    hex = -hex;
  }
  int i = 0;
  while (hex > 0) {
    arr->set(i++, Container::hex_remains_to_char(hex));
    hex /= 16;
  }
}

Hex_num::Hex_num(Container *arr, std::string hex) : arr(arr) {
  str_to_arr(hex);
}

Hex_num::Wrong_format_exception::Wrong_format_exception(std::string msg)
    : std::runtime_error(msg){};
//-------------------------------------------------------------

//-----------------Protected methods---------------------------

// as an example -1A3F, len = 5
void Hex_num::str_to_arr(string str) {
  size_t len = str.length();
  if (len == 0) {
    throw Wrong_format_exception("Empty string");
  }
  if (str.length() > 1 && str[0] == '-') {
    arr->set_minus();
    --len;
  }
  for (size_t i = 0; i < len; ++i) {
    if (string("0123456789ABCDEF").find(str[str.length() - 1 - i]) !=
        str.npos) {
      arr->set(i, str[str.length() - 1 - i]);
    } else {
      throw Hex_num::Wrong_format_exception(
          "Wrong format in converting str to arr");
    }
  }
}

char Container::hex_remains_to_char(int hex) {
  hex %= 16;
  if (hex < 10) {
    return '0' + hex;
  } else {
    return 'A' + hex - 10;
  }
}

int Container::int_hex_from_char(char hex) {
  if ('0' <= hex && hex <= '9') {
    return hex - '0';
  } else if ('A' <= hex && hex <= 'F') {
    return hex - 'A' + 10;
  } else {
    throw Hex_num::Wrong_format_exception(
        "Wrong format in converting char to arr");
  }
}
//-------------------------------------------------------------

void Hex_num::move_left(int n) {}
void Hex_num::move_right(int n) {}

bool Hex_num::evenness() {
  if (Container::int_hex_from_char(arr->get(0)) % 2 == 0) {
    return 1;
  } else {
    return 0;
  }
}

void Hex_num::input(std::istream &is) {
  string inp;
  std::getline(is, inp);
  str_to_arr(inp);
}

void Hex_num::output(std::ostream &os) {
  bool started = 0;
  int i = arr->get_len() - 1;
  int a = Container::int_hex_from_char(arr->get(i));
  if (a >= 8) {
    os << '-';
    if (a > 8) {
      os << a - 8;
    }
    --i;
  }
  for (; i >= 0; --i) {
    a = Container::int_hex_from_char(arr->get(i));
    if (a != 0) {
      os << a;
      started = 1;
    } else if (started) {
      os << a;
    }
  }
  os << endl;
}

void Hex_num::print_container(std::ostream &out) {
  for (int i = arr->get_len() - 1; i >= 0; --i) {
    out << arr->get(i);
  }
  out << endl;
}

bool Hex_num::equal(Hex_num const &a, Hex_num const &b) {}
Hex_num *Hex_num::sum(Hex_num const &a, Hex_num const &b) {}
Hex_num *Hex_num::dif(Hex_num const &a, Hex_num const &b) {}

// Hex_num::~Hex_num() {
//   free()
// }
