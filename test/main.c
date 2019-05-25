#define CTEST_MAIN
#define CTEST_COLOR_OK
#include <ctest.h>
#include <game.h>
#include <menu.h>
int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}
CTEST(correct_test1, result_test)
{
    ch = 0;
    CreateField();
    const int result = res;
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}
