#include "hex_num.h"

using dyn_hex_num::Hex_num;
using namespace std;

char Hex_num::int_to_char(int hex) {
  hex %= 16;
  if (hex < 10) {
    return '0' + hex;
  } else {
    return 'A' + hex - 10;
  }
}

int Hex_num::char_to_int(char hex) {
  if ('0' <= hex && hex <= '9') {
    return hex - '0';
  } else if ('A' <= hex && hex <= 'F') {
    return hex - 'A' + 10;
  } else {
    throw Hex_num::Wrong_format_exception(
        "Wrong format in converting char to int");
  }
}

int Hex_num::get_len() const { return arr.size(); }

void Hex_num::str_to_arr(string str) {
  size_t len = str.length();
  if (len == 0) {
    // set_zeros();
  }
  len = str[0] == '-' ? len - 1 : len;
  for (size_t i = 0; i < len; ++i) {
    if (string("0123456789ABCDEF").find(str[str.length() - 1 - i]) !=
        str.npos) {
      // arr->set(i, str[str.length() - 1 - i]);
    } else {
      throw Hex_num::Wrong_format_exception(
          "Wrong format in converting str to arr");
    }
  }
  if (str[0] == '-') {
    // set_minus();
  }
}
