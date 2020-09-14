#include"Fighter.h"

//void foo()
//{
//	Fighter *c1 = new Fighter("Maple",150, 10);
//	Fighter *c2 = new Fighter("Sally",45, 30);
//	c1->duel(c2);
//	delete c1;
//	delete c2;
//}

int main(int argc, char* argv[])
{

	
	Fighter *f1 = new Fighter(argv[1], std::stoi(argv[2]), std::stoi(argv[3]));
	Fighter *f2 = new Fighter(argv[4], std::stoi(argv[5]), std::stoi(argv[6]));
	f1->duel(f2);


	//std::cout << argv[1] << std::endl;
	delete f1;
	delete f2;

	return 0;
}