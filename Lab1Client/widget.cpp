#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label_satus->setText("Status: disconnected");

    disableAllUI();

    client = new Client(this);

    connect(client, &Client::connectedAsPublisher, this, [this]{
        ui->label_satus->setText("Status: connected as publisher");
        this->enableUIForPublisher();
    });

    connect(client, &Client::connectedAsSubscriber, this, [this]{
        ui->label_satus->setText("Status: connected as subscriber");
        this->enableUIForSubscriber();
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_connectPb_clicked()
{
    client->connectAsPublisher(ui->lineEdit_ip->text(), ui->spinBox_port->value());
}

void Widget::on_pushButton_connectSb_clicked()
{
    client->connectAsSubscriber(ui->lineEdit_ip->text(), ui->spinBox_port->value(), ui->comboBox_topics->currentText());
}

void Widget::on_pushButton_send_clicked()
{
    client->send(ui->plainTextEdit->document()->toRawText());
}

void Widget::disableAllUI()
{
    ui->textBrowser_2->setEnabled(false);
    ui->pushButton_send->setEnabled(false);
    ui->plainTextEdit->setEnabled(false);
}

void Widget::enableUIForPublisher()
{
    ui->pushButton_send->setEnabled(true);
    ui->plainTextEdit->setEnabled(true);
}

void Widget::enableUIForSubscriber()
{
    ui->textBrowser_2->setEnabled(true);
}
