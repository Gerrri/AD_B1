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

int main(int argc, char** argv) {
    POINT *A, *B, *C;
    double X,Y;
    

    // AUFGABE 1 -> Einlesen der Punkte A,B,C 
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
    
    // Aufgabe 2 Abbrechn fals Punkte Doppelt
    // Vergleichen von A/B A/C C/B (einzelne Attribute)
    if(A->equalTo(*B) || B->equalTo(*C) || C->equalTo(*B)){
        cout<<"\nFehler [mind. 2 mal der Gleiche Punkt]- Bitte starten Sie das Programm Neu!";
        return 0;
    }
    
    // Aufgabe 3 Konstruieren von Hilfskreisen um Punkte A,B,C sodass sich 2 Kreise schneiden
    // hilfskreis A/B A/C C/B mir Methode "hilfskreis"
    CIRCLE AB_hkreis = hilfskreis(*A,*B);
    CIRCLE BA_hkreis = hilfskreis(*B,*A);
    CIRCLE BC_hkreis = hilfskreis(*B,*C);
    CIRCLE CB_hkreis = hilfskreis(*C,*B);
    
    
    // A4
    // Geraden (von schnittpunkten)ermitteln A/B B/C
    LINE AB_schnitt_gerade = A_hkreis.intersects(*B);
    LINE BC_schnitt_gerade = B_hkreis.intersects(*C);
    
    
    
 
 
    
    
    

    
    return 0;
}

//Hilfskreis Funktion
CIRCLE hilfskreis(POINT A, POINT B){
    double d,R,R_final;
    d = A.distanceTo(*B); 
    R = d/2; // Radius damit sich die Kreise berühren
    R_final = R+(R/10000); // Radius ein wenig vergrößert damit sich die Kreise schneiden
        
    CIRCLE a = new CIRCLE(A,R_final);
    return (a);
}
