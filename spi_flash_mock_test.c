#include "spi_flash.h"
#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#define UNIT_TESTING 1
#include <cmocka.h>


static void test_erased(void **state)
{
    sFLASH_EraseBulk();
    uint8_t outputArray[3] = {0, 0, 0};
    uint8_t expectedArray[3] = {0xff, 0xff, 0xff};
    sFLASH_ReadBuffer(outputArray, 0, 3);
    assert_memory_equal(outputArray, expectedArray, 3);
}

static void test_write(void **state)
{
  uint8_t testWriteArray[3] = {'1', '2', '3'};
  uint8_t outputArray[3] = {0, 0, 0};
  sFLASH_WriteEnable();
  sFLASH_WritePage(testWriteArray, 0, 3);
  sFLASH_ReadBuffer(outputArray, 0, 3);
  assert_memory_equal(testWriteArray, outputArray, 3);
}

static void test_read(void **state)
{
}

int main()
{
    const struct CMUnitTest flash_api_tests[] =
    {
        cmocka_unit_test(test_erased),
        cmocka_unit_test(test_write),
        cmocka_unit_test(test_read)
    };

    return cmocka_run_group_tests(flash_api_tests, NULL, NULL);
}