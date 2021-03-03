#include "application.h"

#include <QAction>
#include <QApplication>
#include <QMenu>
#include <QMessageBox>

#include "settings.h"

Application::Application(QObject* parent)
    : QObject(parent)
    , m_trayIcon(new QSystemTrayIcon(this))
    , m_settings(new Settings(this))
{
    m_icon = QIcon(":/icons/model-m.jpg");
    m_trayIcon->setIcon(m_icon);

    setupActions();

    setupContextMenu();
}

void Application::show()
{
    m_trayIcon->show();
}

void Application::onAbout()
{
    QMessageBox::about(nullptr,
                       tr("About %1").arg(qApp->applicationName()),
                       tr("%1 makes sounds when you type").arg(qApp->applicationName()));
}

void Application::setupActions()
{
    m_aboutAction = new QAction(tr("About %1").arg(qApp->applicationName()), this);

    connect(m_aboutAction, &QAction::triggered, this, &Application::onAbout);
}

void Application::setupContextMenu()
{
    QAction* quit = new QAction(tr("Quit"), this);
    quit->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q));
    connect(quit, &QAction::triggered, qApp, &QApplication::quit);

    QMenu* contextMenu = new QMenu();
    contextMenu->addAction(m_aboutAction);
    contextMenu->addSeparator();
    contextMenu->addAction(quit);

    m_trayIcon->setContextMenu(contextMenu);
}

void Application::loadSettings()
{
    // TODO: load settings
}

void Application::saveSettings()
{
    // TODO: save settings
}
