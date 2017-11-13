/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LINE.cpp
 * Author: Dustin
 * 
 * Created on 9. November 2017, 13:05
 */


#include "LINE.h"
#include "POINT.h"
#include <math.h>

LINE::LINE() {}
LINE::LINE(const LINE& orig) {}
LINE::~LINE() {}



LINE::LINE(double X1, double Y1, double X2, double Y2){
    this->A= X1-X2;           //P1.X - P2.X [x]
    this->B= Y1-Y2;           //P1.Y -P2.Y  [y]
    this->C= Y2 - (this->A/this->B) * X2; // P2.Y-(A/B)*P2.X [y-achsen-Abschnitt]
    normalize();
}

LINE::LINE(POINT *P1, POINT *P2){
    //Formel: x= P1 + C*P2
    this->A= P1->getX()-(P2->getX()); //P1.X - P2.X [x]
    this->B= P1->getY()-(P2->getY()); //P1.Y -P2.Y  [y]
    this->C= P2->getY() - (this->A/this->B) * P2->getX(); // P2.Y-(A/B)*P2.X [y-achsen-Abschnitt]
    normalize();
}

POINT LINE :: meets (LINE* L){ //meets
    /*y=mx+b
     * m = P1-P2 (Vektoren) = PE (Ergebnis Vektor) -> y/x = Steigung
     * b = Y2-m*X2 = y-achsen Abschnitt
     * 
     * Sei "Ax+b" die Geradengleichung der this LINIE
     * und "Cx+d" die Geradengleichung der L LINIE
     * So ist die Aufgelöste gleichung der beiden [Ax+b=Cx+d]
     * der Schnittpunkt der Geraden -> x=(d-b)/(A-C)
    */
    
    double x,y,A,C,b,d; //x=(d-b)/(A-C) y=A*x+b
    
    //Ax+b
    A= this->B/this->A; //A=y:x
    b= this->C;
    
    //Cx+d
    C= L->B/L->B;       //C=y:x
    d= L->C;
    
    x=(d-b)/(A-C);
    y=A*x+b;

    return (*new POINT(x,y));
}

LINE::parallelTo(LINE* L){
    if((A/B)==(L->A/L->B)){
        return 1; //geraden sind Parallel
    }
    return 0;
}

LINE::normalize(){
    this->A = A/sqrt(pow(A,2)+pow(B,2));
    this->B = B/sqrt(pow(A,2)+pow(B,2));
    this->C = C/sqrt(pow(A,2)+pow(B,2));
}
