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
    CIRCLE* hilfskreis(POINT *A, POINT *B);
    
    LINE *eins = new LINE (1,1,3,3);
    LINE *zwei = new LINE (3,1,1,3);
    
    POINT *schnitt = new POINT (eins->meets(zwei));
    
    cout<<"Schnittpunkt : ("<<schnitt->getX()<<"/"<<schnitt->getY()<<")";
  

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
    // hilfskreis A/B B/A B/C C/B mit Methode "hilfskreis"
    
    
    CIRCLE *AB_hkreis = hilfskreis(A,B);//hilfskreis(*A,*B);
    CIRCLE *BA_hkreis = hilfskreis(B,A);
    CIRCLE *BC_hkreis = hilfskreis(B,C);    
    CIRCLE *CB_hkreis = hilfskreis(C,B);
   
    // A4
    // Geraden (von schnittpunkten)ermitteln A/B B/C
    LINE *AB_schnitt_gerade = AB_hkreis->intersects(BA_hkreis); //gerade durch schnittpunkt A/B - B/A
    LINE *BC_schnitt_gerade = BC_hkreis->intersects(CB_hkreis); //gerade durch schnittpunkt B/C - C/B
    
   
    if(AB_schnitt_gerade->parallelTo(BC_schnitt_gerade)==1){ //Abbruch wenn geraden paralle sind
        cout<<"\nFehler [die Geraden sind Parallel]- Bitte starten Sie das Programm Neu!";
        return 0;
    }
    

    POINT *Mitte_Kreis_neu = new POINT(AB_schnitt_gerade->meets(BC_schnitt_gerade).getX(),AB_schnitt_gerade->meets(BC_schnitt_gerade).getY()); // neuer Punkt -> Schnittpunkt der beiden geraden
    double Radius_Kreis_neu = Mitte_Kreis_neu->distanceTo(*A);            // neuer Radius -> Radius = Abstand neuer Punkt zu einem der Ausgangspunkte
    
    CIRCLE *Kreis_neu = new CIRCLE(Mitte_Kreis_neu,Radius_Kreis_neu);    // Neuer Kreis auf dem sich alle Drei Punkte Befinden
    
    
    //Ausgabe
    cout<<"Daten vom Generierten Kreis: ";
    cout<<"Mittelpuntk bei : "<<Kreis_neu->getMiddle()->getX()<<"/"<<Kreis_neu->getMiddle()->getY()<<"\n";
    cout<<"Radius bei : "<<Kreis_neu->getRadius()<<"\n";
 
    /* Zum Werte Prüfen einkommentieren !
    cout<<"\n\n Übersicht der Werte:\n";
    cout<<"Hilfskreis AB : Punkt :  ("<<AB_hkreis->getMiddle()->getX()<<","<<AB_hkreis->getMiddle()->getY()<<") || Radius: "<<AB_hkreis->getRadius()<<"\n";
    cout<<"Hilfskreis BA : Punkt :  ("<<BA_hkreis->getMiddle()->getX()<<","<<BA_hkreis->getMiddle()->getY()<<") || Radius: "<<BA_hkreis->getRadius()<<"\n";
    cout<<"Hilfskreis BC : Punkt :  ("<<BC_hkreis->getMiddle()->getX()<<","<<BC_hkreis->getMiddle()->getY()<<") || Radius: "<<BC_hkreis->getRadius()<<"\n";
    cout<<"Hilfskreis CB : Punkt :  ("<<CB_hkreis->getMiddle()->getX()<<","<<CB_hkreis->getMiddle()->getY()<<") || Radius: "<<CB_hkreis->getRadius()<<"\n";
    cout<<"\n";
    cout<<"Linie      AB : Punkt :("<<AB_schnitt_gerade->getA()<<","<<AB_schnitt_gerade->getB()<<") || Steigung : "<<AB_schnitt_gerade->getC()<<"\n";
    cout<<"Linie      BC : Punkt :("<<BC_schnitt_gerade->getA()<<","<<BC_schnitt_gerade->getB()<<") || Steigung : "<<BC_schnitt_gerade->getC()<<"\n";    
    */
    
    return 0;
}

//Hilfskreis Funktion
CIRCLE* hilfskreis(POINT *X, POINT *Y){
    double d,R,R_final;
    d = X->distanceTo(*Y); 
    R = d/2; // Radius damit sich die Kreise berühren
    R_final = R+(R/2); // Radius ein wenig vergrößert damit sich die Kreise schneiden
        
    CIRCLE* a = new CIRCLE(X,R_final);
    
    //delete X;
    //delete Y;
   
    return (a);
}
