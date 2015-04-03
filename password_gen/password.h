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

#ifndef PASSWORD_GEN_PASSWORD_GEN_PASSWORD_H_
#define PASSWORD_GEN_PASSWORD_GEN_PASSWORD_H_

#include <cstdint>
#include <vector>
#include "password_gen/character.h"

class password final {
 public:
  enum {
    USE_LOWERCASE = 1,
    USE_UPPERCASE = 1 << 1,
    USE_NUMBER = 1 << 2,
    USE_SPCHAR = 1 << 3,
  };

  password(int32_t min_len, int32_t max_len, uint32_t type_flag);
  ~password() = default;

  const char* get();

 private:
  inline bool chk_flag(uint32_t value, uint32_t flag) const;

  const int32_t min_len_;
  const int32_t max_len_;
  std::vector<char> buffer_;
  std::vector<character> chars_;
};

#endif  // PASSWORD_GEN_PASSWORD_GEN_PASSWORD_H_
