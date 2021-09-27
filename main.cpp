#include "head.hpp"
#include "AT.hpp"

int main() {
  QUEUE q;
    
    if (!AutoTest()) {
        std::cout << "Autotests failed!\n";
        return 0;
    }
    else {
        std::cout << "Input 1 to add the string" << std::endl;
        std::cout << "Input 2 to calc lenght and size" << std::endl;
        
        std::cout << "Input 3 to copy and del" << std::endl;
        std::cout << "Input 4 to have a first string number" << std::endl;
        std::cout << "Input 5 to have a max add number" << std::endl;
        std::cout << "Input 6 to print all" << std::endl;
        std::cout << "Input 0 to end" << std::endl;
        
        
        
        while(1){
            std::cout << "Input the command" << std::endl;
            int enter;
            std::cin >> enter;
            
            if (enter!=0 && enter != 1 && enter != 2 && enter != 3 && enter != 4 && enter != 5 && enter != 6) {
                std::cout <<"Error! Unknown command!!!" << std::endl;
                continue;
            }
            if(enter == 0) break;
            else if(enter == 1){
                std::string str;
                int num;
                std::cout <<"input number and string"<<"\n" ;
                std::cin >> num >> str;
                if (num<0) {
                    std::cout << "Error! Not integer number!";
                    continue;
                }
                q.add_string(num, str);
                //q.print();
                
            }
            else if(enter == 2){
                std::cout << q.calc_l_and_size().first<<", "<<q.calc_l_and_size().second <<"\n";
            }
            else if(enter == 3){
                q.copy_and_del();
                //q.pr();
                //q.print();
            }
            else if(enter == 4){
                std::cout << q.return_first_n() <<"\n";
            }
            else if(enter == 5){
                std::cout << q.return_max_last_num() <<"\n";
            }
            else if(enter == 6){
                q.all_pr();
                q.pr();
            }
        }
    }
    return 0;
}

