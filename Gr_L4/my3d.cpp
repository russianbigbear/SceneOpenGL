#include "my3d.h"

My3D::My3D() : Qt3DExtras::Qt3DWindow()
{
    scene = createScene();

    // Камера
    Camera = this->camera();
    Camera->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    Camera->setPosition(QVector3D(0, 30.0f, 55.0f));
    Camera->setViewCenter(QVector3D(0, 0, 0));


    // For camera controls
    camController = new Qt3DExtras::QOrbitCameraController(scene);
    camController->setLinearSpeed( 50.0f );
    camController->setLookSpeed( 180.0f );
    camController->setCamera(Camera);
    this-> setRootEntity (scene);
}

Qt3DCore::QEntity * My3D::createScene()
{
    auto *rootEntity = new Qt3DCore::QEntity;

    /*-----------------------------------------------------Свет------------------------------------------------------------*/
    auto *lightEntity_r = new Qt3DCore::QEntity(rootEntity);
    auto *light_r = new Qt3DRender::QPointLight(lightEntity_r);
    auto *lightTransform_r = new Qt3DCore::QTransform(lightEntity_r);

    auto *lightEntity_b = new Qt3DCore::QEntity(rootEntity);
    auto *light_b = new Qt3DRender::QPointLight(lightEntity_b);
    auto *lightTransform_b = new Qt3DCore::QTransform(lightEntity_b);

    auto *lightEntity_w = new Qt3DCore::QEntity(rootEntity);
    auto *light_w = new Qt3DRender::QPointLight(lightEntity_b);
    auto *lightTransform_w = new Qt3DCore::QTransform(lightEntity_b);

    light_r->setColor("red");
    light_r->setIntensity(0.5f);
    lightEntity_r->addComponent(light_r);
    lightTransform_r->setTranslation(QVector3D(-25, 20, -25));
    lightEntity_r->addComponent(lightTransform_r);
    light_r->setEnabled(true);

    light_b->setColor("green");
    light_b->setIntensity(1);
    lightEntity_b->addComponent(light_b);
    lightTransform_b->setTranslation(QVector3D(25, 10, 25));
    lightEntity_b->addComponent(lightTransform_b);
    light_b->setEnabled(true);


    light_w->setColor("white");
    light_w->setIntensity(0.3f);
    lightEntity_w->addComponent(light_w);
    lightTransform_w->setTranslation(QVector3D(0, 30, 0));
    lightEntity_w->addComponent(lightTransform_w);
    light_w->setEnabled(true);
    /*--------------------------------------------------------------------------------------------------------------------*/


    /*-------------------------------------------------Стены--------------------------------------------------------------*/
    auto *wall = new Qt3DCore::QEntity(rootEntity);
    auto *wall2 = new Qt3DCore::QEntity(rootEntity);
    auto *wall3 = new Qt3DCore::QEntity(rootEntity);

    auto *wallMesh = new Qt3DExtras::QPlaneMesh;
    auto *wallTex = new Qt3DRender::QTextureLoader(rootEntity);
    auto *wallMaterial = new Qt3DExtras::QTextureMaterial(rootEntity);
    auto *wallTransform = new Qt3DCore::QTransform;

    QString file = QCoreApplication::applicationDirPath() + "/Tex/Wall/Wall1.jpg";
    wallTex->setSource(QUrl::fromLocalFile(file));
    wallMaterial->setTexture(wallTex);
    wallTex->setSize(5, 5);
    wallTex->setWrapMode(Qt3DRender::QTextureWrapMode (Qt3DRender::QTextureWrapMode::MirroredRepeat));

    wallMesh->setHeight(20);
    wallMesh->setWidth(50);
    wallTransform->setRotationX(90);
    wallTransform->setTranslation(QVector3D(0, 10, -25));

    wall->addComponent(wallMesh);
    wall->addComponent(wallTransform);
    wall->addComponent(wallMaterial);

    wallMesh = new Qt3DExtras::QPlaneMesh;
    wallMesh->setHeight(20);
    wallMesh->setWidth(50);

    wallTransform = new Qt3DCore::QTransform;
    wallTransform->setRotationZ(90);
    wallTransform->setRotationX(90);
    wallTransform->setTranslation(QVector3D(25, 10, 0));

    wall2->addComponent(wallMesh);
    wall2->addComponent(wallTransform);
    wall2->addComponent(wallMaterial);

    wallMesh = new Qt3DExtras::QPlaneMesh;
    wallMesh->setHeight(20);
    wallMesh->setWidth(50);

    wallTransform = new Qt3DCore::QTransform;
    wallTransform->setRotationZ(-90);
    wallTransform->setRotationX(90);
    wallTransform->setTranslation(QVector3D(-25, 10, 0));

    wall3->addComponent(wallMesh);
    wall3->addComponent(wallTransform);
    wall3->addComponent(wallMaterial);
    /*--------------------------------------------------------------------------------------------------------------------*/


    /*--------------------------------------------------Пол---------------------------------------------------------------*/
    auto *floor = new Qt3DCore::QEntity(rootEntity);

    auto *Material = new Qt3DExtras::QDiffuseSpecularMaterial(rootEntity);
    Material->setDiffuse(QColor(QRgb(0x928327)));
    Material->setShininess(0.5f);

    wallMesh = new Qt3DExtras::QPlaneMesh;
    wallMaterial = new Qt3DExtras::QTextureMaterial(rootEntity);
    wallTransform = new Qt3DCore::QTransform;
    wallTransform->setRotationY(90);

    wallTex  = new Qt3DRender::QTextureLoader(rootEntity);
    wallTex->setWrapMode(* new Qt3DRender::QTextureWrapMode (Qt3DRender::QTextureWrapMode::Repeat));

    wallMesh->setHeight(50);
    wallMesh->setWidth(50);

    file = QCoreApplication::applicationDirPath() + "/Tex/Floor/Floor1.jpg";
    wallTex->setWrapMode(Qt3DRender::QTextureWrapMode (Qt3DRender::QTextureWrapMode::MirroredRepeat));
    wallTex->setSource(QUrl::fromLocalFile(file));
    wallTex->setWidth(5);
    wallTex->setHeight(5);

    Qt3DRender::QTextureWrapMode qm (Qt3DRender::QTextureWrapMode::Repeat);
    qm.setX(Qt3DRender::QTextureWrapMode::Repeat);
    qm.setY(Qt3DRender::QTextureWrapMode::Repeat);
    qm.setZ(Qt3DRender::QTextureWrapMode::Repeat);
    wallTex->setWrapMode(qm);

    wallMaterial->setTexture(wallTex);
    wallMaterial->setAlphaBlendingEnabled(true);

    floor->addComponent(wallMesh);
    floor->addComponent(wallTransform);
    floor->addComponent(Material);
    floor->addComponent(wallMaterial);
    /*--------------------------------------------------------------------------------------------------------------------*/


    /*----------------------------------------------Плакаты--------------------------------------------------------------*/
    auto *Pic1 = new Qt3DCore::QEntity(rootEntity);
    auto *Pic2 = new Qt3DCore::QEntity(rootEntity);
    auto *Pic3 = new Qt3DCore::QEntity(rootEntity);
    auto *Pic4 = new Qt3DCore::QEntity(rootEntity);

    //Плакат-правила
    wallMesh = new Qt3DExtras::QPlaneMesh;
    wallMaterial = new Qt3DExtras::QTextureMaterial(rootEntity);

    wallTex  = new Qt3DRender::QTextureLoader(rootEntity);
    wallMesh->setHeight(8);
    wallMesh->setWidth(8);
    file = QCoreApplication::applicationDirPath() + "/Tex/Picture/Pic1.jpg";
    wallTex->setSource(QUrl::fromLocalFile(file));
    wallTex->setMirrored(false);

    wallMaterial->setTexture(wallTex);

    wallTransform = new Qt3DCore::QTransform;
    wallTransform->setRotationX(90);
    wallTransform->setTranslation(QVector3D(-20, 15, float(-24.8)));

    Pic1->addComponent(wallMesh);
    Pic1->addComponent(wallTransform);
    Pic1->addComponent(wallMaterial);

    //Плакат - CS
    wallMesh = new Qt3DExtras::QPlaneMesh;
    wallMaterial = new Qt3DExtras::QTextureMaterial(rootEntity);

    wallTex  = new Qt3DRender::QTextureLoader(rootEntity);
    wallMesh->setHeight(14);
    wallMesh->setWidth(10);
    file = QCoreApplication::applicationDirPath() + "/Tex/Picture/Pic2.jpg";
    wallTex->setSource(QUrl::fromLocalFile(file));
    wallTex->setMirrored(false);

    wallMaterial->setTexture(wallTex);

    wallTransform = new Qt3DCore::QTransform;
    wallTransform->setRotationX(90);
    wallTransform->setTranslation(QVector3D(0, 12, float(-24.8)));

    Pic2->addComponent(wallMesh);
    Pic2->addComponent(wallTransform);
    Pic2->addComponent(wallMaterial);

    //Плакат - Wow
    wallMesh = new Qt3DExtras::QPlaneMesh;
    wallMaterial = new Qt3DExtras::QTextureMaterial(rootEntity);

    wallTex  = new Qt3DRender::QTextureLoader(rootEntity);
    wallMesh->setHeight(10);
    wallMesh->setWidth(8);
    file = QCoreApplication::applicationDirPath() + "/Tex/Picture/Pic3.png";
    wallTex->setSource(QUrl::fromLocalFile(file));
    wallTex->setMirrored(false);

    wallMaterial->setTexture(wallTex);

    wallTransform = new Qt3DCore::QTransform;
    wallTransform->setRotationZ(270);
    wallTransform->setRotationX(90);
    wallTransform->setTranslation(QVector3D(float(-24.8), 13, 16));

    Pic3->addComponent(wallMesh);
    Pic3->addComponent(wallTransform);
    Pic3->addComponent(wallMaterial);

    //Плакат - Wow
    wallMesh = new Qt3DExtras::QPlaneMesh;
    wallMaterial = new Qt3DExtras::QTextureMaterial(rootEntity);

    wallTex  = new Qt3DRender::QTextureLoader(rootEntity);
    wallMesh->setHeight(12);
    wallMesh->setWidth(25);
    file = QCoreApplication::applicationDirPath() + "/Tex/Picture/Pic4.jpg";
    wallTex->setSource(QUrl::fromLocalFile(file));
    wallTex->setMirrored(false);

    wallMaterial->setTexture(wallTex);

    wallTransform = new Qt3DCore::QTransform;
    wallTransform->setRotationZ(90);
    wallTransform->setRotationX(90);
    wallTransform->setTranslation(QVector3D(float(24.8), 14, 6));

    Pic4->addComponent(wallMesh);
    Pic4->addComponent(wallTransform);
    Pic4->addComponent(wallMaterial);
    /*--------------------------------------------------------------------------------------------------------------------*/


    /*---------------------------------------------------Столы----------------------------------------------------------*/   
    auto *Table1 = new Qt3DCore::QEntity(rootEntity);
    auto *Table2 = new Qt3DCore::QEntity(rootEntity);
    auto *Table3 = new Qt3DCore::QEntity(rootEntity);
    auto *Table4 = new Qt3DCore::QEntity(rootEntity);

    auto *TablelMesh = new Qt3DRender::QMesh;
    auto *TableTex = new Qt3DRender::QTextureLoader(rootEntity);
    auto *TableMaterial = new Qt3DExtras::QTextureMaterial(rootEntity);


    file = QCoreApplication::applicationDirPath() + "/Tex/3d/Table/Table.obj";
    TablelMesh->setSource(QUrl::fromLocalFile(file));

    file = QCoreApplication::applicationDirPath() + "/Tex/3d/Table/Table.jpg";
    TableTex->setSource(QUrl::fromLocalFile(file));
    TableMaterial->setTexture(TableTex);

    //Table1
    auto *TableTransform1 = new Qt3DCore::QTransform;
    TableTransform1->setScale3D(QVector3D(float(0.1), float(0.09), float(0.06)));
    TableTransform1->setTranslation(QVector3D(-16, 0, -22));

    Table1->addComponent(TablelMesh);
    Table1->addComponent(TableTransform1);
    Table1->addComponent(TableMaterial);

    //Table2
    auto *TableTransform2 = new Qt3DCore::QTransform;
    TableTransform2->setScale3D(QVector3D(float(0.1), float(0.09), float(0.06)));
    TableTransform2->setTranslation(QVector3D(16, 0, -22));

    Table2->addComponent(TablelMesh);
    Table2->addComponent(TableTransform2);
    Table2->addComponent(TableMaterial);

    //Table3
    auto *TableTransform3 = new Qt3DCore::QTransform;
    TableTransform3->setScale3D(QVector3D(float(0.1), float(0.09), float(0.06)));
    TableTransform3->setTranslation(QVector3D(-22, 0, 6));
    TableTransform3->setRotationY(90);

    Table3->addComponent(TablelMesh);
    Table3->addComponent(TableTransform3);
    Table3->addComponent(TableMaterial);

    //Table4
    auto *TableTransform4 = new Qt3DCore::QTransform;
    TableTransform4->setScale3D(QVector3D(float(0.1), float(0.09), float(0.06)));
    TableTransform4->setTranslation(QVector3D(22, 0, 6));
    TableTransform4->setRotationY(270);

    Table4->addComponent(TablelMesh);
    Table4->addComponent(TableTransform4);
    Table4->addComponent(TableMaterial);
    /*--------------------------------------------------------------------------------------------------------------------*/


    /*---------------------------------------------------Стулья----------------------------------------------------------*/
    auto *Chair1 = new Qt3DCore::QEntity(rootEntity);
    auto *Chair2 = new Qt3DCore::QEntity(rootEntity);
    auto *Chair3 = new Qt3DCore::QEntity(rootEntity);
    auto *Chair4 = new Qt3DCore::QEntity(rootEntity);

    auto *ChairMesh = new Qt3DRender::QMesh;
    auto *ChairTex = new Qt3DRender::QTextureLoader(rootEntity);
    auto *ChairMaterial = new Qt3DExtras::QTextureMaterial(rootEntity);

    file = QCoreApplication::applicationDirPath() + "/Tex/3d/Chair/Chair.obj";
    ChairMesh->setSource(QUrl::fromLocalFile(file));

    file = QCoreApplication::applicationDirPath() + "/Tex/3d/Chair/Chair.png";
    ChairTex->setSource(QUrl::fromLocalFile(file));
    ChairMaterial->setTexture(ChairTex);

    //Chair1
    auto *ChairTransform1 = new Qt3DCore::QTransform;
    ChairTransform1->setScale3D(QVector3D(float(0.1), float(0.1), float(0.1)));
    ChairTransform1->setTranslation(QVector3D(-16, 0, -15));
    ChairTransform1->setRotationY(90);

    Chair1->addComponent(ChairMesh);
    Chair1->addComponent(ChairTransform1);
    Chair1->addComponent(ChairMaterial);

    //Chair2
    auto *ChairTransform2 = new Qt3DCore::QTransform;
    ChairTransform2->setScale3D(QVector3D(float(0.1), float(0.1), float(0.1)));
    ChairTransform2->setTranslation(QVector3D(16, 0, -15));
    ChairTransform2->setRotationY(90);

    Chair2->addComponent(ChairMesh);
    Chair2->addComponent(ChairTransform2);
    Chair2->addComponent(ChairMaterial);

    //Chair3
    auto *ChairTransform3 = new Qt3DCore::QTransform;
    ChairTransform3->setScale3D(QVector3D(float(0.1), float(0.1), float(0.1)));
    ChairTransform3->setTranslation(QVector3D(-14, 0, 6));
    ChairTransform3->setRotationY(180);

    Chair3->addComponent(ChairMesh);
    Chair3->addComponent(ChairTransform3);
    Chair3->addComponent(ChairMaterial);

    //Chair4
    auto *ChairTransform4 = new Qt3DCore::QTransform;
    ChairTransform4->setScale3D(QVector3D(float(0.1), float(0.1), float(0.1)));
    ChairTransform4->setTranslation(QVector3D(14, 0, 6));

    Chair4->addComponent(ChairMesh);
    Chair4->addComponent(ChairTransform4);
    Chair4->addComponent(ChairMaterial);
    /*--------------------------------------------------------------------------------------------------------------------*/


    /*---------------------------------------------------Компьютеры----------------------------------------------------------*/
    auto *Comp1 = new Qt3DCore::QEntity(rootEntity);
    auto *Comp2 = new Qt3DCore::QEntity(rootEntity);
    auto *Comp3 = new Qt3DCore::QEntity(rootEntity);
    auto *Comp4 = new Qt3DCore::QEntity(rootEntity);

    auto *CompMesh = new Qt3DRender::QMesh;
    auto *CompTex = new Qt3DRender::QTextureLoader(rootEntity);
    auto *CompMaterial = new Qt3DExtras::QTextureMaterial(rootEntity);

    file = QCoreApplication::applicationDirPath() + "/Tex/3d/Comp/Monitor.obj";
    CompMesh->setSource(QUrl::fromLocalFile(file));

    file = QCoreApplication::applicationDirPath() + "/Tex/3d/Comp/Monitor.png";
    CompTex->setSource(QUrl::fromLocalFile(file));
    CompMaterial->setTexture(CompTex);

    //Comp1
    auto *CompTransform1 = new Qt3DCore::QTransform;
    CompTransform1->setScale3D(QVector3D(2, 2, 2));
    CompTransform1->setTranslation(QVector3D(-16, 10, -24));
    CompTransform1->setRotationY(-8);

    Comp1->addComponent(CompMesh);
    Comp1->addComponent(CompTransform1);
    Comp1->addComponent(CompMaterial);

    //Comp2
    auto *CompTransform2 = new Qt3DCore::QTransform;
    CompTransform2->setScale3D(QVector3D(2, 2, 2));
    CompTransform2->setTranslation(QVector3D(16, 10, -24));
    CompTransform2->setRotationY(-8);

    Comp2->addComponent(CompMesh);
    Comp2->addComponent(CompTransform2);
    Comp2->addComponent(CompMaterial);

    //Comp3
    auto *CompTransform3 = new Qt3DCore::QTransform;
    CompTransform3->setScale3D(QVector3D(2, 2, 2));
    CompTransform3->setTranslation(QVector3D(-24, 10, 6));
    CompTransform3->setRotationY(82);

    Comp3->addComponent(CompMesh);
    Comp3->addComponent(CompTransform3);
    Comp3->addComponent(CompMaterial);

    //Comp4
    auto *CompTransform4 = new Qt3DCore::QTransform;
    CompTransform4->setScale3D(QVector3D(2, 2, 2));
    CompTransform4->setTranslation(QVector3D(24, 10, 6));
    CompTransform4->setRotationY(-98);

    Comp4->addComponent(CompMesh);
    Comp4->addComponent(CompTransform4);
    Comp4->addComponent(CompMaterial);
    /*--------------------------------------------------------------------------------------------------------------------*/


    return rootEntity;
}
