cmake_minimum_required(VERSION 3.1)

m_source_group_recurse(sources)

add_executable(glogDemo ${sources})

target_link_libraries(glogDemo glog::glog)