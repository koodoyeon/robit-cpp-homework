#include <iostream>
#include <string>
using namespace std;

// 기본 클래스: Animal
class Animal {
protected:
    string name;
    int age;

public:
    Animal(string n, int a) : name(n), age(a) {}
    virtual void makeSound() = 0; // 순수 가상 함수
    void showInfo() {
        cout << "이름: " << name << ", 나이: " << age << "살" << endl;
    }
};

// 개 클래스
class Dog : public Animal {
public:
    Dog(string n, int a) : Animal(n, a) {}
    void makeSound() override {
        cout << "Bark!" << endl;
    }
};

// 고양이 클래스
class Cat : public Animal {
public:
    Cat(string n, int a) : Animal(n, a) {}
    void makeSound() override {
        cout << "Meow!" << endl;
    }
};

// 새 클래스
class Bird : public Animal {
public:
    Bird(string n, int a) : Animal(n, a) {}
    void makeSound() override {
        cout << "Chirp!" << endl;
    }
};

int main() {
    // 동물 객체 생성
    Animal* myDog = new Dog("Buddy", 4);
    Animal* myCat = new Cat("Whiskers", 3);
    Animal* myBird = new Bird("Tweety", 1);

    // 각 동물의 정보 출력 및 소리 내기
    myDog->showInfo();
    myDog->makeSound();

    myCat->showInfo();
    myCat->makeSound();

    myBird->showInfo();
    myBird->makeSound();

    // 동물 객체 메모리 해제
    delete myDog;
    delete myCat;
    delete myBird;

    return 0;
}
