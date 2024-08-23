#include "cute.h"

int lifeTheUniverseAndEverything = 6*7;

void mySimpleTest(){
    ASSERT_EQUAL(42, lifeTheUniverseAndEverything);
}

#include "cute_runner.h"
#include "ide_listener.h"
#include <iostream>

void main1(){
	cute::ide_listener<> listener{};
    if (cute::makeRunner(listener)(mySimpleTest)){
        std::cout << "success\n";
    } else {
        std::cout << "failure\n";
    }   
}

void main2(){
    cute::ide_listener<> listener{};
    cute::makeRunner(listener)(mySimpleTest);
}

#include "cute_test.h"
#include "cute_equals.h"

int anotherTest(){
	ASSERT_EQUAL(42, lifeTheUniverseAndEverything);
	return 0;
}

cute::test tests[]={
	CUTE(mySimpleTest)
	,mySimpleTest
	,CUTE(anotherTest)
};

struct ATestFunctor {
	void operator()(){
		ASSERT_EQUAL_DELTA(42.0, static_cast<double>(lifeTheUniverseAndEverything), 0.001);
	}
};

#include "cute_suite.h"

int main3(){
	cute::ide_listener<> listener{};
    auto run = cute::makeRunner(listener);
    cute::suite s(tests, tests + (sizeof(tests) / sizeof(tests[0])));
	s += ATestFunctor();
	return run(s, "suite");
}

int main(){
	main1();
	main2();
	main3();
}