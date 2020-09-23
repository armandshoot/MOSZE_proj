#include"Fighter.h"
#include<exception>
void duel(Fighter attacker, Fighter defender) {

	bool can_attack = true;
	/*próba exception*/
	if (attacker.getHP() == -1)
		return;
	while (attacker.getHP() != 0 && defender.getHP() != 0)
	{
		std::cout << attacker << defender;

		if (can_attack) {
			std::cout << attacker.getName() << "--->" << defender.getName() << std::endl;
			attacker.deal_dmg(defender);
			can_attack = false;
		}
		else
		{
			std::cout << defender.getName() << "--->" << attacker.getName() << std::endl;
			attacker.take_dmg(defender);
			can_attack = true;
		}
	}
	std::cout << attacker << defender;
	if (attacker.getHP() > defender.getHP())
	{
		std::cout << defender.getName() << " died. " << attacker.getName() << " wins.\n";
	}
	else
	{
		std::cout << attacker.getName() << " died. " << defender.getName() << " wins.\n";
	}
}

/*beovlasok soronként, ha a sorban az első elem nem '{' vagy '}' akkor azt feldolgozom
feltételezhetem hogy jó az input és sorrend is rendben van
csinlok egy substringet a : után lévő karakterekből, abból levágom a "ket vagy a ,ket. 
str-be szeletelek a lineból stringeket find és posal.

?esetleg legyen dupla slice, először a : utána, majd a kapottat a kettő " " között és aszerint rakom el

*/



int main(/*int argc, char* argv[]*/)
{
	/**/


	
	//Fighter f1 = Fighter(argv[1], std::stoi(argv[2]), std::stoi(argv[3]));
	//Fighter f2 = Fighter(argv[4], std::stoi(argv[5]), std::stoi(argv[6]));
	//duel(f1, f2);

	Fighter u1(Fighter::parseUnit("Kakarot.json"));
	Fighter u2(Fighter::parseUnit("Vegita.json"));
	duel(u1, u2);

	

	return 0;
}

