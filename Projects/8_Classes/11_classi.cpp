#include <iostream>
#include <string>

using namespace std;

//This class rappresents a generic Dog
class Dog
{
	public:
	string kind;
	int color[3];
	int age;
	string name;
	float weight;
	
		void bark()
	{
		cout << "SONO" << name << endl;
		cout << "WOOF" << endl;
	}
};



class Dog2
{
	public:
	string kind;
	int color[3];
	int age;
	string name;
	float weight;
	
	void Dog2(string k, int c[3], int a, string n, float w)
	{
		kid = k;
		color[0] = c[0];
		color[1] = c[1];
		color[2] = c[2];
		age = a;
		name = n;
		weight = w;
	}
	
		void bark()
	{
		cout << "SONO" << name << endl;
		cout << "WOOF" << endl;
	}	
}

int main()
{
	Dog huski;
	husky.kind = "HUSKY";
	husky.age = 4;
	husky.color[0] = 127;
	husky.color[1] = 127;
	husky.color[2] = 127;
	husky.name = "Freccia";
	husky.weight = 14.5;
	
	husky.bark();
	
	//Create another dog using class Dog
	
	Dog chihuahua();
	chihuahua.age = 2;
	chihuahua.color[0] = 0;
	chihuahua.color[1] = 0;
	chihuahua.color[2] = 0;
	chihuahua.name = "Negros";
	chihuahua.weight = 999.5;
	
	chihuahua.bark();
	
	int c[3];
	c[0] = 10;
	c[1] = 20;
	c[2] = 30;
	Dog2 rex("PastoreTedesco", c, 4, "Willy", 15.7);
	rex.bark();
	
	return 0;
}