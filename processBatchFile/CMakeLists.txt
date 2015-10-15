cmake_minimum_required(VERSION 2.8)

aux_source_directory(./ SRC_LIST)

add_executable(batch ${SRC_LIST})

target_link_libraries(batch)
