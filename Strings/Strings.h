#pragma once
#include"../Orchestra/Orchestra.h"
#include <vector>
class Strings: public Orchestra{
private:
    std::string manufacturer_name;
    std::string short_description;

public:
    Strings();
    Strings(Strings& str);
    ~Strings() override;

    void set_manufacture(std::string _manufacture);
    void set_description(std::string _description);
    std::string get_manufacture();
    std::string get_description();

    void set_cost(double _cost) override;
    void set_name(std::string _name) override;
    void set_owner(std::string _owner) override;
    void set_total_num(int _total_num) override;

    double get_cost() override;
    std::string get_name() override;
    std::string get_owner() override;
    int get_total_num() override;

    void show() override;
    void saving() override;
    void rewrite() override;

    friend std::ostream& operator<<(std::ostream& os, const Strings& obj) {
        std::vector<std::string> v;
        v.push_back(obj.name);
        v.push_back(obj.owner_name);
        v.push_back(obj.manufacturer_name);
        v.push_back(obj.short_description);
        v.push_back(std::to_string(obj.total_number));
        v.push_back(std::to_string(obj.cost));
        for (auto & i : v)
            os << i + " ";
        return os;
    }
};