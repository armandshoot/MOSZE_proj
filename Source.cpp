#include"Fighter.h"

void duel(Fighter attacker, Fighter defender) {

	bool can_attack = true;


	while (attacker.getHP() != 0 && defender.getHP() != 0)
	{
		if (can_attack) {

			attacker.deal_dmg(defender); 
			can_attack = false;

			
		}
		else
		{

			attacker.take_dmg(defender);

			can_attack = true;
		}
	}
	if (attacker.getHP() > defender.getHP())
	{
		std::cout << attacker.getName() << " wins. " << "Remaining HP: " << attacker.getHP() << std::endl;
	}
	else
	{
		std::cout << defender.getName() << " wins. " << "Remaining HP: " << defender.getHP() << std::endl;
	}

}


int main(int argc, char* argv[])
{

	try {
		Fighter u1(Fighter::parseUnit(argv[1]));
		Fighter u2(Fighter::parseUnit(argv[2]));
		duel(u1, u2);

	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}


	return 0;
}
