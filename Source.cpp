#include"Fighter.h"

<<<<<<< HEAD
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
=======
>>>>>>> Master_copy


int main(int argc, char* argv[])
{

	try {
		Fighter u1(Fighter::parseUnit(argv[1]));
		Fighter u2(Fighter::parseUnit(argv[2]));
<<<<<<< HEAD
		duel(u1, u2);
=======

		Fighter *outcome=&u1.duel(&u2);
		std::cout << outcome->getName() << " wins. " << "Remaining HP: " << outcome->getHP() << std::endl;
>>>>>>> Master_copy

	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}

	return 0;
}
