#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTableWidget>
#include <QTableWidgetItem>
#include "sslserver.h"
#include <QTimer>
#include <QScreen>
#include <QPixmap>
//#include "QtWebSockets/QWebSocket"
#include "define.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initConnects();
    void startServer();
    void stopServer();

    void createCertificates();

    //QScreen* screen;
    QPixmap pix;
    QTimer m_timer;
public slots:
    void onClientData(QString data);
    void onTimeout();
    void mouse_control(QString x, QString y, QString type);
private slots:
    void on_button_start_server_clicked();
    void on_button_stop_server_clicked();
    void appendToLogSlot(const QString&);
    void updateClientListSlot(const QVector<QSslSocket *> &);
    void onSendClicked(bool clicked);
    void onkeyEvent(QString);
signals:
    void sendMessage(QString message);
private:
    Ui::MainWindow *ui;
    SSLServer* m_server;

};
#endif // MAINWINDOW_H
