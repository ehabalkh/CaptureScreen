#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScreen>
#include <QPixmap>
#include <QGuiApplication>
#include <QDir>
#include <QDateTime>
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int x;

private slots:
    void takeScreenshot();
    void showme();
    void startex();
    void setx();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
