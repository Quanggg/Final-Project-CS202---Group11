#pragma once
#include <vector>
#include <string>

class vehicle
{

public:
    std::vector<std::string> st;
    vehicle(int x, int y) : x(x), y(y){};
    int x, y;
    virtual ~vehicle(){};
};

class car : public vehicle
{

public:
    car(int x, int y) : vehicle(x, y)
    {
        st.assign(5, "");
        st[0] = " ------";
        st[1] = "|  car |";
        st[2] = "|      |";
        st[3] = " ------";
        st[4] = "O o  o O";
    }
    ~car(){};
};

class truck : public vehicle
{

public:
    truck(int x, int y) : vehicle(x, y)
    {
        st.assign(5, "");
        st[0] = " ------";
        st[1] = "| truck|";
        st[2] = "|      |";
        st[3] = " ------";
        st[4] = "O o  o O";
    }
    ~truck(){};
};
class controlVehicle
{
public:
    std::vector<vehicle *> list;
    controlVehicle()
    {
        vehicle *v;
        v = new car(0, 0);
        list.push_back(v);
        v = new truck(0, 10);
        list.push_back(v);
    }
    void updateXY()
    {
        for (auto i : list)
            i->x += 1;
    }
    ~controlVehicle()
    {
        for (auto i : list)
            delete i;
    }
};