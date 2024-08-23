#include "cute.h"
#include "cute_equals.h"
#include"cute_runner.h"
#include "ostream_listener.h"
#include "xml_listener.h"
#include "ide_listener.h"
#include "stdlib.h"
#include <sstream>
#include <unordered_map>

int lifeTheUniverseAndEverything = 6*7;

TEST(myTest){
    ASSERT_EQUAL(42, lifeTheUniverseAndEverything);
}

bool runSuite(cute::runner<cute::xml_listener<cute::ide_listener<>>> runner)
{
    cute::suite s{};
    s += myTest();
    return runner(s, "TestSuite");
}



int main(int argc, char const * argv[]){
	cute::xml_file_opener cmlfile(argc, argv);
    cute::xml_listener<cute::ide_listener<>> listener(os: xmlfile.out);
    auto runner = cute::makeRunner(s: listener, argc, argv);

    bool suiteResult = runSuite(runner);
    return suiteResult ? EXIT_SUCCESS : EXIT_FAILURE;
}