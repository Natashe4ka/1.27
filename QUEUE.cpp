#include "QUEUE.hpp"


    void QUEUE::add_string(const int num, const std::string str) { //num порядковый номер строки
        if(calc == 0) {
          sort_string = new std::string[num+1];
          sort_num = new int[num+1];
          for (int i = 0; i < num+1; i++) {
            sort_string[i] = "";
            sort_num[i] = -1;
          }
          number = new int[1];

          calc++;
          last_n_s = num;
          sort_string[num] = str;
          sort_num[num] = num;
          number[0] = num;
        }
        else if (num > last_n_s) {
          std::string* f_h = new std::string[last_n_s + 1];
          for (int i = 0; i < last_n_s + 1; i++) {
            f_h[i] = sort_string[i];
          }
         /*std::cout << "----" << std::endl;
          for (int i = 0; i < last_n_s + 1; i++) {
            std::cout << f_h[i] << "     ";
          }
          std::cout << std::endl  << "----" << std::endl;*/
          
          delete [] sort_string;

          sort_string = new std::string[num + 1];
          for (int i = 0; i < last_n_s + 1; i++) {
            sort_string[i] = f_h[i];
          }
            int* extra;
            extra = (int*)realloc(sort_num, (num + 1) * sizeof(int));
                    if( !extra ){
                        std::cout<<("Error! Cannot allocate memory")<<"\n";
                        exit(-2);
                    }
            sort_num = extra;
        
            
        //    sort_num = (int*)realloc(sort_num, (num + 1) * sizeof(int));
          for (int i = last_n_s + 1; i < num + 1; i++) {
            sort_string[i] = "";
              sort_num [i]=-1;
          }
        
          /*std::cout << "----" << std::endl;
          for (int i = 0; i < num + 1; i++) {
            std::cout << sort_string[i] << "     ";
          }
          std::cout << std::endl << "----" << std::endl;*/

            int* extra1;
            extra1 = (int*)realloc(number, (calc + 1) * sizeof(int));
                    if( !extra1 ){
                        std::cout<<("Error! Cannot allocate memory.\n")<<"\n";
                        exit(-2);
                    }
            number = extra1;
            //number = (int*)realloc(number, (calc + 1) * sizeof(int));

          sort_string[num] = str;
          sort_num[num] = num;
          number[calc] = num;

          calc++;
          last_n_s = num;
        }
        else if (num < last_n_s) {
          sort_num[num] = num;
          sort_string[num] = str;
          calc++;
            
            int* extra1;
            extra1 = (int*)realloc(number, (calc) * sizeof(int));
                    if( !extra1 ){
                        std::cout<<("Error! Cannot allocate memory.\n")<<"\n";
                        exit(-2);
                    }
            number = extra1;
         // number = (int*)realloc(number, (calc) * sizeof(int));
          number[calc - 1] = num;
        }
      }
    void QUEUE::print (){
        for (int i=0; i<last_n_s+1; i++){
            std::cout << sort_num[i] << "   " << sort_string [i] << "\n";
        }
    }
    void QUEUE::pr (){
        for (int i=0; i<calc; i++){
            std::cout << number[i] << "   " ;
        }
        std::cout <<"\n";
    }
    
    int QUEUE::return_first_n (){
        return sort_num[last_n_s];
    }
    
    int QUEUE::return_max_last_num (){
        return last_n_s;
    }
    
    std::string QUEUE::copy_and_del (){
        
        if (calc==0) {
            std::cout <<"Empty Lenght" << "\n";
            exit (-1);
        }
        std::string str;
        str = sort_string [number[0]];
        std::cout << str<< "\n";
        
        sort_num[number[0]]=-1;
        sort_string[number[0]]="";
        for (int i=0; i<calc-1; i++){
            std::swap (number[i], number [i+1]);
        }
        int* extra1;
        extra1 = (int*)realloc(number, (calc - 1) * sizeof(int));
                if( !extra1 ){
                    std::cout<<("Error! Cannot allocate memory.\n")<<"\n";
                    exit(-2);
                }
        number = extra1;
        //number = (int*)realloc(number, (calc-1)*sizeof(int));

        calc--;
        print();
        pr();
        return str;
    }
    
    void QUEUE::all_pr (){
        if (calc==0) {
            std::cout <<"error! enter the set"<<"\n";
            return;
            
        }
        for (int i=0; i<last_n_s+1; i++){
            if (sort_num[i]!=-1){
            std::cout << sort_num[i] << "   " << sort_string [i] << "\n";
            }
        }
    }
    
    std::pair<int, int> QUEUE::calc_l_and_size () {
        std::pair<int, int> answer;
        answer.first = 0;
        answer.second = 0;
        for(int i=0; i<last_n_s+1; i++){
            if (sort_num[i]==-1) break;
            if (sort_num[i]!=-1) {
                answer.first=answer.first+ sort_string[i].size();
                answer.second++;
            }
            }
        return answer;
    }

QUEUE::~QUEUE () {
    delete [] sort_num;
    delete [] sort_string;
    delete [] number;
}
