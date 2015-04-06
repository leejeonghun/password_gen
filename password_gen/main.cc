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

#include <iostream>
#include "password_gen/password.h"

int wmain(int argc, wchar_t* argv[]) {
  if (argc > 1) {
    uint32_t min = 1;
    uint32_t max = 1;
    uint32_t type_flag = 0;
    for (int32_t i = 1; i < argc; i++) {
      if (_wcsicmp(argv[i], L"/L") == 0) {
        type_flag |= password::USE_LOWERCASE;
      } else if (_wcsicmp(argv[i], L"/U") == 0) {
        type_flag |= password::USE_UPPERCASE;
      } else if (_wcsicmp(argv[i], L"/N") == 0) {
        type_flag |= password::USE_NUMBER;
      } else if (_wcsicmp(argv[i], L"/S") == 0) {
        type_flag |= password::USE_SPCHAR;
      } else if (wcsstr(argv[i], L"/min:")) {
        swscanf_s(argv[i], L"/min:%u", &min, sizeof(min));
      } else if (wcsstr(argv[i], L"/max:")) {
        swscanf_s(argv[i], L"/max:%u", &max, sizeof(max));
      }
    }

    password pwd(min, max, type_flag);
    while (const char* passwd = pwd.get()) {
      std::cout << passwd << std::endl;
    }
  } else {
    std::cout << "Usage : password_gen.exe /min:8 /max:12 /L /U /N /S"
      << std::endl << std::endl <<
      "/L : use lowercase" << std::endl <<
      "/U : use uppercase" << std::endl <<
      "/N : use numeric" << std::endl <<
      "/S : use special character" << std::endl << std::endl;
  }

  return 0;
}
