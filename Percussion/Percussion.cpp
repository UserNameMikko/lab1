#include <fstream>
#include"Percussion.h"

Percussion::Percussion(){
    this->type ="";
    this->name = "";
    this->cost = 0;
    this->owner_name = "";
    this->total_number = 0;
}
Percussion::Percussion(const Percussion &perc) {
    this->type = perc.type;
    this->total_number = perc.total_number;
    this->name = perc.name;
    this->cost = perc.cost;
    this->owner_name = perc.owner_name;
}

double Percussion::get_cost() {
    return this->cost;
}
std::string Percussion::get_name() {
    return this->name;
}
std::string Percussion::get_owner(){
    std::cout<< "get_owner_perc"<< std::endl;
    return this->owner_name;
}
int Percussion::get_total_num() {
    return this->total_number;
}
std::string Percussion::get_type(){
    return this->type;
}



void Percussion::set_cost(double _cost) {
    this->cost = _cost;
}
void Percussion::set_name(std::string _name) {
    this->name = _name;
}
void Percussion::set_owner(std::string _owner) {
    this->owner_name = _owner;
}
void Percussion::set_total_num(int _total_num) {
    this->total_number = _total_num;
}
void Percussion::set_type(std::string _type){
    this->type = _type;
}


void Percussion::show() {
    std::cout<<"---show percussion---\n"
               "name: "<<name<<
               "\ncost: "<<cost<<
               "\ntype: "<<type<<
               "\nowner name: "<<owner_name<<
               "\ntotal number: "<<total_number<<
               "\n---------------------"<<
               std::endl;
}
void Percussion::saving() {
    std::ofstream file_out;
    std::string init_file = "data.txt";
    file_out.open(init_file, std::ios_base::app);
    if (!file_out)
        throw "Error opening!";
    else {
        file_out << 2 << std::endl << name << std::endl << cost << std::endl
        << owner_name << std::endl << total_number << std::endl << type << std::endl;
        file_out.close();
    }
}
void Percussion::rewrite() {
    std::cout << "-------------------------------" << std::endl;
    std::cout << "Change data of Percussion instrument\n"
                 "input:\n"
                 "name -> cost -> owner name-> total number-> type"<< std::endl;
    try {
        std::cin>>this->name>>this->cost>>this->owner_name>>
                this->total_number>>this->type;
    } catch (std::exception e) {
        throw e;
    }

}
Percussion::~Percussion() = default;