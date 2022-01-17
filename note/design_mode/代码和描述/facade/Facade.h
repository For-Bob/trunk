#ifndef FACADE_H
#define FACADE_H

#include <memory>

#include "assemble.h"
#include "compilation.h"
#include "preprocessing.h"
#include "linking.h"

class Facade
{
public:
    Facade();
    ~Facade();
    void generateBinaryFile(string file);

private:
    shared_ptr<Assemble> m_assPointer;
    shared_ptr<Preprocessing> m_prePointer;
    shared_ptr<Compilation> m_comPointer;
    shared_ptr<Linking> m_linkPointer;

};

#endif // FACADE_H
