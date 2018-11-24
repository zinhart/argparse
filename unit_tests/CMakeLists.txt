set(token_parser_unit_tests_src
 run_all.cc
 token_parser_test.cc
 )
add_executable(token_parser_unit_tests ${token_parser_unit_tests_src})

target_link_libraries(token_parser_unit_tests 
					  token_parser
					  gtest
					  #gmock_main # for google mock
					  ${CMAKE_THREAD_LIBS_INIT}
					 )
add_test(
NAME token_parser_unit_tests
COMMAND token_parser_unit_tests
)
