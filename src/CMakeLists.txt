include_directories(${CMAKE_SOURCE_DIR}/include)

set(RL_EXAMPLE_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/env/cartpole.cc
                            ${CMAKE_CURRENT_SOURCE_DIR}/env/mountain_car.cc)

set(RL_EXAMPLE_SHARED_LIB_DEPS "")
add_library(${RL_EXAMPLE_SHARED_LIB} SHARED ${RL_EXAMPLE_SOURCE_FILES})
target_link_libraries(${RL_EXAMPLE_SHARED_LIB}
                      PRIVATE ${RL_EXAMPLE_SHARED_LIB_DEPS})

set(RL_EXAMPLE_STATIC_LIB_DEPS "")
add_library(${RL_EXAMPLE_STATIC_LIB} STATIC ${RL_EXAMPLE_SOURCE_FILES})
target_link_libraries(${RL_EXAMPLE_STATIC_LIB}
                      PRIVATE ${RL_EXAMPLE_STATIC_LIB_DEPS})
