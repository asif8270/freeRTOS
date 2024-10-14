# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/espressif/v5.1.4/esp-idf/components/bootloader/subproject"
  "D:/freeRTOS/02_freeRTOS_TaskParameters/build/bootloader"
  "D:/freeRTOS/02_freeRTOS_TaskParameters/build/bootloader-prefix"
  "D:/freeRTOS/02_freeRTOS_TaskParameters/build/bootloader-prefix/tmp"
  "D:/freeRTOS/02_freeRTOS_TaskParameters/build/bootloader-prefix/src/bootloader-stamp"
  "D:/freeRTOS/02_freeRTOS_TaskParameters/build/bootloader-prefix/src"
  "D:/freeRTOS/02_freeRTOS_TaskParameters/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/freeRTOS/02_freeRTOS_TaskParameters/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/freeRTOS/02_freeRTOS_TaskParameters/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
