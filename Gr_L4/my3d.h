#pragma once

#ifndef MY3D_H
#define MY3D_H
#include <QGuiApplication>
#include <QCoreApplication>
#include <Qt3DCore/QEntity>
#include <Qt3DRender/QTextureGenerator>
#include <Qt3DRender/QDirectionalLight>
#include <Qt3DRender/QPointLight>
#include <Qt3DRender/QCamera>
#include <Qt3DRender/QCameraLens>
#include <Qt3DRender/Qt3DRender>
#include <Qt3DCore/QTransform>
#include <Qt3DCore/QAspectEngine>
#include <Qt3DRender/QEffect>
#include <QEffect>
#include <Qt3DInput/QInputAspect>
#include <QtCore/QDebug>
#include <Qt3DRender/QSceneLoader>
#include <Qt3DRender/QTechnique>
#include <Qt3DExtras/QPlaneMesh>
#include <Qt3DRender/QGeometryRenderer>
#include <Qt3DRender/QRenderAspect>
#include <Qt3DRender/QCamera>
#include <Qt3DExtras/QForwardRenderer>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DExtras/QDiffuseSpecularMaterial>
#include <Qt3DExtras/QCylinderMesh>
#include <Qt3DExtras/QSphereMesh>
#include <Qt3DExtras/QTorusMesh>
#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DExtras/QTextureMaterial>
#include <Qt3DRender/QAbstractTexture>
#include <QDebug>
#include <QFile>

#include <QPropertyAnimation>

#include "orbittransformcontroller.h"
#include "qorbitcameracontroller.h"


class My3D : public Qt3DExtras::Qt3DWindow {
  public:
    My3D();
    Qt3DCore::QEntity *createScene();       //создать сцену
    Qt3DCore::QEntity *rootEntity;

    Qt3DCore::QEntity *scene;
    Qt3DRender::QCamera *Camera;

    // For camera controls
    Qt3DExtras::QOrbitCameraController *camController;
};

#endif // MY3D_H
