#include "camera.hpp"

void EngineCamera::Update(){
    forward = {cosf(angle), sinf(angle)};
    right = {sinf(angle), -cosf(angle)};
}

void EngineCamera::Rotate(float d_a){
    angle += d_a;
    Update();
}

void EngineCamera::SetPosition(vector2f new_pos){
    position = new_pos;
}

vector2f EngineCamera::GetPosition(){
    return position;
}

void EngineCamera::MoveForward(float velocity){
    position = position + (forward * velocity);
}

void EngineCamera::MoveRight(float velocity){
    position = position + (right * velocity);
}
