#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "nyastega8.h"

#include <QClipboard>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connectTop();
    connectBottom();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectTop() {
    connect(ui->textTop, &QPlainTextEdit::textChanged, this, [this]{
        ui->textBottom->disconnect();
        ui->textBottom->setPlainText(QString::fromStdWString(nyastega8::encode(ui->textTop->toPlainText().toStdString())));
        connectBottom();
    });
}

void MainWindow::connectBottom() {
    connect(ui->textBottom, &QPlainTextEdit::textChanged, this, [this]{
        ui->textTop->disconnect();
        ui->textTop->setPlainText(QString::fromStdString(nyastega8::decode(ui->textBottom->toPlainText().toStdWString())));
        connectTop();
    });
}

void MainWindow::on_copyTop_clicked()
{
    QApplication::clipboard()->setText(ui->textTop->toPlainText());
}


void MainWindow::on_copyBottom_clicked()
{
    QApplication::clipboard()->setText(ui->textBottom->toPlainText());
}


void MainWindow::on_pasteTop_clicked()
{
    ui->textTop->setPlainText(QApplication::clipboard()->text());
}

void MainWindow::on_pasteBottom_clicked()
{
    ui->textBottom->setPlainText(QApplication::clipboard()->text());
}


void MainWindow::on_clearTop_clicked()
{
    ui->textTop->clear();
}


void MainWindow::on_clearBottom_clicked()
{
    ui->textBottom->clear();
}

