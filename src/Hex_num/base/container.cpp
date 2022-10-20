#include "container.h"
#include "hex_num.h"

using namespace hex_num;
using namespace std;
typedef Container C;

//-----------------Container-----------------------------------
int C::get_len() const { return len; }
void C::set_len(size_t len) { this->len = len; }

char C::int_to_char(int hex) {
  hex %= 16;
  if (hex < 10) {
    return '0' + hex;
  } else {
    return 'A' + hex - 10;
  }
}

int C::char_to_int(char hex) {
  if ('0' <= hex && hex <= '9') {
    return hex - '0';
  } else if ('A' <= hex && hex <= 'F') {
    return hex - 'A' + 10;
  } else {
    throw Hex_num::Wrong_format_exception(
        "Wrong format in converting char to int");
  }
}

C::~Container() {}
//-------------------------------------------------------------
