/**
 * Класс Оркестр(Orchestra) хранит данные об инструментах: 
 *  - ударные (percussion), 
 *  - струнные(strings), 
 *  - духовые(brass/wind).
 * 
 * Для ударных инструментов определено:
 *  - тип(type),
 *  - название(name), 
 *  - стоимость(cost), 
 *  - количество единиц(number) в оркестре,
 *  - ФИО владельца(owner_name). 
 * 
 * Для струнных определено: 
 *  - название, 
 *  - ФИО владельца,
 *  - наименование производителя(manufacturer's name), 
 *  - стоимость(cost), 
 *  - количество единиц в оркестре(total_number),
 *  - краткое текстовое описание(instrument_description). 
 * 
 * Для духовых определено: название(name),
 *  - наименование производителя(manufacturer_name),
 *  - стоимость(cost),
 *  - ФИО владельца(owner_name),
 *  - количество единиц в оркестре,
 *  - какие дефекты присутствуют в инструменте (текстовое описание)(defects_description).
*/
#include "Keeper/Keeper.h"
#include "Menu/Menu.h"
int main(){
    Menu menu;
    menu.main_menu();
    /*Brass b;
    Percussion p;
    b.set_cost(2000.0);
    b.set_defects("nothing");
    b.set_manufacture("YAMAHA");
    b.set_name("Saxophone");
    b.set_total_num(20);
    b.set_owner("Me");
    std::cout<<b.get_manufacture()<<"\n"<<b.get_cost()<<"\n"<<b.get_owner()<<"\n"
    <<b.get_defects()<<"\n"<<b.get_name()<<"\n"<<b.get_total_num()<<std::endl;
    std::cout<<b;*/

    return 0;
}