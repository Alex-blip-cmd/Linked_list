//
// Created by pimen on 27.10.2026.
//

#include "sim.h"

double Istberechnung(double soll, double ist, double buffer, bool anstieg) {
    if (ist<soll-buffer) {
        return ist+0.2;
    }else {
        if (ist<soll+buffer&&anstieg) {
            return ist+0.2;
        }else {
            return ist-0.2;
        }
    }
}