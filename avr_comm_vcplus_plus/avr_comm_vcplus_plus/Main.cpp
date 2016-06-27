#include <iostream>
#include <vector>
#include <initializer_list>
#include <memory>

using namespace std;
class Widget
{
public:
	Widget(int i, double d)
	{
		cout << "i = " << i << " d = " << d;
	}
	
	Widget(initializer_list<bool> i) : vc(i)
	{
		for (auto n : vc)
		{
			cout << n << "\n";
		}
	}
	operator float() const
	{
		cout << "called float \n";

		return 1;
	}

	vector<bool> vc;
};

int main0()
{
	/*
	std::cout << "hello to this world1.. \n";
	Widget w{ 1, 2};
	Widget w1{ w };
	cout << " ------------ \n";
	for(auto v : w1.vc)
	{
		cout << v << "\n";
	}
	cout << w << "\n";
*/
	return 1;
	//while(true) {}
}