#include "zNotepad.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    zNotepad w;
    w.show();
    return a.exec();
}
