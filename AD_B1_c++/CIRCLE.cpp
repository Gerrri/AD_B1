/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CIRCLE.cpp
 * Author: Dustin
 * 
 * Created on 9. November 2017, 13:52
 */

#include "CIRCLE.h"
#include <math.h>

CIRCLE::CIRCLE() {}
CIRCLE::CIRCLE(const CIRCLE& orig) {}
CIRCLE::~CIRCLE() {}

CIRCLE::CIRCLE(POINT* M, double R){ // ACHTUNG KOPIE VON M ERSTELLEN warum?!?!
    //Erstelle Kreis um Punkt(POINT M) mit Radius R
    POINT punkt_m;
    punkt_m.setX() =M->getX();      //M(x) Kopieren
    punkt_m.setY() =M->getY();      //M(y) Kopieren
    Middle = punkt_m;
    this->Radius = R;
    this->umfang = M_PI*2*R;
    this->flaeche = M_PI*pow(R,2);
    
}

CIRCLE::CIRCLE(double X, double Y, double R){
    //Erstelle Kreis um Punkt (X/Y) mit Radius R
    this->Middle->setX() = X;
    this->Middle->setY() = Y;
    this->Radius = R;
    this->umfang = M_PI*2*R;
    this->flaeche = M_PI*pow(R,2);
}

LINE* CIRCLE::intersects(CIRCLE* C) {
    
    POINT * n1 = new POINT(
            2 * (this->Middle->getX() - C->Middle->getX()),
            2 * (this->Middle->getY() - C->Middle->getY()));
    POINT * n2 = new POINT(n1->getY(), -n1->getX()); // orthogonal to n1

    double c = (*C->Middle * *C->Middle - *this->Middle * *this->Middle) -
            (C->Radius * C->Radius - this->Radius * this->Radius);

    double s = -c / (n1->getBetrag() * n1->getBetrag()); // lambda s

    double p_half = (*n2 * *this->Middle) / (n1->getBetrag() * n1->getBetrag());
    double q = (c * c) / (n1->getBetrag() * n1->getBetrag() * n1->getBetrag() * n1->getBetrag()) +
            (2 * c * (*n1 * *this->Middle)) / (n1->getBetrag() * n1->getBetrag() * n1->getBetrag() * n1->getBetrag()) +
            (*this->Middle * *this->Middle - this->Radius * this->Radius) / (n1->getBetrag() * n1->getBetrag());

    double sqrtVal = sqrt(p_half*p_half - q);
    double d1 = p_half - sqrtVal;
    double d2 = p_half + sqrtVal;
    
    POINT s1 = *n1 * s + *n2 * d1;
    POINT s2 = *n1 * s + *n2 * d2;
    
    delete n1;
    delete n2;
    
    return new LINE(&s1, &s2);
    
    
/*    
    LINE ret_line;
    POINT A_p = this->Middle;           //Mittelpunkt this
    POINT B_p = C->getMiddle();         //Mittelpunkt C
    double a  = this->Radius;           //Rad Kreis this
    double b  = C->getRadius();         //Rad Kreis C
    double c  = A_p.distanceTo(*B_p);   //Abstand a,b
    double x,y;                         //zwischenspeicher
    double Ax=A_p.getX();               //x von A
    double Bx=B_p.getX();               //x von B
    double Ay=A_p.getY();               //y von A
    double By=B_p.getY();               //y von B
    double temp;
    
    POINT Q1; //Schnittpunkt 1
    POINT Q2; //Schnittpunkt 2
   
    
    x=(pow(a,2)+pow(c,2)-pow(b,2))/2*c; //Kreisformel und Pythagoras kombiniert
    y=sqrt(pow(a,2)-pow(x,2));          //Pythagoras (einsetzen)
    
    // berechnung Q1(x)
    temp    = Ax    +   x*  ((Bx-Ax)/c)   -   y*    ((By-Ay)/c);
    Q1.setX(temp);
    
    // berechnung Q2(x)
    temp    = Ax    +   x*  ((Bx-Ax)/c)   +   y*    ((By-Ay)/c);
    Q2.setX(temp);
    
    // berechnung Q1(y)
    temp    = Ay    +   x*  ((By-Ay)/c)   +   y*    ((Bx-Ax)/c);
    Q1.setY(temp);
   
    // berechnung Q2(y)
    temp    = Ay    +   x*  ((By-Ay)/c)   -   y*    ((Bx-Ax)/c);
    Q2.setY(temp);
    
    ret_line = new LINE(*Q1,*Q2);
    return ret_line;
 */  
}



