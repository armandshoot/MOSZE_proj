#include"Fighter.h"

void duel(Fighter attacker, Fighter defender) {

	bool can_attack = true;
	while (attacker.getHP() != 0 && defender.getHP() != 0)
	{
		std::cout << attacker << defender;

		if (can_attack) {
			std::cout << attacker.getName() << "--->" << defender.getName() << std::endl;
			defender.take_dmg(attacker);
			can_attack = false;
		}
		else
		{
			std::cout << defender.getName() << "--->" << attacker.getName() << std::endl;
			attacker.take_dmg(defender);
			can_attack = true;
		}
	}
	std::cout << attacker<< defender;
	if (attacker.getHP() > defender.getHP())
	{
		std::cout << defender.getName() << " died. " << attacker.getName() << " wins.\n";
	}
	else
	{
		std::cout << attacker.getName() << " died. " << defender.getName() << " wins.\n";
	}
}

int main(int argc, char* argv[])
{

	
	Fighter f1 = Fighter(argv[1], std::stoi(argv[2]), std::stoi(argv[3]));
	Fighter f2 = Fighter(argv[4], std::stoi(argv[5]), std::stoi(argv[6]));
	duel(f1, f2);

	//std::cout << f1<< f2<< std::endl;


	return 0;
}

