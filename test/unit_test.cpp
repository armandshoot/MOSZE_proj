#include <gtest/gtest.h>
#include <string>
#include <map>
#include <fstream>
#include <utility>
#include "../Jsonparser.h"

TEST(JsonparserTest, Test_parseJson_ifstream)
{
	std::string inputFilename = "units/Maple.json";
	std::map<std::string, std::string> exp_output;
	exp_output.insert(std::pair<std::string, std::string>("name", "Maple"));
	exp_output.insert(std::pair<std::string, std::string>("hp", "150"));
	exp_output.insert(std::pair<std::string, std::string>("dmg", "10"));

    std::ifstream inputFile(inputFilename);

	std::map<std::string, std::string> test_output = Jsonparser::parseJson(inputFile);

    inputFile.close();

	ASSERT_EQ(exp_output, test_output);
}

TEST(JsonparserTest, Test_parseJson_fname)
{
	std::string inputFilename = "test/bad_unit.json";
	//std::string inputFilename = "units/Maple.json";
	ASSERT_THROW(Jsonparser::parseJson(inputFilename), std::runtime_error);
}

TEST(JsonparserTest, Test_getmap)
{
	std::string str = "{This is a bad Json}";

	ASSERT_THROW(Jsonparser::getmap(str), std::runtime_error);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
