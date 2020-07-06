#include <QGuiApplication>

#include <Qt3DCore/QEntity>
#include <Qt3DRender/QCamera>
#include <Qt3DRender/QCameraLens>
#include <Qt3DCore/QTransform>
#include <Qt3DCore/QAspectEngine>
#include <Qt3DInput/QInputAspect>
#include <Qt3DRender/QRenderAspect>
#include <Qt3DExtras/QForwardRenderer>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DExtras/QCylinderMesh>
#include <Qt3DExtras/QSphereMesh>
#include <Qt3DExtras/QTorusMesh>
#include <QPropertyAnimation>

#include "qt3dwindow.h"
#include "orbittransformcontroller.h"
#include "qorbitcameracontroller.h"
#include "my3d.h"

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);
    My3D view;
    view.show();  //show();

    return app.exec();
}
