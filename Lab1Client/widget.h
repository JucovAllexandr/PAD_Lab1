#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "client.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
    Client *client;
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_connectPb_clicked();

    void on_pushButton_connectSb_clicked();

    void on_pushButton_send_clicked();

private:
    Ui::Widget *ui;
    void disableAllUI();
    void enableUIForPublisher();
    void enableUIForSubscriber();
};
#endif // WIDGET_H
