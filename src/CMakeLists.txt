# src
set(TEST_NAME pcg-random-lib-test)
add_executable(${TEST_NAME} pcg-random-lib.cpp)
target_include_directories(${TEST_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../include")
target_link_libraries(${TEST_NAME} PRIVATE pcg-random-lib)

if(MSVC)
  target_compile_options(${TEST_NAME} PRIVATE /W4 /WX)
else()
  target_compile_options(${TEST_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()