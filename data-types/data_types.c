/*
Author: chankruze (chankruze@gmail.com)
Created: Thu Oct 13 2022 18:33:02 GMT+0530 (India Standard Time)

Copyright (c) geekofia 2022 and beyond
*/

#include <stdio.h>

// declaration made available
#include "ext.h"

// extern variable definition checked against declaration
int ext_i;

void static_func() {
  // static data class
  // default value: 0
  // location: memory
  // scope: block
  static int i;
  i++;
  printf("%d\n", i);
}

void ext_func() {
  // external data class
  // default value: 0
  // location: memory
  // scope: global (across multiple file)
  ext_i++;
  printf("%d\n", ext_i);
}

int main(int argc, char const *argv[]) {
  // char x = 291;  // reduced to 291 % 2^8 = 291 % 256 = 35,
  // printf("%c", x);

  static_func();  // 1
  static_func();  // 2
  static_func();  // 3

  ext_func();  // 1
  ext_func();  // 2
  ext_func();  // 3

  return 0;
}
