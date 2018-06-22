#ifndef WINDOW_H
#define WINDOW_H

#include <QSystemTrayIcon>

#ifndef QT_NO_SYSTEMTRAYICON

#include <QDialog>
#include <QSettings>
#include "ObsAutoRecord.h"

class QAction;
class QCheckBox;
class QComboBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QMenu;
class QPushButton;
class QSpinBox;
class QTextEdit;
class QListWidget;

class Window : public QDialog
{
    Q_OBJECT

public:
    Window();

    void setVisible(bool visible) override;

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void intervalChanged();
    void addressChanged();
    void folderChanged();
    void selectFolder();
    void selectApp();

private:
    void createGeneralGroupBox();
    void createActions();
    void createTrayIcon();

    QSettings settings;

    ObsAutoRecord *oar;

    QGroupBox *generalGroupBox;
    QLabel *intervalLabel;
    QLabel *addressLabel;
    QLabel *folderLabel;
    QSpinBox *intervalSpinBox;
    QLineEdit *addressEdit;
    QLineEdit *folderEdit;
    QPushButton *folderSelectButton;
    QListWidget *appList;
    QPushButton *appSelectButton;

    QAction *showAction;
    QAction *quitAction;

    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;

    const int DEFAULT_INTERVAL = 15;
    const QString DEFAULT_ADDRESS = "ws://localhost:4444";
};

#endif // QT_NO_SYSTEMTRAYICON

#endif