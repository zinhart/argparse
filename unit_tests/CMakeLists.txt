set(argparse_unit_tests_src
 run_all.cc
 argparse_test.cc
 )
add_executable(argparse_unit_tests ${argparse_unit_tests_src})

target_link_libraries(argparse_unit_tests 
					gtest
					#gmock_main # for google mock
					${CMAKE_THREAD_LIBS_INIT}
					)
add_test(
NAME argparse_unit_tests
COMMAND argparse_unit_tests
)
endif()

