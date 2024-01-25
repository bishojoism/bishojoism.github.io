#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_copyTop_clicked();

    void on_copyBottom_clicked();

    void on_pasteTop_clicked();

    void on_pasteBottom_clicked();

    void on_clearTop_clicked();

    void on_clearBottom_clicked();

private:
    Ui::MainWindow *ui;

    void connectTop();
    void connectBottom();
};
#endif // MAINWINDOW_H
