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
#include "LINE.h"
#include "POINT.h"
#include "CIRCLE.h"
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    POINT *A, *B, *C;
    double X,Y;
    
    //Todo
    
    cout<<"Bitte x y für A eingeben: \n";
    cout<<"x: ";
    cin>>X;
    cout<<"y: ";
    cin>>Y;
    A=new POINT (X,Y);
    
    cout<<"Bitte x y für B eingeben: \n";
    cout<<"x: ";
    cin>>X;
    cout<<"y: ";
    cin>>Y;
    B=new POINT (X,Y);
    
    cout<<"Bitte x y für C eingeben: \n";
    cout<<"x: ";
    cin>>X;
    cout<<"y: ";
    cin>>Y;
    C=new POINT (X,Y);
    
    cout<<"\nPunkte A,B,C: \n";
    cout<<"A :"<<A->getX()<<"/"<<A->getY()<<"\n";
    cout<<"B :"<<B->getX()<<"/"<<B->getY()<<"\n";
    cout<<"C :"<<C->getX()<<"/"<<C->getY()<<"\n";
    
    // Vergleichen von A/B A/C C/B (einzelne Attribute)
    if(A->equalTo(*B) || B->equalTo(*C) || C->equalTo(*B)){
        cout<<"\nFehler [mind. 2 mal der Gleiche Punkt]- Bitte starten Sie das Programm Neu!";
        return 0;
    }
    

    
    return 0;
}

