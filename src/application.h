#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QSystemTrayIcon>

class QAction;
class Settings;

class Application : public QObject
{
    Q_OBJECT

public:
    explicit Application(QObject* parent = nullptr);

    void show();

private slots:
    //void onPreferences(); // TODO: maybe we'll use them
    //void onPreferencesSaved(); // TODO: maybe we'll use them

    void onAbout();

private:
    void setupActions();
    void setupContextMenu();

    void loadSettings();
    void saveSettings();

private:
    QSystemTrayIcon* m_trayIcon{nullptr};

    QAction* m_aboutAction{nullptr};

    Settings* m_settings{nullptr};

    QIcon m_icon;
};

#endif // APPLICATION_H
