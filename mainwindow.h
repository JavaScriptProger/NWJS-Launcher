#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

     QString cmd;
     QString nw, prj;
     QString cnfPath;
private slots:
    void on_select_clicked();

    void on_run_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
