
#include "PrimeEngine.h"

namespace Prime {

    void PrimeEngine::StartTicking(void (*tick)(float)) {
        double frameTime;

        while (true){
            tick(frameTime);
        }
    }

    PrimeEngine::PrimeEngine() {

    }
} // Prime