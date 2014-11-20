#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QColorDialog>
#include <QLabel>
#include <iostream>
#include "image_processing.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QPalette palet;
    QColor color;

private slots:
    void on_Open_img_2_clicked();

    void on_Red_slider_2_valueChanged(int value);

    void on_Green_slider_2_valueChanged(int value);

    void on_Blue_slider_2_valueChanged(int value);

    void on_Calib_disp1_dial_2_valueChanged(int value);

    void on_Calib_disp2_dial_2_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    image_processing image_process_class;
    QMessageBox message_error;
    unsigned char rgb_val_uchar[3];

};

#endif // MAINWINDOW_H
