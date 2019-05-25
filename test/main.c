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
    int rg = 50;
    const int result = LvlGame(rg);
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}
CTEST(correct_test2, result_test)
{
    int rg = 49;
    const int result = LvlGame(rg);
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(create_4x4, result_test)
{
    int rg = 49;
    LvlGame(rg);
    const int result = CreateField();
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(create_5x5, result_test)
{
    int rg = 50;
    LvlGame(rg);
    const int result = CreateField();
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}

