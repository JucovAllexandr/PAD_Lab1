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
    Client client;
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_connect_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
