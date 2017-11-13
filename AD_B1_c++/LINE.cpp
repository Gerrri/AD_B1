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

LINE::LINE() {}
LINE::LINE(const LINE& orig) {}
LINE::~LINE() {}



LINE::LINE(double X1, double Y1, double X2, double Y2){
    A= X1-X2;           //P1.X - P2.X [x]
    B= Y1-Y2;           //P1.Y -P2.Y  [y]
    C= Y2 - (A/B) * X2; // P2.Y-(A/B)*P2.X [y-achsen-Abschnitt]
}

LINE::LINE(POINT* P1, POINT* P2){
    //Formel: x= P1 + C*P2
    A= P1->getX()-(P2->getX()); //P1.X - P2.X [x]
    B= P1->getY()-(P2->getY()); //P1.Y -P2.Y  [y]
    C= P2->getY() - (A/B) * P2->getX(); // P2.Y-(A/B)*P2.X [y-achsen-Abschnitt]
}

LINE::*meets(LINE* L){
    //Todo
}

LINE::parallelTo(LINE* L){
    //Todo
}

LINE::normalize(){
    //Todo
}
