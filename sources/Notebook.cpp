#include "Notebook.hpp"
#include <unordered_map>
#include <iostream>
#include <stdexcept>
#include <algorithm>  
#include <string> 

using namespace std;
using namespace ariel;
const int max_col= 100; 



// This function check that the string we want to write has proper chars 
 bool Notebook::check_input (string const &in){

    if(in.find('~')!= std::string::npos){
         return false; 
     }
     for (char c: in)
     {
         // check if we can print each char in the string
         if (std::isprint(c) ==0)
         {
         return false; 
         }
         
     } 
      
    return true; 
}

// This function check if the place we want to write to is empty  
bool Notebook::check_space( int page,  int row,  int col, Direction dir, string const &in){
    for (int i = 0; i < in.length(); i++){
        if(dir== Direction:: Horizontal){
            if(notebook[page][row].data[(unsigned long)col] != '_' || notebook[page][row].data[(unsigned long)col] == '~' ){ 
                return false; 
                }
                col++; 
        }
        else{
            if(notebook[page][row].data[(unsigned long)col] != '_' || notebook[page][row].data[(unsigned long)col] == '~' ){ 
                return false; 
                }
                row++; 
        }
}
return true;
}

// This function write new word in the page 
void Notebook::write( int page,  int row,  int col, Direction dir, string const &in)
{

    // check worng input
    if ( !check_input(in) || (dir== Direction:: Horizontal && (int)in.length()+col >= max_col) || col>= max_col || row<0 || col<0 || page <0 )
    {
        throw invalid_argument("Worng input, Please try again!");   
    }
    //check that the p\lace we want to write to is empty
    if ( !check_space(page,row,col,dir,in))
    {
        throw invalid_argument("There is another word that written here");
    }

    for (size_t i = 0; i < in.length(); i++){
        if(dir== Direction:: Horizontal){
                notebook[page][row].data[(size_t)col]= in[i]; 
                col++;
                } 
            
        else if (dir== Direction:: Vertical){
                notebook[page][row].data[(size_t)col]= in[i];
                row++;
                }
             
            }
    
}  
 // This function erase a word from the page    
void Notebook::erase( int page,  int row,  int col, Direction dir, int length){
    //check correct input
    if ((dir== Direction:: Horizontal && length+col >= max_col) || col>= max_col || row<0 || col<0 || page <0 || length<0)
    {
        throw invalid_argument("Worng input, Please try again!");   
    }

        for (int i = 0; i < length; i++){
            if(dir== Direction:: Horizontal){
                    notebook[(unsigned long)page][(unsigned long)row].data[(unsigned long)col]= '~'; 
                    col++;
                }       
            else if (dir== Direction:: Vertical){
                    notebook[(unsigned long)page][(unsigned long)row].data[(unsigned long)col]= '~';
                    row++;
            }         
            }
}

// This function reads a word from the page 
string Notebook::read( int page,  int row,  int col, Direction dir, int length){

    if ((dir== Direction:: Horizontal && length+col > max_col) || col>= max_col || row<0 || col<0 || page <0 || length<0)
    {
        throw invalid_argument("Worng input, Please try again!");   
    }
    string ans;
    for (int i = 0; i < length; i++)
    {
     ans+= notebook[page][row].data[(size_t)col];
     if (dir== Direction:: Horizontal){
         col++;
     }
        if (dir== Direction:: Vertical){
        row++; 
    }      
    }
    return ans; 

}

//This function show the whole page is given 
void Notebook::show(int page){
    int t=0; 
    if (page <0){
         throw invalid_argument("Page number must be positive!");
    }
    //go throw the page- k.first is row number, k.second is the string that written in the row(all the cols) 
    for(auto const &k: notebook[page]){
        //print empty rows 
        while (t<k.first)
        {
            cout<< t <<" " << string(max_col,'_') << endl; 
            t++; 
        }       
        cout << k.first << " " << k.second.data <<endl;
    }

    
}

        