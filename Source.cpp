#include"Fighter.h"



int main(int argc, char* argv[])
{

	
	Fighter *f1 = new Fighter(argv[1], std::stoi(argv[2]), std::stoi(argv[3]));
	Fighter *f2 = new Fighter(argv[4], std::stoi(argv[5]), std::stoi(argv[6]));
	f1->duel(f2);


	delete f1;
	delete f2;

	return 0;
}