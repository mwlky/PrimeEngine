#ifndef PRIMEENGINE_TRANSFORM_H
#define PRIMEENGINE_TRANSFORM_H

#include "ECS.h"
#include "../Math/Vector2.h"
#include "Math/Clamp.h"

namespace Prime{

    class Transform : public Component{

    public:
        Vector2 Velocity;
        Vector2 Position;
        Vector2 Scale;
        
        Transform(){
            Position = Vector2().Zero();
            Scale = *new Vector2(1,1);
            Velocity = Vector2().Zero();
        }

        Transform(Vector2 position){
            this->Position = position;
            Scale = *new Vector2(1,1);
        }

        Transform(Vector2 position, Vector2 scale){
            this->Position = position;
            this->Scale = scale;
        }

        void Tick() override
        {
            Position.x += Velocity.x;
            Position.y += Velocity.y;
            
            Position.x = Prime::Math::Clamp::ClampValue(Position.x, 670 , -10);
            Position.y = Prime::Math::Clamp::ClampValue(Position.y, 670 , -10);
        }
    };

}

#endif //PRIMEENGINE_TRANSFORM_H
