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

double POINT::getX() {
    return this->x;
}

double POINT::getY() {
    return this->y;
}

