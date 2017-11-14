/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   POINT.h
 * Author: Dustin
 *
 * Created on 9. November 2017, 09:23
 */

#ifndef POINT_H
#define POINT_H

class POINT {
public:
    POINT(double x, double y);
    POINT(const POINT& orig);
    virtual ~POINT();
    
    double getX();
    double getY();
    void setX(double);
    void setY(double);
    
    bool equalTo(POINT in_point);
    double distanceTo(POINT in_point);
    double getBetrag ();
    double Skalarprodukt(POINT *b);
    POINT Addition(POINT b);
    POINT Scale(double a); 

    
private:
    double x;
    double y;
};

#endif /* POINT_H */

