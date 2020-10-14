#include"Fighter.h"
#include"Jsonparser.h"

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
		std::map<std::string, std::string>map1 = Jsonparser::parseJson(argv[1]);

		std::map<std::string, std::string>map2 = Jsonparser::parseJson(argv[2]);

		Fighter u1(map1["name"], std::stoi (map1["hp"]),std::stof( map1["dmg"]));
		Fighter u2(map2["name"], std::stoi (map2["hp"]),std::stof( map2["dmg"]));

//		std::cout << u1.getName() << "\t" << u1.getHP() << "\t" << u1.getDMG() << "\t" << std::endl;
//		std::cout << u2.getName() << "\t" << u2.getHP() << "\t" << u2.getDMG() << "\t" << std::endl;

		duel(u1, u2);
		//std::cout << u1.getName() <<"\t"<< u1.getHP() << "\t" << u1.getDMG() << "\t" << std::endl;
		//std::cout << u2.getName()<<"\t" << u2.getHP() << "\t" << u2.getDMG() << "\t" << std::endl;

	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
		
		//std::cout << u1.getName() <<"\t"<< u1.getHP() << "\t" << u1.getDMG() << "\t" << std::endl;
		//std::cout << u2.getName()<<"\t" << u2.getHP() << "\t" << u2.getDMG() << "\t" << std::endl;

		//std::cout << "#\n";
		//for (auto&j : mymap)
		//	std::cout << j.first << "\t" << j.second << std::endl;
		//std::cout << "#\n";
		//Fighter f1(mymap["name"],std::stoi(mymap["hp"]),std::stof(mymap["dmg"]));

		//Fighter m1(mymap["name"], std::stoi(mymap["hp"]), std::stof(mymap["dmg"]));

		///*működik */
		//std::cout << f1.getName() <<"\t"<< f1.getHP() << "\t" << f1.getDMG() << "\t" << std::endl;
	return 0;
}
