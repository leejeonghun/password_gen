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

#include "password_gen/password.h"

password::password(int32_t min_len, int32_t max_len, uint32_t type_flag)
    : min_len_(min_len), max_len_(max_len) {
  buffer_.resize(max_len_ + 1);
  chars_.resize(max_len_);
  for (auto& one_char : chars_) {
    one_char.init(chk_flag(type_flag, USE_LOWERCASE),
      chk_flag(type_flag, USE_UPPERCASE),
      chk_flag(type_flag, USE_NUMBER),
      chk_flag(type_flag, USE_SPCHAR));
  }
  for (int32_t i = 1; i < min_len_; i++) {
    buffer_[i] = chars_[i].get();
  }
}

bool password::chk_flag(uint32_t value, uint32_t flag) const {
  return value & flag ? true : false;
}

const char* password::get() {
  bool end = false;
  for (uint32_t i = 0; i < chars_.size(); i++) {
    char value = chars_[i].get();
    if (value == 0) {
      if (i < chars_.size() - 1) {
        buffer_[i] = chars_[i].get();
      } else {
        end = true;
        break;
      }
    } else {
      buffer_[i] = value;
      break;
    }
  }

  return end ? nullptr : buffer_.data();
}
