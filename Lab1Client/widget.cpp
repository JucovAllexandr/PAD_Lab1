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

    connect(client, &Client::connected, this, [this]{
        ui->label_satus->setText("Status: connected");
        enableButtons();
    });

    connect(client, &Client::becameASubscriber, this, [this]{
        ui->label_satus->setText("Status: became a subscriber ");
        this->enableUIForSubscriber();
    });

    connect(client, &Client::becameAPublisher, this, [this]{
        ui->label_satus->setText("Status: became a publisher ");
        this->enableUIForPublisher();
    });

    connect(client, &Client::connectionError, this, [this]{
        ui->label_satus->setText("Status: connection error");
        disableAllUI();
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_connectPb_clicked()
{
    //   client->connectAsPublisher(ui->lineEdit_ip->text(), ui->spinBox_port->value());
}

void Widget::on_pushButton_connectSb_clicked()
{
    //    client->connectAsSubscriber(ui->lineEdit_ip->text(), ui->spinBox_port->value(), ui->comboBox_topics->currentText());
}

void Widget::on_pushButton_connect_clicked()
{
    client->connect(ui->lineEdit_ip->text(), ui->spinBox_port->value());
    ui->comboBox_topics->addItems(client->getTopics());
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
    ui->pushButton_connectPb->setEnabled(false);
    ui->pushButton_connectSb->setEnabled(false);
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

void Widget::enableButtons()
{
    ui->pushButton_connectPb->setEnabled(true);
    ui->pushButton_connectSb->setEnabled(true);
}
