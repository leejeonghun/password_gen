// Copyright (c) 2015 jeonghun
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

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
