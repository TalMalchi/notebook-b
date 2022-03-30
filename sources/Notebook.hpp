#include <string>
#include "Direction.hpp"
# include <unordered_map>
# include <map>

#include <stdint.h>
using namespace std;
using ariel::Direction;


namespace ariel{
    
    //each row in the page will have 100 col, that will init by '_'
    struct data{ 
      string data = string(100,'_') ; 
    }; 

    class Notebook{
         
        private: 
         //<pageNumber<row, data>>
            unordered_map < int,map< int, data>> notebook; 
            // unsigned int min_col= 0;
            // unsigned int min_row=0;
            // unsigned int max_row= INT8_MAX;
            //unsigned int max_col= 100; 
          
          public:

            Notebook(){} //constructor 

            void write( int page, int row, int col, Direction dir , string const &in);
            void erase( int page, int row, int col, Direction dir , int length); 
            string read( int page, int row, int col, Direction dir , int length);
             void show( int page);
            static bool check_input (string const &in); 
            bool check_space( int page,  int row,  int col, Direction dir, string const &in);
            
    
            ~Notebook(){} // distructor 
};

    }

    
  



