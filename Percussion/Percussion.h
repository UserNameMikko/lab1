#pragma once
#include "../Orchestra/Orchestra.h"
class Percussion: public Orchestra{
private:
    std::string type;
public:
    Percussion();
    Percussion(const Percussion& perc);
    ~Percussion() override;

    void set_type(std::string _type);
    void set_cost(double _cost) override;
    void set_name(std::string _name) override;
    void set_owner(std::string _owner) override;
    void set_total_num(int _total_num) override;

    std::string get_type();
    double get_cost() override;
    std::string get_name() override;
    std::string get_owner() override;
    int get_total_num() override;

    void show() override;
    void saving() override;
    void rewrite() override;
    void redact(std::string item1, double item2, std::string item3, int item4) override;

    friend std::ostream& operator<<(std::ostream& os, const Percussion& obj) {
        os << "Type = Percussion\n" << "name = " <<obj.name<<"\n"<< "cost = " <<obj.cost<<"\n"
        << "owner = " <<obj.owner_name<<"\n"<< "total = " <<obj.total_number<<"\n"<< "type = " <<obj.type<<std::endl;
        return os;
    }
};