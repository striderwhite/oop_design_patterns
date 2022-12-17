#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>

float randFloat(float LO = -250.0f, float HI = 250.0f) {
    return LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));
}

class Entity {
protected:
    float x, y, z;

public:
    Entity() : x(randFloat()), y(randFloat()), z(randFloat()) { };
};

class Animal : Entity {
    std::string name;
    int rareity;

public:
    void Speak() {
        std::cout << "I am a " << name << " and I am of rareity " << rareity << " I am currently at position X: " << x << " Y: " << y << " Z: " << z << std::endl;
        std::cout << "My name (std::string) is located at " << &name << " and has a object size of " << sizeof(name) << " with a total of " << name.size() << " characters" << std::endl;
        std::cout << "My rareity (int) is located at address " << &rareity << " and has a size of " << sizeof(rareity) << std::endl;
    }

    Animal(std::string const& name) : rareity(rand() % 10) {
        this->name = name;
    }
};


int main()
{
    // rng seeder
    srand(static_cast <unsigned> (time(0)));

    std::vector<Animal*> animals;

    animals.emplace_back(new Animal("Dog"));
    animals.emplace_back(new Animal("Cat"));
    animals.emplace_back(new Animal("Super Dog Cat Bird Thing"));

    for (int i = 0; i < animals.size(); i++) {
        auto a = animals[i];
        a->Speak();
        std::cout << "Address of Animal instance is: " << &*animals[i] << " sizeof = " << sizeof(*animals[i]) << "\n" << std::endl;
    }

    std::cout << "\nent list (vector<Animal>) addy -> " << &animals << " with a sizeof " << sizeof(animals) << std::endl;
    std::getchar();
}
