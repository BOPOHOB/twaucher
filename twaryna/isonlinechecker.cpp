#include "isonlinechecker.h"
#include <QEventLoop>
#include <QProcess>

const QString IsOnlineChecker::LIVE_STREAMER = QString("C:\\Program Files (x86)\\Livestreamer\\livestreamer.exe");

IsOnlineChecker::IsOnlineChecker()
{

}

IsOnlineChecker::~IsOnlineChecker()
{

}

bool IsOnlineChecker::isOnline(const QString& name) {
    QEventLoop loop;
    IsOnlineChecker checker;
    checker.chanel = name;
    loop.connect(&checker, SIGNAL(finished()), SLOT(quit()));
    checker.start(QThread::LowestPriority);
    loop.exec();
    return checker.result;
}
#include <QDebug>
void IsOnlineChecker::run() {
    QProcess p;
    p.setProgram(LIVE_STREAMER);
    p.setArguments(QStringList() << chanel << "best");
    p.start();
    p.waitForReadyRead();
    p.waitForReadyRead();
    p.waitForReadyRead();
    result = p.readAll().contains("Available streams");
    p.kill();
    p.waitForFinished();
}
