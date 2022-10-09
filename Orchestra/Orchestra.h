#pragma once
#include <iostream>
class Orchestra {
private:
protected:
    std::string name;
    double cost;
    std::string owner_name;
    int total_number;

public:
    Orchestra() { name =""; cost =0.0;owner_name="";total_number=0; };
    virtual ~Orchestra() = default;

    virtual void set_cost(double _cost) = 0;
    virtual void set_name(std::string _name) = 0;
    virtual void set_owner(std::string _owner) = 0;
    virtual void set_total_num(int _total_num) = 0;

    virtual double get_cost() = 0;
    virtual std::string get_name() = 0;
    virtual std::string get_owner() = 0;
    virtual int get_total_num() = 0;

    virtual void show() = 0;
    virtual void saving() = 0;
    virtual void rewrite() = 0;


};

typedef struct Instance {
    Orchestra* data;
    Instance* next;
} Instance;