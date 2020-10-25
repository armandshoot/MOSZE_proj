#include <gtest/gtest.h>
#include <string>
#include <map>
#include <fstream>
#include <utility>
#include "../Jsonparser.h"

TEST(ParserTest, TestingWithFileInput)
{
	std::string inputFilename = "units/Maple.json";
	std::map<std::string, std::string> expected;
	expected.insert(std::pair<std::string, std::string>("name", "Maple"));
	expected.insert(std::pair<std::string, std::string>("hp", "150"));
	expected.insert(std::pair<std::string, std::string>("dmg", "10"));


    std::ifstream inputFile(inputFilename);

	std::map<std::string, std::string> testingFunction = Jsonparser::parseJson(inputFile);

    inputFile.close();

	ASSERT_EQ(expected, testingFunction);
}

TEST(ParserTest, TestingWithFilenameInput)
{
	//std::string inputFilename = "test/bad_unit.json";
	std::string inputFilename = "units/Maple.json";
	ASSERT_THROW(Jsonparser::parseJson(inputFilename), std::runtime_error);
}

TEST(ParserTest, TestingWithStringInput)
{
	std::string inputString = "{\n\t\"name\"  :  \"Maple\",\n\t\"hp\":150,\n\t\"dmg\"   :    10,}";

	ASSERT_THROW(Jsonparser::parseJson(inputString), std::runtime_error);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
