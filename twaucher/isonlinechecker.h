#ifndef ISONLINECHECKER_H
#define ISONLINECHECKER_H

#include <QThread>

class QString;

class IsOnlineChecker : public QThread
{
    Q_OBJECT

    bool result;
    QString chanel;

    void run();
public:
    IsOnlineChecker();
    ~IsOnlineChecker();

    static const QString LIVE_STREAMER;
    static bool isOnline(const QString& name);
};

#endif // ISONLINECHECKER_H
