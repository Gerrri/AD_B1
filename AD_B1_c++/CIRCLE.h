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
    
    
private:
    POINT *Middle;
};

#endif /* CIRCLE_H */

