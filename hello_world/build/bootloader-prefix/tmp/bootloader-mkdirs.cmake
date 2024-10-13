# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/espressif/v5.1.4/esp-idf/components/bootloader/subproject"
  "D:/freeRTOS/hello_world/build/bootloader"
  "D:/freeRTOS/hello_world/build/bootloader-prefix"
  "D:/freeRTOS/hello_world/build/bootloader-prefix/tmp"
  "D:/freeRTOS/hello_world/build/bootloader-prefix/src/bootloader-stamp"
  "D:/freeRTOS/hello_world/build/bootloader-prefix/src"
  "D:/freeRTOS/hello_world/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/freeRTOS/hello_world/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/freeRTOS/hello_world/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()