# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Volumes/ExtremeSSD/Bitskin-UI/src/_deps/cpr-src"
  "/Volumes/ExtremeSSD/Bitskin-UI/src/_deps/cpr-build"
  "/Volumes/ExtremeSSD/Bitskin-UI/src/_deps/cpr-subbuild/cpr-populate-prefix"
  "/Volumes/ExtremeSSD/Bitskin-UI/src/_deps/cpr-subbuild/cpr-populate-prefix/tmp"
  "/Volumes/ExtremeSSD/Bitskin-UI/src/_deps/cpr-subbuild/cpr-populate-prefix/src/cpr-populate-stamp"
  "/Volumes/ExtremeSSD/Bitskin-UI/src/_deps/cpr-subbuild/cpr-populate-prefix/src"
  "/Volumes/ExtremeSSD/Bitskin-UI/src/_deps/cpr-subbuild/cpr-populate-prefix/src/cpr-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Volumes/ExtremeSSD/Bitskin-UI/src/_deps/cpr-subbuild/cpr-populate-prefix/src/cpr-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Volumes/ExtremeSSD/Bitskin-UI/src/_deps/cpr-subbuild/cpr-populate-prefix/src/cpr-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
