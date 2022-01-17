#include <memory>
#include "adapter.h"

using namespace std;

int main(int argc, char *argv[])
{
    shared_ptr <Target> pointer = make_shared <Adapter>();
    pointer->request();
    return 0;
}
