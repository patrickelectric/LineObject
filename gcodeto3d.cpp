#include "gcodeto3d.h"

#include <QDebug>
#include <QFile>
#include <QVector4D>
#include <QThread>
#include <QUrl>

GcodeTo3D::GcodeTo3D(QObject *parent) :
    QObject(parent)
    , _wait(false)
{
}

GcodeTo3D::~GcodeTo3D()
{
}

void GcodeTo3D::enableWait()
{
    _wait = true;
}

void GcodeTo3D::read(QString url)
{
    thread = new QThread;
    auto fileLoader = new FileLoader(QUrl(url).path());
    fileLoader->enableWait(_wait);
    fileLoader->moveToThread(thread);
    connect(fileLoader, &FileLoader::percentUpdate ,this, &GcodeTo3D::percentUpdate);
    connect(fileLoader, &FileLoader::posFinished ,this, &GcodeTo3D::posFinished);
    connect(fileLoader, &FileLoader::posUpdated ,this, &GcodeTo3D::posUpdated);
    connect(thread, &QThread::started, fileLoader, &FileLoader::run);
    thread->start();
}
