#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
	virtual void cast_a_vote() {
		cout << "Hrrrrr" << endl;
	}
	virtual void sight() {
		cout << "Eyes look forward" << endl;
	}

	// лапы
	int paws;
protected:
	bool tail;
	string teeth;
};

class Food 
{
public:
	virtual void type_of_food() {
		cout << "Eat everything" << endl;
	}
};

class PlantFood: public Food 
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
class Predator: virtual public Animal, public MeatFood {
public:
	Predator(bool tail) {
		this->tail = tail;
	}
	bool get_tail() {
		return tail;
	}
	// переместить методы с зубами в Animal 
	void set_teeth(string teeth) {
		this->teeth = teeth;
	}
	string get_teeth() {
		return this->teeth;
	}
};

// травоядный 
class Grass_feeding: virtual public Animal, public PlantFood { 
public:
	void sight() override {
		cout << "Eyes look to the sides" << endl;
	}
	void cast_a_vote() override {
		cout << "Frrr" << endl;
	}

};

// всеядный 
class Omnivorous: public Animal, public Food { 
public:
	// соединение подачи голоса хищника и травоядного 

};



int main()
{
	Grass_feeding Zebra;
	Zebra.type_of_food();
	Zebra.paws = 4;
	cout << Zebra.paws << endl;
	Omnivorous Vasya;
	Vasya.type_of_food();

	Predator Lion(1);
	Lion.type_of_food();
	cout << Lion.get_tail() << endl;
	Lion.set_teeth("sharp");
	cout << Lion.get_teeth() << endl;



	return 0;
}