#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
	const int N = 10;
	Animal *animals[N];

	for(int i = 0; i < 5; i++)
		animals[i] = new Dog();
	for (int i = 5; i < N; i++)
		animals[i] = new Cat();

	for (int i = 0; i < N; i++)
	{
		std::cout << "animal"<< i << " type :"<<animals[i]->getType() << " " << std::endl;
		animals[i]->makeSound();
	}
	for (int i = 0; i < N; i++)
		delete animals[i];

	return 0;
}