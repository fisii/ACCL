include_directories(${MPI_CXX_INCLUDE_PATH})
link_libraries(${MPI_CXX_LIBRARIES} uuid)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${MPI_CXX_LINK_FLAGS})
add_executable(dacusr main.cpp)
