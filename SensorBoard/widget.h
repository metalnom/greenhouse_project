#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    struct SerialSettings {
        QString portname;
        qint32 baudRate;
        QSerialPort::DataBits dataBits;
        QSerialPort::Parity parity;
        QSerialPort::StopBits stopBits;
        QSerialPort::FlowControl flowControl;
    };
    SerialSettings m_serialSettings;
    QSerialPort *m_serial;

    QSqlDatabase db;
    QSqlTableModel *model;

    QMessageBox qmsg;

    void showTable();

private slots:
    void connectButton();
    void exitButton();
    void readData();
    void error(QSerialPort::SerialPortError err);
    void tableClicked(const QModelIndex &index);

    void insertButton();
    void updateButton();
    void deleteButton();
    void initeditorButton();
};
#endif // WIDGET_H
