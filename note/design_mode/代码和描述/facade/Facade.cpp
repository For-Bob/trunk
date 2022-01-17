#include "Facade.h"

Facade::Facade()
    : m_assPointer(new  Assemble())
    ,m_prePointer(new Preprocessing())
    ,m_comPointer(new Compilation())
    ,m_linkPointer(new Linking())
{
    cout << " the device is construct" << endl;
}

Facade::~Facade(){
    cout << " the device is desconstruct" << endl;
}

void Facade::generateBinaryFile(string file){
    string fileName = "";
    size_t f = file.find(".");
    cout << "current pos: " << f << endl;
    fileName = file.substr(0, f);
    m_prePointer->run(fileName);
    m_comPointer->run(fileName);
    m_assPointer->run(fileName);
    m_linkPointer->run(fileName);
}
