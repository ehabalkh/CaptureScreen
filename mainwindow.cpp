#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    // Create a button to take a screenshot
    QPushButton *screenshotButton = new QPushButton("Take Screenshot", this);
    //connect(screenshotButton, &QPushButton::clicked, this, &MainWindow::takeScreenshot);
    // Use QTimer to delay the screenshot capture
    connect(screenshotButton, &QPushButton::clicked, this, &MainWindow::startex);
    // Set layout
    setCentralWidget(screenshotButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showme()
{
    this->show();
}

void MainWindow::setx()
{
    x=1;
}

void MainWindow::startex()
{
    x=1;

    if (x==1){
        // Create a QTimer object
        QTimer *timer = new QTimer(this);
        this->hide();
        // Set the timer to single-shot mode (one-time execution)
        timer->setSingleShot(true);

        connect(timer, &QTimer::timeout, this, [this]() {
            // Code to execute after the delay
            qDebug() << "Timer timed out!";
            this->takeScreenshot(); // Call member function
        });

        // Start the timer with the desired delay (in milliseconds)
        timer->start(100); // 3000 ms = 3 seconds
        x=0;

    } // 2000 milliseconds = 2 seconds}

}

void MainWindow::takeScreenshot()
{
//this->hide();
    // Capture the screen

    QScreen *screen = QGuiApplication::primaryScreen();
    if (!screen) {
        return;
    }

    QPixmap screenshot = screen->grabWindow(0);

    // Define the file path to save the screenshot on the desktop
    QString desktopPath ="/Users/ehab/Desktop";
    QString timestamp = QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");
    QString filePath = desktopPath + QDir::separator() + "Screenshot_" + timestamp + ".png";

    // Save the screenshot
    if (!screenshot.save(filePath)) {
        qDebug() << "Failed to save screenshot to" << filePath;
    } else {
        qDebug() << "Screenshot saved to" << filePath;
    }
    QTimer::singleShot(0, this, &MainWindow::showme); // 2000 milliseconds = 2 seconds
}

