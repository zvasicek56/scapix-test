cmake_minimum_required(VERSION 3.14...3.26)

project(demolib)

include(FetchContent)
FetchContent_Declare(
  cmodule
  URL "https://github.com/scapix-com/cmodule/archive/refs/tags/v1.0.42.tar.gz"
  URL_HASH SHA256=0fc5bb6bde3054664713bc9cba48f44a2f8af8fa2b94eb0da1031d5298f9ccf6
)
FetchContent_MakeAvailable(cmodule)


add_library(demolib SHARED "src/lib.h")
target_compile_features(demolib PUBLIC cxx_std_17)

find_package(Scapix REQUIRED)

scapix_bridge_headers(
    demolib
    "com.example.demo"
    "src/lib.h"
)
