#include"Fighter.h"

void duel(Fighter attacker, Fighter defender) {

	bool can_attack = true;

	while (attacker.getHP() != 0 && defender.getHP() != 0)
	{
		if (can_attack) {
			/*std::cout << attacker.getName() << "--->" << defender.getName() << std::endl;*/
			attacker.deal_dmg(defender);
			can_attack = false;
		}
		else
		{
			/*std::cout << defender.getName() << "--->" << attacker.getName() << std::endl;*/
			attacker.take_dmg(defender);
			can_attack = true;
		}
	}
	if (attacker.getHP() > defender.getHP())
	{
		std::cout << attacker.getName() << " Wins. " <<"Remaining HP: "<< attacker.getHP() << ".\n";
	}
	else
	{
		std::cout << defender.getName() << " Wins. " << "Remaining HP: " << defender.getHP() << ".\n";
	}
}

/*beovlasok soronként, ha a sorban az első elem nem '{' vagy '}' akkor azt feldolgozom
feltételezhetem hogy jó az input és sorrend is rendben van
csinlok egy substringet a : után lévő karakterekből, abból levágom a "ket vagy a ,ket. 
str-be szeletelek a lineból stringeket find és posal.

?esetleg legyen dupla slice, először a : utána, majd a kapottat a kettő " " között és aszerint rakom el

*/



int main(int argc, char* argv[])
{

	try {
		Fighter u1(Fighter::parseUnit(argv[1]));
		Fighter u2(Fighter::parseUnit(argv[2]));
		duel(u1, u2);
		
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
		return 1;
	}

	return 0;
}

