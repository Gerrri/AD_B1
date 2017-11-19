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
    this->A = Y1 - Y2;
    this->B = X2 - X1;
    this->C = X1 * Y2 - (X2 * Y1);
    normalize();
}

LINE::LINE(POINT *P1, POINT *P2){
    this->A = P1->getY() - P2->getY(); //Y1-Y2;
    this->B = P2->getX() - P1->getX(); //X2-X1;
    this->C = P1->getX() * P2->getY()-(P2->getX() * P1->getY()); //X1*Y2-(X2*Y1);
   normalize();
}

POINT LINE :: meets (LINE* L){ //meets
        double A1, B1, C1, A2, B2, C2, x3, y3;
        
        A1 = this->A;
        B1 = this->B;
        C1 = this->C;
        A2 = L->getA();
        B2 = L->getB();
        C2 = L->getC();

        x3 = (B2 * C1 - (C2 * B1)) / (A2 * B1 - (A1 * B2));
        y3 = (C2 * A1 - (A2 * C1)) / (A2 * B1 - (A1 * B2));

        return (*new POINT(x3, y3));
}

LINE::parallelTo(LINE* L){
    if((A/B)==(L->A/L->B)){
        return 1; //geraden sind Parallel
    }
    return 0;
}

LINE::normalize(){
    this->A = this->A/sqrt(pow(this->A,2)+pow(this->B,2));
    this->B = this->B/sqrt(pow(this->A,2)+pow(this->B,2));
    this->C = this->C/sqrt(pow(this->A,2)+pow(this->B,2));
}
