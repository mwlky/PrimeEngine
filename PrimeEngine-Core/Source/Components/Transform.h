#ifndef PRIMEENGINE_TRANSFORM_H
#define PRIMEENGINE_TRANSFORM_H

#include "ECS.h"
#include "../Math/Vector2.h"

namespace Prime{

    class Transform : public Component{

    public:
        Transform(){
            position = Vector2().Zero();
            scale = (*new Vector2(1,1));
        }

        Transform(Vector2 position){
            this->position = position;
            scale = (*new Vector2(1,1));
        }

        Transform(Vector2 position, Vector2 scale){
            this->position = position;
            this->scale = scale;
        }

        Vector2 position;
        Vector2 scale;
    };

}

#endif //PRIMEENGINE_TRANSFORM_H
