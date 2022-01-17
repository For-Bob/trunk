#ifndef HANDLDER_H
#define HANDLDER_H

class Handlder
{
public:
    enum{
      levelOne = 5,
      levelTwo = 10,
      levelThree = 20
    };
public:
    Handlder();
    virtual ~Handlder(){}
    virtual void setNextHandler(Handlder *hdl) = 0;
    virtual void handleNextRequst(int& index) = 0;
private:

};

#endif // HANDLDER_H
