#include <QApplication>
#include "player1.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    Player1 a;
    a.show();
    return app.exec();
}
