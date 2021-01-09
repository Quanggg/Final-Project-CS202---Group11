#pragma once
#include "all.h"

class Bird : public Object
{
public:
    Bird(int x, int y);
    ~Bird();
};

class Dinosaur : public Object
{
public:
    Dinosaur(int x, int y);
    ~Dinosaur();
};

class Animal
{
private:
    const int BIRD_LOCATION_Y = 7,
              DINOSAUR_LOCATION_Y = 18,
              BIRD_LENGTH = 5,
              DINOSAUR_LENGTH = 17;

    void BirdMove(const int &ElapsedTime);
    void DinosaurMove(const int &ElapsedTime);

public:
    std::deque<Object *> _BirdLane, _DinosaurLane;

    Animal(const int &level, const bool &call_CreateObj = true);
    ~Animal();

    void CreateObj();
    void Move(const int &ElapsedTime);

    void AddRandomBird();
    void AddRandomDinosaur();

    void AddBird(Object *obj);
    void AddDinosaur(Object *obj);

    void SaveAnimal(std::ofstream &f);
};
