#include <istream>
#include <vector>
#if !defined(HEX_NUM_H)
#define HEX_NUM_H

namespace dyn_hex_num {
using namespace std;

class Hex_num {
  vector<char> arr;

  //-- Container methods--
protected:
  int get_len() const;
  // int get_sign() const;
  // void set_len(size_t len);
  // void set_zeros();
  // void set_minus();
  // void set_plus();

  // char get_char(size_t pos, char def = '0') const;
  // int get_int(size_t pos, int def = 0) const;
  // char get_cell_char(size_t pos, char def = '0') const;
  // int get_cell_int(size_t pos, int def = 0) const;

  /**
   * @brief Set val but not sign
     @details Set val if it is possible not to touch sign bit else 
              throw an exception.
   * @param pos
   * @param val
   */
  // void set_char(char inp);
  // void set_int(int inp);
  // void set_cell_char(char inp);
  // void set_cell_int(int inp);

  static char int_to_char(int hex);
  static int char_to_int(char hex);

  //-- Hex_num methods--
public:
  // Hex_num();
  // Hex_num(int hex);
  // Hex_num(string hex);
  // Hex_num(const Hex_num &that);
  // Hex_num &operator=(const Hex_num &a);
  //
  // istream &input(istream &inp);
  // ostream &output(ostream &out) const;
  // void print_container(std::ostream &out);
  //
  // bool evenness();
  // Hex_num move_left(unsigned n);
  // Hex_num move_right(unsigned n);

  class Wrong_format_exception : public std::runtime_error {
  public:
    Wrong_format_exception(std::string msg);
  };

protected:
  void str_to_arr(string str);
  // void int_to_arr(int inp);
  //
  // Hex_num *to_additional_code();
  // Hex_num *reverse_code();
  // Hex_num *from_add_to_rev_code();
  // static Hex_num sum_of_additonals(const Hex_num &a, const Hex_num &b);
  // static bool equal(const Hex_num &a, const Hex_num &b);
  // static Hex_num sum(const Hex_num &a, const Hex_num &b);
  // static Hex_num dif(Hex_num const &a, Hex_num const &b);
};

} // namespace dyn_hex_num

#endif
