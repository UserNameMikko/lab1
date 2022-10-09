#include <fstream>
#include"Strings.h"
Strings::Strings(){
    this->name = "";
    this->cost = 0;
    this->owner_name = "";
    this->total_number = 0;
    this->manufacturer_name = "";
    this->short_description = "";
}
Strings::Strings(Strings &str) {
    this->name = str.name;
    this->cost = str.cost;
    this->owner_name = str.owner_name;
    this->total_number = str.total_number;
    this->manufacturer_name = str.manufacturer_name;
    this->short_description = str.short_description;
}
void Strings::set_manufacture(std::string _manufacture){
    this->manufacturer_name = _manufacture;
}
void Strings::set_description(std::string _description){
    this->short_description = _description;
}
void Strings::set_total_num(int _total_num) {
    this->total_number = _total_num;
}
void Strings::set_cost(double _cost) {
    this->cost = _cost;
}
void Strings::set_name(std::string _name) {
    this->name = _name;
}
void Strings::set_owner(std::string _owner) {
    this->owner_name = _owner;
}

std::string Strings::get_manufacture(){
    return this->manufacturer_name;
}
std::string Strings::get_description(){
    return this->short_description;
}
int Strings::get_total_num() {
    return this->total_number ;
}
double Strings::get_cost() {
    return this->cost;
}
std::string Strings::get_name() {
    return this->name;
}
std::string Strings::get_owner() {
    return this->owner_name;
}

void Strings::show() {
    std::cout<<"---show strings--\n"
        "name: "<<this->name<<
        "\ncost: "<<this->cost<<
        "\nowner name: "<<this->owner_name<<
        "\ntotal number: "<<this->total_number<<
        "\nmanufacturer name: "<<this->manufacturer_name<<
        "\nshort description: "<<this->short_description<<
        "\n---------------------"<<std::endl;
}
void Strings::saving() {
    std::ofstream file_out;
    std::string init_file = "data.txt";
    file_out.open(init_file, std::ios_base::app);
    if (!file_out)
        throw "Error opening!";
    else {
        file_out << 3 << std::endl << this->name << std::endl << this->cost << std::endl
                 << this->owner_name << std::endl << this->total_number << std::endl
                 << this->manufacturer_name << std::endl << this->short_description << std::endl;
        file_out.close();
    }
}
void Strings::rewrite() {
    std::cout << "-------------------------------" << std::endl;
    std::cout << "Change data of Strings instrument\n"
                 "input:\n"
                 "name -> cost -> owner name-> total number-> manufacturer name ->short description"<<std::endl<<
                 "if your text variables contains >1 word use '_' for current work of program"<< std::endl;
    std::cin>>this->name>>this->cost>>this->owner_name>>
    this->total_number>>this->manufacturer_name>>this->short_description;

}
Strings::~Strings() = default;