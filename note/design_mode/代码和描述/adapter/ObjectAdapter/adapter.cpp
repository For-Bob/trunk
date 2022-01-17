#include "adapter.h"

Adapter::Adapter()
{
    pointer = std::make_shared <Adaptee>();
}

Adapter::~Adapter(){

}

void Adapter::request(){
    pointer->specifyRequest();
}
