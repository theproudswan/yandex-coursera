#include "test_runner.h"

#include <iostream>
#include <sstream>

#define PRINT_VALUES(out, x, y) (out) << (x) << endl << (y) << endl
int main()
{
    TestRunner tr;
    tr.RunTest([] 
    {
        std::ostringstream output;
        PRINT_VALUES(output, 5, "red belt");
        ASSERT_EQUAL(output.str(), "5\nred belt\n");
    }, "PRINT_VALUES usage example");

    return 0;
}