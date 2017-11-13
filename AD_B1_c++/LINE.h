/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LINE.h
 * Author: Dustin
 *
 * Created on 9. November 2017, 13:05
 */

#ifndef LINE_H
#define LINE_H
#include "POINT.h"



class LINE {
public:
    LINE();
    LINE(const LINE& orig);
    virtual ~LINE();
    

    LINE(double X1, double Y1, double X2, double Y2);
    LINE(POINT *P1, POINT *P2);
    
    POINT meets (LINE *L);
    int parallelTo(LINE *L);
    
    double getA() const {return A;}
    double getB() const {return B;}
    double getC() const {return C;}
    
    void setA(double A) {this->A = A;}
    void setB(double B) {this->B = B;}
    void setC(double C) {this->C = C;}
    
private:
    double A;
    double B;
    double C;
    
   // POINT A_oL;
   // POINT B_oL;
    normalize(void);
};

#endif /* LINE_H */

