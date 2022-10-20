// #if !defined(CONTAINER_H)
// #define CONTAINER_H
//
// #include <iostream>
// #include <stdexcept>
// #include <string>
//
// namespace hex_num {
//
// /**
//  * @class Container
//  * @brief Abstract class for container
//  */
// class Container {
//   int len = 0; // current len of container
//
// public:
//   /**
//    * @brief Get len of the Container
//    * @return Length
//    */
//   int get_len() const;
//   /**
//    * @brief Set len of the container
//    * @param len New length of the container
//    */
//   void set_len(size_t len);
//   /**
//    * @brief Set to all container cells '0' value
//    */
//   virtual void set_zeros() = 0;
//   /**
//    * @brief Make num negative
//    */
//   virtual void set_minus() = 0;
//   /**
//    * @brief Make num positive
//    */
//   virtual void unset_minus() = 0;
//   /**
//    * @brief Return sign
//    * @return Return 0 if sing is + or 0 and return 1 if sign is -
//    */
//   virtual bool get_sign() const = 0;
//   /**
//    * @brief Get char on pos in container
//      @details Return char on pos in container. If cell with such pos does not
//               exist return def
//    * @param pos
//      @param def
//    * @return Char on pos in container
//    */
//   virtual char get(int pos, char def = '0') const = 0;
//   /**
//    * @brief Return val on pos but without sign
//    * @details Return cell's val without sign. If container has no cell on given
//               pos return def
//    * @param pos
//      @param def - default value that will be returned if container has no cell
//                   on given pos
//    * @return
//    */
//   virtual char weak_get(int pos, char def) const = 0;
//   /**
//    * @brief Set val but not sign
//      @details Set val if it is possible not to touch sign bit else 
//               throw an exception.
//    * @param pos
//    * @param val
//    */
//   virtual void set(int pos, char val) = 0;
//   /**
//    * @brief Set val to pos even if it touchs number sign
//      @details Set val to pos even if it touchs number sign, does nothing if
//               container has not cell with such pos
//    * @param pos
//    * @param val
//    */
//   virtual void force_set(int pos, char val) = 0;
//   /**
//    * @brief Return new Container
//    * @return new Container
//    */
//   virtual Container *get_new() const = 0;
//   /**
//    * @brief Return copy of a Container
//    * @return copy of a Container
//    */
//   virtual Container *get_copy() const = 0;
//   /**
//    * @brief Return hex as a char
//    * @details Return (hex % 16) and cast ro right char symbol
//    * @param hex Should be >= 0
//    * @return Hex as a char
//    */
//   static char int_to_char(int hex);
//   /**
//    * @brief Return hex char as int
//    * @param hex Should be in 0..9A..F or throws an exception
//    * @throw Wrong_format_exception
//    * @return int hex
//    */
//   static int char_to_int(char hex);
//   /**
//    * @brief Just destructor. Does nothing
//    */
//   virtual ~Container();
// };
// } // namespace hex_num
// #endif
