#ifndef ZNOTEPAD_H
#define ZNOTEPAD_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>



QT_BEGIN_NAMESPACE
namespace Ui { class zNotepad; }
QT_END_NAMESPACE

class zNotepad : public QMainWindow
{
    Q_OBJECT

public:
    zNotepad(QWidget *parent = nullptr);
    ~zNotepad();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_As_triggered();

    void on_actionSave_triggered();

    void on_actionprint_triggered();

    void on_actionExit_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

private:
    Ui::zNotepad *ui;
    QString currentFile = "";
};
#endif // ZNOTEPAD_H
