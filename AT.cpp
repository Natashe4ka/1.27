#include "AT.hpp"


int AutoTest1(){
    QUEUE q;
    q.add_string(0, "w");
    
    
    if (q.return_max_last_num()==0) return 1;
    else return 0;
}

int AutoTest2(){
    QUEUE q;
    q.add_string(1, "fjd");
    q.add_string(2, "fkjgv");
    if (q.return_first_n()==2) return 1;
    else return 0;
}

int AutoTest3(){
    QUEUE q;
    q.add_string(0, "q");
    q.add_string(1, "e");
    if (q.calc_l_and_size().first==2 && q.calc_l_and_size().second==2) return 1;
    else return 0;
}
int AutoTest(){
    
    if(!AutoTest1()){
        std::cout << "AutoTest1 failed." << std::endl;
    }
     if(!AutoTest2()){
        std::cout << "AutoTest2 failed." << std::endl;
    }
    if(!AutoTest3()){
        std::cout << "AutoTest3 failed." << std::endl;
    }
    
    
     
    if( AutoTest1() && AutoTest2() && AutoTest3()) return 1;
    else return 0;

}

