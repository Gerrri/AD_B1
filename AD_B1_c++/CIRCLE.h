/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CIRCLE.h
 * Author: Dustin
 *
 * Created on 9. November 2017, 13:52
 */

#ifndef CIRCLE_H
#define CIRCLE_H
#include "LINE.h"
#include "POINT.h"


class CIRCLE {
public:
    CIRCLE();
    CIRCLE(const CIRCLE& orig);
    virtual ~CIRCLE();
    
    CIRCLE (POINT *M, double R);
    CIRCLE (double X, double Y, double R);
    
    LINE *intersects(CIRCLE *C);

    POINT* getMiddle() const {return Middle;}
    double getRadius() const {return Radius;}
    double getFlaeche() const {return flaeche;}    
    double getUmfang() const {return umfang;} 
    
    void setMiddle(POINT* Middle) {this->Middle = Middle;}
    void setRadius(double Radius) {this->Radius = Radius;}
    void setFlaeche(double flaeche) {this->flaeche = flaeche;}
    void setUmfang(double umfang) {this->umfang = umfang;}

   
private:
    POINT *Middle;
    double Radius;
    double umfang;
    double flaeche;
};

#endif /* CIRCLE_H */

