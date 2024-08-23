#include <gtest/gtest.h>
#include <sstream>
#include "hello.h"

class HelloTest : public ::testing::Test {
protected:
    // Redirect standard output to a string stream
    std::stringstream output_stream;
    std::streambuf* old_cout_streambuf;

    void SetUp() override {
        // Save the original buffer and redirect std::cout
        old_cout_streambuf = std::cout.rdbuf();
        std::cout.rdbuf(output_stream.rdbuf());
    }

    void TearDown() override {
        // Restore the original buffer
        std::cout.rdbuf(old_cout_streambuf);
    }
};

TEST_F(HelloTest, SayHelloPrintsCorrectMessage) {
    hello h;
    h.sayHello();
    
    // Check the captured output
    std::string expected_output = "Hello World!\n";
    EXPECT_EQ(output_stream.str(), expected_output);
}