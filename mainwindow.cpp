#include "mainwindow.h"
#include "ui_mainwindow.h"


using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    image_process_class = image_processing();
    ui->Color_label->setBackgroundRole(QPalette::Base);
    palet = ui->Color_label->palette();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Open_img_2_clicked()
{
    QString imagefile_str = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     "",
                                                     tr("Files (*.*)"));

    if(image_process_class.take_image_file(imagefile_str).isNull()){

        message_error.critical(this,"Error","This problem maybe  missing file, improper permissions, unsupported or invalid format.");

     }
    else {

        ui->Image_disp_label->setPixmap(QPixmap::fromImage(image_process_class.take_image_file(imagefile_str)));

    }

}

void MainWindow::on_Red_slider_2_valueChanged(int value)
{
    ui->Red_val_lcd_2->display(value);
    palet.setColor(ui->Color_label->backgroundRole(),QColor(112,223,112)); //QColor(value,rgb_val_uchar[1],rgb_val_uchar[2])
    ui->Color_label->setPalette(palet);
    rgb_val_uchar[0]=value;
}

void MainWindow::on_Green_slider_2_valueChanged(int value)
{
    ui->Green_val_lcd_2->display(value);
    palet.setColor(ui->Color_label->backgroundRole(),QColor(rgb_val_uchar[0],value,rgb_val_uchar[2]));
    ui->Color_label->setPalette(palet);
    rgb_val_uchar[1]=value;
}

void MainWindow::on_Blue_slider_2_valueChanged(int value)
{
    ui->Blue_val_lcd_2->display(value);
    palet.setColor(ui->Color_label->backgroundRole(),QColor(rgb_val_uchar[0],rgb_val_uchar[1],value));
    ui->Color_label->setPalette(palet);
    rgb_val_uchar[2]=value;
}

void MainWindow::on_Calib_disp1_dial_2_valueChanged(int value)
{
    ui->Calib_disp1_lcd_2->display(value);
}

void MainWindow::on_Calib_disp2_dial_2_valueChanged(int value)
{
     ui->Calib_disp2_lcd_2->display(value);
}
