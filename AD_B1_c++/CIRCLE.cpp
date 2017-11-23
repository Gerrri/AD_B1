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







