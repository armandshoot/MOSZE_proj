#include"Fighter.h"



int main(int argc, char* argv[])
{

	try {
		Fighter u1(Fighter::parseUnit(argv[1]));
		Fighter u2(Fighter::parseUnit(argv[2]));
		u1.duel(&u2);
		/**
	 	* Exception handling. An exception thrown when a file related error occurs.
	 	*/

	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
		/**
	 	* Exception handling. Catches and warns about an error occurring.
	 	*/
	}

	return 0;
}
