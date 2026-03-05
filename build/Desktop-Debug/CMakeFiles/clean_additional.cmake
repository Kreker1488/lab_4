# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Logger\\CMakeFiles\\Logger_autogen.dir\\AutogenUsed.txt"
  "Logger\\CMakeFiles\\Logger_autogen.dir\\ParseCache.txt"
  "Logger\\Logger_autogen"
  "main\\CMakeFiles\\main_autogen.dir\\AutogenUsed.txt"
  "main\\CMakeFiles\\main_autogen.dir\\ParseCache.txt"
  "main\\main_autogen"
  )
endif()
