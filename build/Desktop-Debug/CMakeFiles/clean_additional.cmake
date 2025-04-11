# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/fbla25-finance_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/fbla25-finance_autogen.dir/ParseCache.txt"
  "fbla25-finance_autogen"
  )
endif()
