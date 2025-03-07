#include <iostream>

class Animatronic
{
protected:
    std::string name;
    std::string color;
public:
    Animatronic(){
        name = "Endo 01";
        color = "Metal";
    }
    ~Animatronic() = default;

    template <class T>
    Animatronic& operator=(T const& other)
    {
        name = other->name;
        color = other->color;
        return *this;
    }

    std::string GetName() const
    {
        return name;
    }

    std::string GetColor() const
    {
        return color;
    }
};


class Fready : public Animatronic
{
public:
    Fready() {
        name = "Fready";
        color = "Brown";
    }
    ~Fready() = default;
};

class Bonnie : public Animatronic
{
public:
    Bonnie() {
        name = "Bonnie";
        color = "Blue";
    }
    ~Bonnie() = default;
};

class Chica : public Animatronic
{
public:
    Chica() {
        name = "Chica";
        color = "Yellow";
    }
    ~Chica() = default;
};

class Foxie : public Animatronic
{
public:
    Foxie() {
        name = "Foxie";
        color = "Red";
    }
    ~Foxie() = default;
};


enum AnimatronicName
{
    fready,
    bonnie,
    chica,
    foxy
};


Animatronic AnimatronicFactory(AnimatronicName name) {
    Animatronic animatronic;

    switch (name) {
    case fready:
        animatronic = new Fready();
        break;
    case bonnie:
        animatronic = new Bonnie();
        break;
    case chica:
        animatronic = new Chica();
        break;
    case foxy:
        animatronic = new Foxie();
        break;
    }

    return animatronic;
}

int main()
{
    Animatronic First = AnimatronicFactory(fready);
    //Представьте, что тут есть код...
    //Представьте, что тут есть код...
    //Представьте, что тут есть код...
    //Представьте, что тут есть код...
    //Представьте, что тут есть код...
    //Представьте, что тут есть код...
    //Представьте, что тут есть код...
    //Представьте, что тут есть код...
    //Представьте, что тут есть код...
    //Представьте, что тут есть код...

	return 0;
}