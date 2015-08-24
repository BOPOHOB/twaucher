#include "tray.h"
#include <QMenu>
#include <QProcess>
#include <QApplication>
#include <QTimer>
#include <QDebug>
#include "isonlinechecker.h"

const QIcon Tray::online = QIcon(":p/png.png");
const QIcon Tray::offline = QIcon(":p/png.png");
const QString Tray::CHANEL_URL = "twitch.tv/twaryna";

Tray::Tray()
    : p(new QProcess(this))
    , m(new QMenu(0))
    , mainAction(m->addAction(online, "watch", this, SLOT(run())))
{
    mainAction->setDisabled(true);
    this->setIcon(QIcon(":p/png.png"));
    m->addAction("exit", qApp, SLOT(quit()));
    this->setContextMenu(m);

    p->setProgram(IsOnlineChecker::LIVE_STREAMER);
    p->setArguments(QStringList() << CHANEL_URL << "best");

    QTimer* t(new QTimer(this));
    t->start(60000);
    connect(t, SIGNAL(timeout()), this, SLOT(testStatus()));
}

void Tray::run() {
    p->start();
}

void Tray::testStatus() {
    if (p->pid()) {
        return;
    }
    if (IsOnlineChecker::isOnline(CHANEL_URL)) {
        if (!mainAction->isEnabled()) {
            this->showMessage("Twaryna cyrrently online", "");
            mainAction->setIcon(online);
            mainAction->setEnabled(true);
        }
    } else {
        if (mainAction->isEnabled()) {
            mainAction->setIcon(offline);
            mainAction->setEnabled(false);
            this->toolTip();
        }
    }
}


Tray::~Tray()
{

}

