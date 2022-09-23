#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
class IAnimal
{
public:
    virtual string GetName() = 0;
};

class Dog : public IAnimal
{
public:
    Dog()
    {
    }
    string GetName()
    {
        return "Dog";
    }
};

class Cat : public IAnimal
{
public:
    Cat()
    {
    }
    string GetName()
    {
        return "Cat";
    }
};

class Duck : public IAnimal
{
public:
    Duck()
    {
    }
    string GetName()
    {
        return "Duck";
    }
};

class Creator
{
public:
    virtual IAnimal *FactoryMethod() = 0;
};

class RamdomCreator : public Creator
{
public:
    RamdomCreator()
    {
    }
    IAnimal *FactoryMethod()
    {
        IAnimal *animal;
        srand(time(NULL));
        int res = rand() % (2 - 0 + 1) + 0;
        if (res == 0)
            animal = new Dog();
        else if (res == 1)
            animal = new Cat();
        else
            animal = new Duck();
        return animal;
    } 
};

class SequenceCreator : public Creator
{
public:
    SequenceCreator()
    {
    }
    int index = 0;
    IAnimal* FactoryMethod()
    {
        IAnimal *animal;
        if (index == 0)
        {
            animal = new Dog();
            index++;
        }
        else if (index == 1)
        {
            animal = new Cat();
            index++;
        }
        else
        {
            animal = new Duck();
            index = 0;
        }
        return animal;
    }
};

int main()
{
    Creator *creator = new SequenceCreator();
    cout << creator->FactoryMethod()->GetName()<<endl;
    cout << creator->FactoryMethod()->GetName()<<endl;
    cout << creator->FactoryMethod()->GetName()<<endl;
     cout << creator->FactoryMethod()->GetName()<<endl;
    cout << creator->FactoryMethod()->GetName()<<endl;
    cout << creator->FactoryMethod()->GetName()<<endl;
}