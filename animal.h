#pragma once
#include "all.h"

//const Coordinate MAP_LOCATION(5, 2);

class Animal
{
public:
    int _Direction;
    float _Distance, _DistanceSum;

    Coordinate _Pos;
    std::vector<std::string> _STRING;
    std::deque<Animal *> _Lane;

    Animal();
    virtual ~Animal();
};

class Bird : public Animal
{
public:
    Bird();
    Bird(int x, int y);
    ~Bird();
};

class Dinosaur : public Animal
{
public:
    Dinosaur();
    Dinosaur(int x, int y);
    ~Dinosaur();
};

class AnimalControl
{
private:
    const int BIRD_LOCATION_Y = 7,
              DINOSAUR_LOCATION_Y = 18,
              BIRD_LENGTH = 5,
              DINOSAUR_LENGTH = 17;

    int DIVIDE_CONSTANT = 1000000;

    void BirdMove(const int &ElapsedTime);
    void DinosaurMove(const int &ElapsedTime);

public:
    int _Level = 1;
    std::deque<Animal *> _BirdLane, _DinosaurLane;

    AnimalControl();

    void CreateObj();
    void Move(const int &ElapsedTime);
    void SetLevel(const int &x);

    void AddBird();
    void AddDinosaur();
};