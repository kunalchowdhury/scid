#pragma once
#include <iostream>

class item
{

public:
	item();
	virtual ~item();
	virtual void showdata()
	{
		std::cout << "inside item \n";
	}
};

class bike : private item
{
public:
	bike() : item(){}
	~bike() {}
	void showdata()
	{
		std::cout << "inside bike \n";
	}

	void extra()
	{
		std::cout << "wasnt me \n";
	}
};

