#include "PrimeEngine.h"

namespace Prime {

    void PrimeEngine::StartTicking(void (*tick)(float)) {

        float deltaTime = 0;

        while (true){
            tick(deltaTime);
        }
    }
} // Prime