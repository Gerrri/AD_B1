/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   POINT.cpp
 * Author: Dustin
 * 
 * Created on 9. November 2017, 09:23
 */

#include "POINT.h"
#include <iostream>
#include <math.h>
using namespace std;


POINT::POINT(double x, double y) {
    this->x = x;
    this->y = y;
    
    //cout<<"\nthis:"<<this->x<<","<<this->y<<","<<"\nxy:"<<x<<","<<y;
}

POINT::POINT(const POINT& orig) {
    this->x = orig.x;
    this->y = orig.y;
}

POINT::~POINT() {
}

bool POINT::equalTo(POINT in_point){
    // wenn gleich return 0 ... wenn ungleich return 1
    if(this->x==in_point.x && this->y==in_point.y){return true;}
    else{return false;}        
}

double POINT::distanceTo(POINT in_point){
    //Distanz zwischen zwei Punkten
    double d,temp;
    temp = pow(this->x - in_point.x,2) + pow(this->y -in_point.y,2); // FORMEL : (x1 - x2)^2 + (y1 - y2)^2 
    d = sqrt(temp); // Wurzel von temp
    d = fabs(d); //Betrag von d
    return d;
}

double POINT::getX() {
    return this->x;
}

double POINT::getY() {
    return this->y;
}

void POINT::setX(double dx) {
    this->x = dx;
}

void POINT::setY(double dy) {
    this->y = dy;
}

double POINT::getBetrag(){
   double Betrag;
   
   Betrag = sqrt(pow(this->x,2)+pow(this->y,2));
   return Betrag;
}

double POINT :: Skalarprodukt(POINT *b) {
    double k;
    
    //a1*b1 + a2*b2 -> Skalarprodukt
    k = (this->x * b->getX()) + (this->y * b->getY());
    
    
    //cout<<"k: "<<k <<this->x<<"*"<<b->getX()<<"+"<<this->y<<"*"<<b->getY();
    return k;
}

POINT POINT::Addition(POINT b) {
    double x,y; 
        x = this->x+b.x;
        y = this->y+b.y;

    return *(new POINT(x,y));
}

POINT POINT::Scale(double a) {
   double x,y;
        x = this->x*a;
        y = this->y*a;
        
   return *(new POINT(x,y));
}



