#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <QString>
#include <QImage>

using namespace cv;
using namespace std;

class image_processing
{
public:
    image_processing() {}
    QImage take_image_file(QString imgfile);



private:
    QImage MatToQImage(const Mat &mat);
    Mat image_file_mat; // define  Mat obj. for captured Image as globally

};



















#endif // IMAGE_PROCESSING_H
