#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>


void init_fusion(void);


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    init_fusion();
    w.show();

    return a.exec();
}

void init_fusion(void){
    qApp->setStyle(QStyleFactory::create("fusion"));
    QPalette palette;
    palette.setColor(QPalette::Window, QColor(25,25,25));
    palette.setColor(QPalette::WindowText, Qt::white);
    palette.setColor(QPalette::Base, QColor(15,15,15));
    palette.setColor(QPalette::AlternateBase, QColor(25,25,25));
    palette.setColor(QPalette::ToolTipBase, Qt::white);
    palette.setColor(QPalette::ToolTipText, Qt::white);
    palette.setColor(QPalette::Text, Qt::white);
    palette.setColor(QPalette::Button, QColor(25,25,25));
    palette.setColor(QPalette::ButtonText, Qt::white);
    palette.setColor(QPalette::BrightText, Qt::red);
    palette.setColor(QPalette::Highlight, QColor(163,51,11).lighter());
    palette.setColor(QPalette::HighlightedText, Qt::black);
    qApp->setPalette(palette);
}
