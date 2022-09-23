#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class Car
{
private:
    int Color;
    string Name;
    string Owner;
    public:
    Car(int color, string name, string owner)
    {
        this->Color = color;
        this->Name = name;
        this->Owner = owner;
    }
    void Show()
    {
        cout<<this->Color << " "<<this->Name << " "<<this->Owner << endl;
    }
};

class Builder
{
public:
    virtual Builder *SetName(string name) = 0;
    virtual Builder *SetColor(int color) = 0;
    virtual Builder *SetOwner(string owner) = 0;
    virtual Car Build() = 0;
};

class CarBuilder : public Builder
{
public:
    CarBuilder()
    {
    }

private:
    int Color;
    string Name;
    string Owner;

public:
    Builder *SetColor(int color)
    {
        this->Color = color;
        return this;
    }

    Builder *SetName(string name)
    {
        this->Name = name;
        return this;
    }

    Builder *SetOwner(string owner)
    {
        this->Owner = owner;
        return this;
    }
    Car Build()
    {
        return Car(this->Color, this->Name, this->Owner);
    }
};

class PremiumCarBuilder : public Builder
{
public:
    PremiumCarBuilder()
    {
    }

private:
    int Color;
    string Name;
    string Owner;

public:
    Builder *SetColor(int color)
    {
        this->Color = color;
        return this;
    }

    Builder *SetName(string name)
    {
        if(name == "premium")
        cout<<"Chao Khanh vip";
        this->Name = name;
        return this;
    }

    Builder *SetOwner(string owner)
    {
        this->Owner = owner;
        return this;
    }
    Car Build()
    {
        return Car(this->Color, this->Name, this->Owner);
    }
};

int main()
{
    Builder *builder = new PremiumCarBuilder();
    Car car = builder
    ->SetColor(1)
    ->SetName("premium")
    ->SetOwner("truong")
    ->Build();
    car.Show();
}