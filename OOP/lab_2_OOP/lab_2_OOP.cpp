#include <iostream>
#include <string>

using namespace std;

namespace Animals {

	class Animal
	{
	public:
		virtual void cast_a_vote() {
			cout << "Vote: Hrrrrr" << endl;
		}
		virtual void sight() {
			cout << "Sight: Eyes look forward" << endl;
		}
		virtual void look_at_tree() {
			cout << "Its gorgeous tree!" << endl;
		}
		void set_teeth(string teeth) {
			this->teeth = teeth;
			cout << "Teeth: " << teeth << endl;
		}

		int paws;
	protected:
		bool tail;
		string teeth;
	private:
		int parents_num; 
	};

	class Food
	{
	public:
		virtual void type_of_food() {
			cout << "Eat everything" << endl;
		}
	};

	class PlantFood : public Food
	{
	public:
		void type_of_food() override {
			cout << "Eat plants and grass" << endl;
		}
	};
	class MeatFood : public Food
	{
	public:
		void type_of_food() override {
			cout << "Eats meat in most cases" << endl;
		}
	};
	// хищник
	class Predator : virtual public Animal, public MeatFood {
	public:
		Predator(bool tail) {
			this->tail = tail;
			if (tail == true) {
				cout << "Tail: exists" << endl;
			}
			else {
				cout << "Tail: отсутствует" << endl;
			}
			
		}
		/*void cast_a_vote() override {
			cout << "Vote: Hrrrrr" << endl;
		}*/
	};

	// травоядный
	class Grass_feeding : virtual public Animal, public PlantFood {
	public:
		void sight() override {
			cout << "Sight: Eyes look to the sides" << endl;
		}
		void cast_a_vote() override {
			cout << "Vote: Frrr" << endl;
		}
		void look_at_tree() override {
			cout << "I would like to eat this tree" << endl;
		}

	};

	// всеядный
	class Omnivorous : virtual public Animal, public Food {
	public:
		void cast_a_vote() override {
			cout << "Vote: Fhfhfhrfh" << endl;
		}
		void look_at_tree() override {
			cout << "WOW.This tree is AMAZING" << endl;
		}
	};

	class Unusual_animal : virtual private Animal , public Food{
	public:
		int get_parents_number(int parents_num) {
			this->num = parents_num;
			return num;
		}
	private:
		int num;
	};
}


int main()
{
	using namespace Animals;

	Predator Lion(true);
	Lion.set_teeth("sharp");
	Lion.cast_a_vote();
	Lion.look_at_tree();
	Lion.paws = 12;
	Lion.sight();
	Lion.type_of_food();
	cout << "Paws: " << Lion.paws << endl << endl;


	Omnivorous Rat;
	Rat.set_teeth("sharp");
	Rat.cast_a_vote();
	Rat.look_at_tree();
	Rat.paws = 4;
	Rat.sight();
	Rat.type_of_food();
	cout << "Paws: " << Rat.paws << endl << endl;


	Grass_feeding Giraffe;
	Giraffe.set_teeth("curves");
	Giraffe.cast_a_vote();
	Giraffe.look_at_tree();
	Giraffe.paws = 4;
	Giraffe.sight();
	Giraffe.type_of_food();
	cout << "Paws: " << Giraffe.paws << endl << endl;


	Unusual_animal Ilya;
	int parents = Ilya.get_parents_number(10);
	cout <<"Number of ancestors of an unusual animal: "<< parents;
	


	return 0;
}