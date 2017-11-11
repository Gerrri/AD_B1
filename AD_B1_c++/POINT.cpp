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


POINT::POINT(const double x, const double y) {
    this->x = x;
    this->y = y;
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
    
}


