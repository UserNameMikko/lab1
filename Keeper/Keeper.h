#pragma once
#include "../Brass/Brass.h"
#include "../Percussion/Percussion.h"
#include "../Strings/Strings.h"
class Keeper{
private:
    int size;
    Instance * head = nullptr;
public:
    Keeper();
    Keeper(int size);
    ~Keeper();
    int get_size();
    Orchestra* operator[] (const int index);

    void insert(Orchestra* n_data);
    void remove(int index);
    void save();
    void load();
};
