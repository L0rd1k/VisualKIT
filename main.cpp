#include <QApplication>
#include <iostream>
#include <memory>
#include "GUI/MainMenuWindow.h"
#include "GUI/CalibrationExecutor.h"
#include "GUI/Cameras/CameraViewer.h"
#include "Utils/ImageProcessing/ImageTransformation.h"

//Current function check one of the option for images fusion
void checkImageTransformation() {
    ImageTransformation *obj_imageTransform = new ImageTransformation();
    delete obj_imageTransform;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    std::unique_ptr<CalibrationExecutor> _obj_calibExec(new CalibrationExecutor());
    _obj_calibExec->show();
//    checkImageTransformation(); // Current function check one of the option for images fusion (Will be implement in Qt Designer soon)
    
    return app.exec();
}
