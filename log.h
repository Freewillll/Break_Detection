#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <QtMsgHandler>
#include <QMutex>
#include <QFile>
#include <QDir>
#include <QTextStream>

void messageOutput(QtMsgType type, const char *msg)
{
    static QMutex mutex;
    mutex.lock();
    QString txtMessage;
    switch (type) {
    case QtDebugMsg:
        txtMessage = QString("[Debug] %1").arg(msg);
        break;
    case QtWarningMsg:
        txtMessage = QString("[Warning] %1").arg(msg);
        break;
    case QtCriticalMsg:
        txtMessage = QString("[Critical] %1").arg(msg);
        break;
    case QtFatalMsg:
        txtMessage = QString("[Fatal] %1").arg(msg);
        abort();
    default:
        break;
    }
    txtMessage += QString("\r\n");
    QString curPath = QDir::currentPath();
    QString qDebugfilePath = curPath.append("/qDebug.txt");
    QFile file(QObject::tr(qDebugfilePath.toStdString().c_str()));
    if(file.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        QTextStream out(&file);
        out<<txtMessage;
    }
    file.flush();
    file.close();
    mutex.unlock();
}

#endif // LOG_H
