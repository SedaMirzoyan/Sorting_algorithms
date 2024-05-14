#include <iostream>
#include "Vector.h"
#include "Counting_sort.h"


int main()
{
	int n;
	std::cout << "Enter the number of elements\n";
	std::cin >> n;

	Vector<int> ob(n);
	ob.genElements();
	ob.printVector();
	ob.getElement(2);

	ob.pushBack(9);
	ob.popBack();
	ob.printVector();

	Vector<int> ob1 = ob;

	std::cout << "Counting sort\n";
	countingSortVec(ob1, n);

	return 0;
}