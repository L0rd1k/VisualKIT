#include <QApplication>
#include <iostream>
#include <memory>
#include "GUI/MainMenuWindow.h"
#include "GUI/Cameras/CameraViewer.h"
#include "Utils/ImageProcessing/ImageTransformation.h"
#include "GUI/FieldOfViewWindow.h"
#include "QRCodeWorker/QRDetector.h"

//#include <boost/array.hpp>
//#include <boost/lambda/lambda.hpp>
//#include <iterator>
//#include <algorithm>

//Current function check one of the option for images fusion

void checkImageTransformation() {
    ImageTransformation *obj_imageTransform = new ImageTransformation();
    delete obj_imageTransform;
}

void setTextCodec() {
    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForLocale(codec);
}

void examineQtCodeImage() {
    QRDetector qd;
    qd.captureVideo();
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    setTextCodec();
    

    //    DatasetMaker win("/home/ilya/Изображения/DataSets/VoskresenskRunway/", 512);
    //    win.setMinimumSize(400, 200);
    //    win.show();

    std::unique_ptr<MainMenuWindow> _obj_main(new MainMenuWindow());
    _obj_main->show();


    // 1.  Detect QR code
    //examineQtCodeImage(); 

    // 2. Current function check one of the option for images fusion (Will be implement in Qt Designer soon)
    //checkImageTransformation();
    return app.exec();
}
