/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Dustin
 *
 * Created on 9. November 2017, 09:13
 */

#include <cstdlib>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    POINT *A, *B, *C;
    double X,Y;
    
    //Todo
    
    cout<<"Bitte x y für A eingeben: ";
    cin>>X>>Y;
    A=new POINT (X,Y);
    
    return 0;
}

