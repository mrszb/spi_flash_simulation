cmake_minimum_required(VERSION 3.14)

project(spi_flash_mock VERSION 1.0 LANGUAGES C)

include(cmake/FetchCMocka.cmake)

add_executable(spi_flash_mock_test spi_flash_mock_test.c spi_flash_mock.c)
target_compile_features(spi_flash_mock_test PRIVATE c_std_99)
target_link_libraries(spi_flash_mock_test PRIVATE cmocka-static)

#enable_testing()
#add_test(NAME test COMMAND spi_flash_mock_test)