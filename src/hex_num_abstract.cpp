#include "hex_num_abstract.h"
#include "string"
#include <functional>
#include <math.h>
#include <stdexcept>
#include <string>

using namespace hex_num;
using namespace std;

//-----------------Container-----------------------------------
size_t Container::get_len() const { return len; }
void Container::set_len(size_t len) { this->len = len; }

char Container::int_hex_to_char(int hex) {
  hex %= 16;
  if (hex < 10) {
    return '0' + hex;
  } else {
    return 'A' + hex - 10;
  }
}

int Container::char_hex_to_int(char hex) {
  // cout << "Befor throw: " << (char)hex << endl;
  if ('0' <= hex && hex <= '9') {
    return hex - '0';
  } else if ('A' <= hex && hex <= 'F') {
    return hex - 'A' + 10;
  } else {
    throw Hex_num::Wrong_format_exception(
        "Wrong format in converting char to int");
  }
}

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
    arr->set(i++, Container::int_hex_to_char(hex));
    hex /= 16;
  }
}

Hex_num::Hex_num(Container *arr, std::string hex) : arr(arr) {
  str_to_arr(hex);
}

Hex_num::Wrong_format_exception::Wrong_format_exception(std::string msg)
    : std::runtime_error(msg){};

Hex_num::Hex_num(const Hex_num &that) {
  arr = that.arr->get_copy();
}
Hex_num::~Hex_num() {
  free(arr);
  arr = nullptr;
  std::cout << "Abstact container destructor" << std::endl;
}
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

void Hex_num::unset_minus(){};
//-------------------------------------------------------------
void Hex_num::move_left(int n) {}
void Hex_num::move_right(int n) {}

bool Hex_num::evenness() {
  if (Container::char_hex_to_int(arr->get(0)) % 2 == 0) {
    return 1;
  } else {
    return 0;
  }
}

void Hex_num::input(std::istream &is) {
  string inp;
  std::getline(is, inp);
  arr->set_zeros();
  str_to_arr(inp);
}

void Hex_num::output(std::ostream &os) {
  bool started = 0;
  int i = arr->get_len() - 1;
  int a = Container::char_hex_to_int(arr->get(i));
  if (a >= 8) {
    os << '-';
    if (a > 8) {
      os << Container::int_hex_to_char(a - 8);
    }
    --i;
  }
  for (; i >= 0; --i) {
    a = Container::char_hex_to_int(arr->get(i));
    if (a != 0) {
      os << Container::int_hex_to_char(a);
      started = 1;
    } else if (started) {
      os << Container::int_hex_to_char(a);
    }
  }
  if (started == 0) {
    os << '0';
  }
  os << endl;
}

void Hex_num::print_container(std::ostream &out) {
  for (int i = arr->get_len() - 1; i >= 0; --i) {
    out << arr->get(i);
  }
  out << endl;
}

Hex_num *Hex_num::to_reverse_code() {
  int val = arr->char_hex_to_int(arr->get(arr->get_len() - 1));
  if (val >= 8) {
    val -= 8;
    for (int i = 0; i < 3; ++i) {
      int bit = static_cast<int>(pow(2, i));
      // cout << "  bit = " << bit << endl;
      // cout << "  last bit = " << (arr->get(i) / bit) % 2 << endl;
      if ((val / bit) % 2 == 0) {
        val += bit;
      } else {
        val -= bit;
      }
    }
    // cout << "val s = " << val << endl;
    arr->set(arr->get_len() - 1, arr->int_hex_to_char(val));

    for (int j = arr->get_len() - 2; j >= 0; --j) {
      int val = arr->char_hex_to_int(arr->get(j));
      for (int i = 0; i < 4; ++i) {
        int bit = static_cast<int>(pow(2, i));
        if ((arr->char_hex_to_int(arr->get(j)) / bit) % 2 == 0) {
          val += bit;
        } else {
          val -= bit;
        }
      }
      arr->set(j, arr->int_hex_to_char(val));
    }
  }
  return this;
}

Hex_num *Hex_num::to_additional_code() {
  int val = arr->char_hex_to_int(arr->get(arr->get_len() - 1));
  if (val >= 8) {
    for (int i = 0; i < arr->get_len() - 2; ++i) {
      val = arr->char_hex_to_int(arr->get(i));
      val += 1;
      if (val == 16) {
        arr->set(i, arr->int_hex_to_char(0));
      } else {
        arr->set(i, arr->int_hex_to_char(val));
        break;
      }
    }
  }
  return this;
}

Hex_num *Hex_num::from_add_to_rev_code() {
  if (Container::char_hex_to_int(arr->get(arr->get_len() - 1)) >= 8) {
    int i = 0;
    int val = Container::char_hex_to_int(arr->get(i));
    while (val == 0 && i < arr->get_len()) {
      ++i;
      val = Container::char_hex_to_int(arr->get(i));
    }
    if (i == arr->get_len() - 1 && val == 8) {
      throw std::overflow_error(
          "Such additional code can't be represented as a reversed code");
    } else {
      for (int j = 0; j < 4; ++j) {
        int bit = static_cast<int>(pow(2, j));
        if ((arr->char_hex_to_int(arr->get(i)) / bit) % 2 == 1) {
          val -= bit;
          for (--j; j >= 0; --j) {
            bit = static_cast<int>(pow(2, i));
            val += bit;
          }
          break;
        }
      }
      arr->set(i, Container::int_hex_to_char(val));
      --i;
    }
    for (; i >= 0; --i) {
      arr->set(i, 'F');
    }
  }
  return this;
}

bool Hex_num::equal(Hex_num const &a, Hex_num const &b) {}

Hex_num Hex_num::sum_of_additonals(const Hex_num &a, const Hex_num &b) {
  Hex_num ans(a.arr->get_new());
  int i = 0;
  int from_prev = 0;
  while (i < a.arr->get_len() && i < b.arr->get_len()) {
    int s1 = Container::char_hex_to_int(a.arr->get(i));
    int s2 = Container::char_hex_to_int(b.arr->get(i));
    int res = s1 + s2 + from_prev;
    from_prev = 0;
    if (res >= 16) {
      from_prev = 1;
      ans.arr->force_set(i, Container::int_hex_to_char(res % 16));
      ++i;
    } else {
      ans.arr->force_set(i, Container::int_hex_to_char(res));
      ++i;
    }
  }
  if (from_prev != 0) {
    if (Container::char_hex_to_int(a.arr->get(a.arr->get_len() - 1)) >= 8 &&
        Container::char_hex_to_int(b.arr->get(b.arr->get_len() - 1)) >= 8) {

    } else {
      ans.arr->force_set(i++, '1');
    }
  }
  return ans;
}

Hex_num Hex_num::sum(const Hex_num &a, const Hex_num &b) {
  Hex_num a_add(a);
  a_add.to_reverse_code()->to_additional_code();
  Hex_num b_add(b);
  b_add.to_reverse_code()->to_additional_code();

  a_add.print_container(cout << "a in additional: ");
  b_add.print_container(cout << "b in additional: ");
  //
  // cout << "HERE" << endl;
  Hex_num ans = sum_of_additonals(a_add, b_add);
  ans.from_add_to_rev_code()->to_reverse_code();
  return ans;
}
Hex_num *Hex_num::dif(Hex_num const &a, Hex_num const &b) {}

// Hex_num::~Hex_num() {
//   free()
// }
