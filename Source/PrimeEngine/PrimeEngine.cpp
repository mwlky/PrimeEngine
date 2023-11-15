
#include "PrimeEngine.h"

namespace Prime {

    PrimeEngine::PrimeEngine() {

    }

    void PrimeEngine::StartTicking(void (*tick)(float)) {

        while (true){
            tick(0);

            if(m_Window != nullptr){
                m_Window->RenderWindow();
            }
        }
    }

    void PrimeEngine::CreateWindow(const char *title, int xPos, int yPos, int width, int height) {
        m_Window = new Window(title, xPos, yPos, width, height);
    }
} // Prime