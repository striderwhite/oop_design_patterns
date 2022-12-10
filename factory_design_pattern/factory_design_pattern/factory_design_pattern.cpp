#include <iostream>

// In this example lets assume Person is more complex than two fields 
class Person {
    friend class PersonFactory;
    friend std::ostream& operator << (std::ostream& out, const Person& p);
    int age;
    int salary;

    Person(int age, int salary) : age(age), salary(salary) {};
};

std::ostream& operator<<(std::ostream& out, const Person& p)
{
    out << "Base " << &p << "\n";
    out << "Age " << p.age << " " << &p.age << "\n";
    out << "Salary " << p.salary << " " << &p.salary << std::endl;
    return out;
}

class PersonFactory {

public:
    Person static PoorOldPerson() {
        return Person(85, 0);
    }

    Person static YoungRichPerson() {
        return Person(25, 2501337);
    }
};

int main()
{
    Person p1 = PersonFactory::PoorOldPerson();
    Person p2 = PersonFactory::YoungRichPerson();

    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;

    std::cin.get();
}
