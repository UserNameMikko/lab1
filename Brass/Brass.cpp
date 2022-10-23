#include <fstream>
#include"Brass.h"

std::string Brass::get_manufacture() {
   return this->manufacturer_name;
}

std::string Brass::get_defects(){
    return this->defects_description;
}
double Brass::get_cost() {
    return this->cost;
}
std::string Brass::get_name() {
    return this->name;
}
std::string Brass::get_owner(){
    return this->owner_name;
}
int Brass::get_total_num() {
    return this->total_number;
}


void Brass::set_manufacture(std::string _manufacture) {
    this->manufacturer_name = _manufacture;
}
void Brass::set_defects(std::string _defects) {
    this->defects_description = _defects;
}
void Brass::set_cost(double _cost) {
    this->cost = _cost;
}
void Brass::set_name(std::string _name) {
    this->name = _name;
}
void Brass::set_owner(std::string _owner) {
    this->owner_name = _owner;
}
void Brass::set_total_num(int _total_num) {
    this->total_number = _total_num;
}
Brass::Brass(){
    this->cost = 0;
    this->defects_description = "";
    this->manufacturer_name = "";
    this->total_number = 0;
    this->owner_name = "";
    this->name = "";
}
Brass::Brass(const Brass &brass) {
    this->manufacturer_name = brass.manufacturer_name;
    this->cost = brass.cost;
    this->defects_description = brass.defects_description;
    this->total_number = brass.total_number;
    this->owner_name = brass.owner_name;
    this->name = brass.name;
}
void Brass::show() {
    std::cout << *this << std::endl;
}
void Brass::saving() {
    std::ofstream file_out;
    std::string init_file = "data.txt";
    file_out.open(init_file, std::ios_base::app);
    if (!file_out)
        throw "Error opening!";
    else {
        file_out << 1 << std::endl << name << std::endl << cost << std::endl
                 << owner_name << std::endl << total_number << std::endl << manufacturer_name<< std::endl
                 << defects_description << std::endl;
        file_out.close();
    }
}
void Brass::rewrite() {
    std::cout << "-------------------------------" << std::endl;
    std::cout << "Change data of Brass instrument\n"
                 "input:\n"
                 "name -> cost -> owner name-> total number-> manufacturer name ->defects description"<<std::endl<<
                 "if your text variables contains >1 word use '_' for current work of program"<< std::endl;
    std::cin>>this->name>>this->cost>>this->owner_name>>
    this->total_number>>this->manufacturer_name>>this->defects_description;
}

Brass::~Brass() = default;