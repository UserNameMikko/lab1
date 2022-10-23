#pragma once
#include "../Orchestra/Orchestra.h"

class Brass: public Orchestra{
private:
    std::string manufacturer_name;
    std::string defects_description;
public:
    Brass();
    Brass(const Brass& brass);
    ~Brass() override;

    void set_manufacture(std::string _manufacture);
    void set_defects(std::string _defects);
    void set_cost(double _cost) override;
    void set_name(std::string _name) override;
    void set_owner(std::string _owner) override;
    void set_total_num(int _total_num) override;

    std::string get_defects();
    std::string get_manufacture();
    double get_cost() override;
    std::string get_name() override;
    std::string get_owner() override;
    int get_total_num() override;

    void show() override;
    void saving() override;
    void rewrite() override;

    friend std::ostream& operator<<(std::ostream& os, const Brass& obj) {
        os << "Type = Brass\n" << "name = " <<obj.name<<"\n"<< "cost = " <<obj.cost<<"\n"
           << "owner = " <<obj.owner_name<<"\n"<< "total = " <<obj.total_number<<"\n"<< "defects = "
           <<obj.defects_description << std::endl;
        return os;
    }
};


