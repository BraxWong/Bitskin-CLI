# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Volumes/ExtremeSSD/Bitskin-UI/src/_deps/zlib-src"
  "/Volumes/ExtremeSSD/Bitskin-UI/src/_deps/zlib-build"
  "/Volumes/ExtremeSSD/Bitskin-UI/src/_deps/zlib-subbuild/zlib-populate-prefix"
  "/Volumes/ExtremeSSD/Bitskin-UI/src/_deps/zlib-subbuild/zlib-populate-prefix/tmp"
  "/Volumes/ExtremeSSD/Bitskin-UI/src/_deps/zlib-subbuild/zlib-populate-prefix/src/zlib-populate-stamp"
  "/Volumes/ExtremeSSD/Bitskin-UI/src/_deps/zlib-subbuild/zlib-populate-prefix/src"
  "/Volumes/ExtremeSSD/Bitskin-UI/src/_deps/zlib-subbuild/zlib-populate-prefix/src/zlib-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Volumes/ExtremeSSD/Bitskin-UI/src/_deps/zlib-subbuild/zlib-populate-prefix/src/zlib-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Volumes/ExtremeSSD/Bitskin-UI/src/_deps/zlib-subbuild/zlib-populate-prefix/src/zlib-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
