#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <random>
#include <assert.h>
#include <stdlib.h>

//#define int int64_t
#define int int32_t
#include "lieonn.hh"
typedef myfloat num_t;

using std::cout;
using std::cerr;
using std::endl;
using std::atoi;
using std::string;
using std::to_string;
using std::vector;
using std::sort;
using std::binary_search;
using std::make_pair;
using std::istringstream;

#undef int
int main(int argc, const char* argv[]) {
  SimpleVector<num_t> op;
  std::cin >> op;
  assert(1 < op.size());
  for(myuint i((myuint(1) << (op.size() - 1)) | myuint(1));
    i < (myuint(1) << op.size()); i ++) {
    num_t lop(int(0));
    for(int j = 0; j < op.size(); j ++)
      if(i & (j ? myuint(1) << j : myuint(1)))
        lop += op[j];
    lop = lop - floor(lop);
    if(int(myuint(lop)) & 1) {
      std::cout << "NG @ 0x" << i << std::endl;
      return 0;
    }
  }
  std::cout << "OK : this is nonzero 0 vector." << std::endl;
  return 0;
}

