#include "image_processing.h"


QImage image_processing::take_image_file(QString imgfile) {

    QImage map;
    image_file_mat = imread(imgfile.toStdString(),3);


    if(image_file_mat.data == NULL){

         // Dont make any convert progress so that The map variable is to be NULL
    }
    else {

        if(!MatToQImage(image_file_mat).isNull()){
            map = MatToQImage(image_file_mat.clone()); //Clone image is used because We are going to use its orjinal image in The Image processing
        }
        else {

            // Dont make any convert progress so that The map variable is to be NULL
        }

    }

   return map; // now The map var is either valid or null

}


// Convert cv::Mat obj. of The OpenCv to QImage object

QImage image_processing::MatToQImage(Mat const &mat)
{

    // 8-bits unsigned, NO. OF CHANNELS=1
    if(mat.type()==CV_8UC1)
    {
        // Set the color table (used to translate colour indexes to qRgb values)
        QVector<QRgb> colorTable;
        for (int i=0; i<256; i++)
            colorTable.push_back(qRgb(i,i,i));
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);
        img.setColorTable(colorTable);
        return img;
    }
    // 8-bits unsigned, NO. OF CHANNELS=3
    else if(mat.type()==CV_8UC3)
    {
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return img.rgbSwapped();
    }
    else
    {

        return QImage();
    }
}
