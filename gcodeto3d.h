#pragma once

#include <QObject>
#include <QVariant>
#include <QVector4D>
#include <QTextStream>
#include <QFile>
#include <cmath>
#include <QDebug>
#include <QTest>

class GcodeTo3D : public QObject
{
    Q_OBJECT

public:
    GcodeTo3D(QObject *parent = 0);
    virtual ~GcodeTo3D();

public:
    void read(QString url);
    void enableWait();

signals:
    void percentUpdate(QVariant percent);
    void posFinished(QList<QVector4D> pos);
    void posUpdated(QList<QVector4D> pos);

private:
    QThread *thread;
    bool _wait;
};

class FileLoader : public QObject
{
    Q_OBJECT

public:
    FileLoader(QString fileName, QObject *parent = nullptr):
        QObject(parent),
        file(new QFile(fileName)),
        _wait(false)
    {
    }

    void enableWait(bool wait)
    {
        _wait = wait;
    }

    ~FileLoader()
    {
    };

private:
    QFile *file;
    bool _wait;

signals:
    void percentUpdate(QVariant var);
    void posFinished(QList<QVector4D> pos);
    void posUpdated(QList<QVector4D> pos);

public slots:
    void run()
    {
        QList<QVector4D> pos;
        qint64 totalSize = file->bytesAvailable();
        qint64 stillSize = totalSize;
        float lastPerc = 0.0;
        qDebug() << totalSize;
        if (file->open(QIODevice::ReadOnly)) {
            QTextStream in(file);
            while (!in.atEnd()) {
                //Get each line
                QString line = in.readLine();
                stillSize -= line.size() + 1; // +1 endl
                float perc = (totalSize -  stillSize) * 100.0 / totalSize;
                if (perc - lastPerc > 1) {
                    qDebug() << perc;
                    emit percentUpdate((int)perc);
                    lastPerc = perc;
                }
                line = line.simplified();
                //Is it a comment ? Drop it
                if (line.isEmpty()) {
                    continue;
                } else {
                    //Remove comment in the end of command
                    if (line.indexOf(";") != -1) {
                        line.resize(line.indexOf(";"));
                        //Remove trailing spaces
                        line = line.simplified();
                    }

                    //Split command and args
                    QStringList commAndArgs = line.split(' ');

                    if (commAndArgs[0] == "G1") {
                        QVector4D ActualPos;
                        //Compute args
                        commAndArgs.removeFirst();
                        for (auto element : commAndArgs) {
                            if (element[0] == 'X') {
                                ActualPos.setX(element.remove(0, 1).toFloat() / 10);
                            }

                            if (element[0] == 'Y') {
                                ActualPos.setY(element.remove(0, 1).toFloat() / 10);
                            }

                            if (element[0] == 'Z') {
                                ActualPos.setZ(element.remove(0, 1).toFloat() / 10);
                            }

                            if (element[0] == 'E') {
                                ActualPos.setW(element.remove(0, 1).toFloat() / 10);
                            }
                        }

                        if (!pos.isEmpty()) {
                            if (!line.contains("X")) {
                                ActualPos.setX(pos.last().x());
                            }
                            if (!line.contains("Y")) {
                                ActualPos.setY(pos.last().y());
                            }
                            if (!line.contains("Z")) {
                                ActualPos.setZ(pos.last().z());
                            }
                            if (!line.contains("E")) {
                                ActualPos.setW(pos.last().w());
                            }
                        }

                        pos.append(ActualPos);
                        if (pos.size() > 1 && _wait) {
                            QTest::qWait(40);
                            emit posUpdated(pos);
                        }
                    }
                }
            }
            emit percentUpdate(100);
            file->close();
            emit posFinished(pos);
        }
    };
};
