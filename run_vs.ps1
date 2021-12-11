mkdir build
cd build
cmake -G "Visual Studio 16 2019" ..
cmake --build . 
cd ..
.\build\Debug\spi_flash_mock_test.exe