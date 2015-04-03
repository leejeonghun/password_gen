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

#ifndef PASSWORD_GEN_PASSWORD_GEN_CHARACTER_H_
#define PASSWORD_GEN_PASSWORD_GEN_CHARACTER_H_

#include <cstdint>

class character final {
 public:
  character() = default;
  ~character() = default;

  inline bool init(bool lowercase, bool uppercase, bool number, bool spchar);
  inline char get();

 private:
  enum TYPE {
    TYPE_LOWERCASE = 0,
    TYPE_UPPERCASE,
    TYPE_NUMBER,
    TYPE_SPCHAR,
    COUNT_OF_TYPE,
    TYPE_UNDEFINED = -1
  };

  inline bool update_type();
  inline void reset_index();
  inline char get_lowercase();
  inline char get_uppercase();
  inline char get_number();
  inline char get_special_char();

  int32_t type_ = TYPE_UNDEFINED;
  int32_t index_ = 0;
  bool lowercase_ = false;
  bool uppercase_ = false;
  bool number_ = false;
  bool spchar_ = false;
};

#include "password_gen/character-inl.h"

#endif  // PASSWORD_GEN_PASSWORD_GEN_CHARACTER_H_
