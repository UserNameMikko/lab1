#include <fstream>
#include "Keeper.h"

Keeper::Keeper() {
    size = 0;
    head = nullptr;
}
Keeper::Keeper(int size): head(nullptr) {
    this->size = size;
}
Keeper::~Keeper() {
    if(head != nullptr) {
        Instance* buff;
        while (head->next != nullptr) {
            buff = head;
            head = head->next;
            buff->data->~Orchestra();
            delete(buff);
        }
    }

}
Orchestra* Keeper::operator[] (const int index) {
    if ((index >= size) || (index < 0))
        throw "Incorrect index!";
    else {
        Instance * buffer = head;
        for (int i = 0; i < size-index-1 ; i++)
            buffer = buffer->next;
        return (buffer->data);
    }
}

int Keeper::get_size() {
    return size;
}

void Keeper::insert(Orchestra *_data) {
    Instance* tmp;
    tmp = new Instance;
    tmp->data = _data;
    if(size == 0)
        tmp->next = 0;
    else
        tmp->next = head;
    ++size;
    head = tmp;
}

void Keeper::load() {
    if (size != 0) {
        Instance * buffer;
        while (head->next != nullptr)
        {
            buffer = head;
            head = head->next;
            buffer->data->~Orchestra();
            delete(head);
        }
        head->data->~Orchestra();
        delete(head);
    }
    std::ifstream file_in;
    std::string init_file = "data.txt";
    Orchestra* instruments;
    std::string manufacturer_name, defects_description, name, owner_name, type, short_description;
    double cost;
    int total_number, num_type, instruments_count;
    file_in.open(init_file);
    if (!file_in)
        throw "no file";
    file_in >> instruments_count;

    for (int i = 0; i < instruments_count; i++) {
        file_in >> num_type;
        if (num_type == 1) { // brass name  owner_name defects_description cost  total_number manufacturer_name
            file_in >> name >> cost >> owner_name >> total_number >>  manufacturer_name >> defects_description ;
            Brass* brass;
            brass = new Brass;
            brass->set_name(name);
            brass->set_cost(cost);
            brass->set_owner(owner_name);
            brass->set_total_num(total_number);
            brass->set_manufacture(manufacturer_name);
            brass->set_defects(defects_description);
            instruments = brass;
            insert(instruments);
        }
        if (num_type == 2) { // percussion  type; name; cost; owner_name; total_number;
            file_in >> name >> cost >>  owner_name >> total_number >> type;
            Percussion* perc;
            perc = new Percussion;
            perc->set_name(name);
            perc->set_cost(cost);
            perc->set_owner(owner_name);
            perc->set_total_num(total_number);
            perc->set_type(type);
            instruments = perc;
            insert(instruments);
        }
        if (num_type == 3) { // Strings name; cost; owner_name; total_number; manufacture_name; short_description;
            file_in>> name >> cost >> owner_name >> total_number >> manufacturer_name >> short_description;
            Strings* strings;
            strings = new Strings;
            strings->set_name(name);
            strings->set_cost(cost);
            strings->set_owner(owner_name);
            strings->set_total_num(total_number);
            strings->set_manufacture(manufacturer_name);
            strings->set_description(short_description);
            instruments = strings;
            insert(instruments);
        }
        file_in.ignore(32767, '\n');
    }
}

void Keeper::remove(int index) {
    if(size == 0)
        throw "size == 0!";
    int c = 0;
    while (c < index-1) {
        head = head->next;
        c++;
    }
    Instance * prev = head;
    prev->next->data->~Orchestra();
    prev->next->next;
    delete(prev->next);
    --size;
}

void Keeper::save() {
    std::ofstream file_out;
    std::string init_file = "data.txt";
    file_out.open(init_file, std::ios_base::app);
    if (!file_out)
        throw "no such file or directory!";
    else {
        file_out << size << std::endl;
        file_out.close();
    }
    Instance* buf = head;
    for (int i = 0; i < size; i++) {
        buf->data->saving();
        buf = buf->next;
    }
}
