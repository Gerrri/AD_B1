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
#include "LINE.h"
#include "POINT.h"
#include <math.h>

using namespace std;

CIRCLE::CIRCLE() {}
CIRCLE::CIRCLE(const CIRCLE& orig) {}
CIRCLE::~CIRCLE() {}

CIRCLE::CIRCLE(POINT* M, double R){ // ACHTUNG KOPIE VON M ERSTELLEN warum - sonst wird referenziertes Objekt veändert?!?!
    //Erstelle Kreis um Punkt(POINT M) mit Radius R
    POINT *punkt_m= new POINT(M->getX(),M->getY()); 
    //*punkt_m.setX(*M->getX());    //M(x) Kopieren
    //*punkt_m.setY(*M->getY());      //M(y) Kopieren
    this->Middle = new POINT (*punkt_m);
    
    //DEBUGG::STARTE
    //cout<<"\nMID :"<<this->Middle->getX()<<","<<this->Middle->getY()<<"\npunkt_m :"<<punkt_m->getX()<<","<<punkt_m->getY();
    //DEBUGG::ENDE
    
    this->Radius = R;
    this->umfang = M_PI*2*R;
    this->flaeche = M_PI*pow(R,2);
    
    delete punkt_m;
    
}

CIRCLE::CIRCLE(double X, double Y, double R){
    //Erstelle Kreis um Punkt (X/Y) mit Radius R
    POINT* punkt_m= new POINT(X,Y);
    this->Middle = new POINT(*punkt_m);
    //this->Middle->setX(X);
    //this->Middle->setY(Y);
    this->Radius = R;
    this->umfang = M_PI*2*R;
    this->flaeche = M_PI*pow(R,2);
}

LINE *CIRCLE::intersects(CIRCLE* C) {
   
    POINT *s1 = new POINT   (2 * (this->Middle->getX() - C->Middle->getX()) , 
                            (2 * (this->Middle->getY() - C->Middle->getY())));
    
    POINT *s2 = new POINT   (s1->getY(), -s1->getX()); // senkrecht zu s1
    
    double c =  ((C->Middle->Skalarprodukt(C->Middle)) - (this->Middle->Skalarprodukt(this->Middle)))
                - ((C->Radius*C->Radius)-(this->Radius*this->Radius));

    
    double s    =   -c / (s1->getBetrag()*s1->getBetrag());
    double p_h  =   (s2->Skalarprodukt(this->Middle) / s1->getBetrag() * this->Radius);
    double q    =   pow(c,2) / pow(s1->getBetrag(),4) + 2*c*s1->Skalarprodukt(this->Middle) /
                    pow(s1->getBetrag(),4) + (this->Middle->Skalarprodukt(this->Middle)-this->Radius*this->Radius) /
                    (s1->getBetrag()*s1->getBetrag());
    
    double sqrtVal = sqrt(pow(p_h,2) - q);
    double d1 = p_h - sqrtVal;
    double d2 = p_h + sqrtVal;
    
    
    
    POINT p1 = (s1->Scale(s)).Addition((s2->Scale(d1)));
    POINT p2 = (s1->Scale(s)).Addition((s2->Scale(d2)));
    
    
    
    //delete s1;
    //delete s2;
    
    return (new LINE (&p1, &p2));
}   
/*
  POINT *A_p = this->Middle;           //Mittelpunkt this
  POINT *B_p = C->getMiddle();         //Mittelpunkt C
  double a  = this->Radius;           //Rad Kreis this
  double b  = C->getRadius();         //Rad Kreis C
  double c  = A_p->distanceTo(*B_p);   //Abstand a,b
  double x,y;                         //zwischenspeicher
  double Ax=A_p->getX();               //x von A
  double Bx=B_p->getX();               //x von B
  double Ay=A_p->getY();               //y von A
  double By=B_p->getY();               //y von B
  double Q1_x,Q2_x,Q1_y,Q2_y;
    

   
    
  x=(pow(a,2)+pow(c,2)-pow(b,2))/2*c; //Kreisformel und Pythagoras kombiniert
  y=sqrt(pow(a,2)+pow(x,2));          //Pythagoras (einsetzen)
    
  // berechnung Q1(x)
  Q1_x    = Ax    +   x*  ((Bx-Ax)/c)   -   y*    ((By-Ay)/c);
    
  // berechnung Q2(x)
  Q2_x    = Ax    +   x*  ((Bx-Ax)/c)   +   y*    ((By-Ay)/c);
    
  // berechnung Q1(y)
  Q1_y    = Ay    +   x*  ((By-Ay)/c)   +   y*    ((Bx-Ax)/c);
 
  // berechnung Q2(y)
  Q2_y    = Ay    +   x*  ((By-Ay)/c)   -   y*    ((Bx-Ax)/c);
 
    
  POINT* Q1 = new POINT(Q1_x,Q1_y); //Schnittpunkt 1
  POINT* Q2 = new POINT(Q2_x,Q2_y); //Schnittpunkt 2
    
    
  LINE *ret_line = new LINE(Q1,Q2);
  return ret_line;
   
}
 */






