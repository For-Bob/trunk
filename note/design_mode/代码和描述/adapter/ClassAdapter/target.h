#ifndef TARGET_H
#define TARGET_H

class Target
{
public:
    Target();
    virtual ~Target();
    virtual void request() = 0;
};

#endif // TARGET_H
