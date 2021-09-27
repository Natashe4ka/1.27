#ifndef queue_hpp
#define queue_hpp

#include <iostream>

class QUEUE {
private:
    int* number; //порядок очереди
    int* sort_num; //порядковые номера возрастание
    std::string* sort_string; //строки по порядку
    int last_n_s; // максимальный следующий элемент
    int calc; //кол-во строк
public:
    QUEUE (){
        number = nullptr;
        sort_string = nullptr;
        number = nullptr;
        last_n_s = 0;
        calc = 0;
        sort_num = nullptr;
    }
    

    void add_string(const int, const std::string);
    void print ();
    void pr ();
    
    int return_first_n ();
    
    int return_max_last_num ();
    
    std::string copy_and_del ();
    
    void all_pr ();
    std::pair<int, int> calc_l_and_size ();
    
    ~QUEUE ();
};


#endif
