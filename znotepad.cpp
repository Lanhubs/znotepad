#include "zNotepad.h"
#include "ui_znotepad.h"

zNotepad::zNotepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::zNotepad)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);

}

zNotepad::~zNotepad()
{
    delete ui;
}


void zNotepad::on_actionNew_triggered()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
}


void zNotepad::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "open file");
    QFile file(filename);
    currentFile = filename;

    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "warning", "unable to open file", file.errorString());
        return;
    }
    setWindowTitle(filename);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void zNotepad::on_actionSave_As_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save As");
    QFile file(filename);
    currentFile = filename;

    if(!file.open(QIODevice::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "warning", "unable to open file", file.errorString());
        return;
    }
    setWindowTitle(filename);
    currentFile = filename;
    QTextStream out(&file);
    QString text = out.readAll();
    ui->textEdit->toPlainText();
    out<< text;
    file.close();
}






void zNotepad::on_actionExit_triggered()
{
    QApplication::exit();
}


void zNotepad::on_actionCut_triggered()
{
    ui->textEdit->cut();
}



void zNotepad::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void zNotepad::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void zNotepad::on_actionprint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Printer Name");
    QPrintDialog pDialog(&printer, this);
    if(pDialog.exec() == QDialog::Rejected){
        QMessageBox::warning(this, "warning", "cannot access printer");
        return;
    }
    ui->textEdit->print(&printer);
}

