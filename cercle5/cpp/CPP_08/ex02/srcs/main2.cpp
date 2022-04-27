#include <iostream>
#include <cstdlib>
#include "MutantStack.hpp"
#define STACK_SIZE 5

static int	random_nb() {
// This clang attribute allows to not use the seed variable without generating a
// compilation error. The evaluation of the expression (srand(time(NULL)), 0) is
// assigned to this variable.
	static int seed __attribute__((unused)) = (srand(time(NULL)), 0);
	return (rand() % 10000);
}

int main()
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
		std::cout << std::endl;
	{
		MutantStack<int> ms;
		for (int i = 0; i < STACK_SIZE; i++)
			ms.push(random_nb());
		for (MutantStack<int>::const_iterator it = ms.begin(), ite = ms.end(); it != ite; it++) {
			// ++(*it); // it's const /!\.
			std::cout << *it;
			if (it + 1 != ite)
				std::cout << ' ';
		}
		std::cout << std::endl;
		for (MutantStack<int>::const_reverse_iterator it = ms.rbegin(), ite = ms.rend(); it != ite; it++) {
			// ++(*it); // it's const /!\.
			std::cout << *it;
			if (it + 1 != ite)
				std::cout << ' ';
		}
		std::cout << std::endl;
		for (MutantStack<int>::iterator it = ms.begin(), ite = ms.end(); it != ite; it++) {
			++(*it); // you can here
			std::cout << *it;
			if (it + 1 != ite)
				std::cout << ' ';
		}
		std::cout << std::endl;
		for (MutantStack<int>::reverse_iterator it = ms.rbegin(), ite = ms.rend(); it != ite; it++) {
			++(*it); // you can here
			std::cout << *it;
			if (it + 1 != ite)
				std::cout << ' ';
		}
		std::cout << std::endl;
	}
	return (EXIT_SUCCESS);
}