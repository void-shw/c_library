// gcc -Wl,--export-dynamic main.c -o prog.exe -ldl
//
#include <stdio.h>
#include <dlfcn.h>
#include "foo.h"

typedef void (*lib_func)();

int call_dy_library() {
  void *handle = NULL;
  lib_func func = NULL;
  handle = dlopen("libfoo.so.1.0", RTLD_NOW | RTLD_GLOBAL);
  if (handle == NULL) {
    fprintf(stderr, "Unable to open lib: %s\n", dlerror());
    return -1;
  }
  func = dlsym(handle, "library_function");

  if (func == NULL) {
    fprintf(stderr, "Unable to get symbol\n");
    return -1;
  }

  func("Hello from dynamic function call \n");
  return 0;
}
void call_static_library() {
  library_function("Hello from static function call \n");
};

int main(int argc, const char *argv[]) {
  printf("Hello from main!\n");
  call_dy_library();
  call_static_library();
  return 0;
}
