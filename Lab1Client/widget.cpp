#include "widget.h"
#include "ui_widget.h"
#include <QScrollBar>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label_satus->setText("Status: disconnected");

    disableAllUI();

    client = new Client(this);

    qRegisterMetaType<Message>("Message");
    qRegisterMetaType<QList<Message>>("QList<Message>");

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

    connect(client, &Client::messageRecived, this, [this](Message msg){
        ui->textBrowser_2->setHtml(ui->textBrowser_2->toHtml() + "<p>" + msg.message() + "</p>");
        QScrollBar *sb = ui->textBrowser_2->verticalScrollBar();
        sb->setValue(sb->maximum());
    });

    connect(client, &Client::messagesRecived, this, [this](QList<Message> msgs){
        for(Message msg: msgs){
            ui->textBrowser_2->setHtml(ui->textBrowser_2->toHtml() + "<p>" + msg.message() + "</p>");
        }
        QScrollBar *sb = ui->textBrowser_2->verticalScrollBar();
        sb->setValue(sb->maximum());
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_connectPb_clicked()
{
    client->becomeAPublisher();
}

void Widget::on_pushButton_connectSb_clicked()
{
    client->becomeASubscriber(ui->comboBox_topics->currentText());
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
