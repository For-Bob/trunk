#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "ConcreteCake.h"
#include "mikeDecoratorCake.h"
#include "orangeDecoratorCake.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    shared_ptr<Cake> pcake = make_shared<ConcreteCake>();
    pcake->showCake();

    mikeDecoratorCake *mikeCake = new mikeDecoratorCake(pcake.get());
    mikeCake->showCake();

    orangeDecoratorCake *orangeCake = new orangeDecoratorCake(pcake.get());
    orangeCake->showCake();

    return app.exec();
}
