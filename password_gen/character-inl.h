// Copyright (c) 2015, jeonghun
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
// list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef PASSWORD_GEN_CHARACTER_INL_H_
#define PASSWORD_GEN_CHARACTER_INL_H_

#include "password_gen/character.h"

bool character::init(bool lowercase, bool uppercase, bool number, bool spchar) {
  lowercase_ = lowercase;
  uppercase_ = uppercase;
  number_ = number;
  spchar_ = spchar;

  return update_type();
}

char character::get() {
  char retchar = 0;

  switch (type_) {
  case TYPE_LOWERCASE:
    retchar = get_lowercase();
    break;
  case TYPE_UPPERCASE:
    retchar = get_uppercase();
    break;
  case TYPE_NUMBER:
    retchar = get_number();
    break;
  case TYPE_SPCHAR:
    retchar = get_special_char();
    break;
  }

  if (retchar == 0) {
    reset_index();
    if (update_type()) {
      retchar = get();
    }
  }

  return retchar;
}

bool character::update_type() {
  bool use_type = false;
  while (use_type == false && ++type_ < COUNT_OF_TYPE) {
    switch (type_) {
    case TYPE_LOWERCASE:
      use_type = lowercase_;
      break;

    case TYPE_UPPERCASE:
      use_type = uppercase_;
      break;

    case TYPE_NUMBER:
      use_type = number_;
      break;

    case TYPE_SPCHAR:
      use_type = spchar_;
      break;
    }
  }

  if (use_type == false) {
    type_ = TYPE_UNDEFINED;
  }

  return use_type;
}

void character::reset_index() {
  index_ = 0;
}

char character::get_lowercase() {
  enum { MAX_LOWERCASE_COUNT = 'z' - 'a' + 1 };
  return index_ < MAX_LOWERCASE_COUNT ? ('a' + index_++) : 0;
}

char character::get_uppercase() {
  enum { MAX_UPPERCASE_COUNT = 'Z' - 'A' + 1 };
  return index_ < MAX_UPPERCASE_COUNT ? ('A' + index_++) : 0;
}

char character::get_number() {
  enum { MAX_NUMBER_COUNT = '9' - '0' + 1 };
  return index_ < MAX_NUMBER_COUNT ? ('0' + index_++) : 0;
}

char character::get_special_char() {
  static const char sp_char_tbl[] = "!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?`~";
  enum { MAX_SPCHAR_COUNT = _countof(sp_char_tbl) - 1 };
  return index_ < MAX_SPCHAR_COUNT ? sp_char_tbl[index_++] : 0;
}

#endif  // PASSWORD_GEN_CHARACTER_INL_H_
