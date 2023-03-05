# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QuanLySinhVien_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QuanLySinhVien_autogen.dir\\ParseCache.txt"
  "QuanLySinhVien_autogen"
  )
endif()
