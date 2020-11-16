cmake_minimum_required(VERSION 3.0.0)

project(learncpp)
  aux_source_directory(. ROOT_DIR)
  add_subdirectory(src)
  add_executable(a ${ROOT_DIR} )
  target_link_libraries( a learncpp)
