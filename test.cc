#include "rockre.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

using namespace RockRE;

int main(int argc, char** argv)
{
  if (argc==1) {
    abort();
  }

  bool run_mode = false;

  int n = 1;
  if (argv[n][0] == '-') {
    if (argv[n][1] == 'r') {
      run_mode = true;
      n++;
    }
  }

  const char*regexp = argv[n];
  RockRE::Node node = RockRE::parse(std::string(regexp));
  assert(node.type() != NODE_UNDEF);
  if (run_mode) {
    RockRE::Irep irep;
    RockRE::codegen(node, irep);
    bool ret = RockRE::match(std::string(argv[n+1]), irep);
    if (ret) {
      printf("OK\n");
    } else {
      printf("FAIL\n");
    }
  } else {
    node.dump();
  }
  return EXIT_SUCCESS;
}
