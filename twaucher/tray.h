#ifndef TRAY_H
#define TRAY_H

#include <QSystemTrayIcon>

class QProcess;
class QMenu;
class QIcon;
class QAction;

class Tray : public QSystemTrayIcon
{
    Q_OBJECT
    static const QIcon online;
    static const QIcon offline;
    static const QString CHANEL_URL;

    QProcess* const p;
    QMenu* const m;
    QAction* const mainAction;
public:
    Tray();
    ~Tray();

public slots:
    void run();
    void testStatus();
};

#endif // TRAY_H
