/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_ip;
    QLineEdit *lineEdit_ip;
    QLabel *label_port;
    QSpinBox *spinBox_port;
    QLabel *label;
    QComboBox *comboBox_topics;
    QPushButton *pushButton_connect;
    QPushButton *pushButton_connectPb;
    QPushButton *pushButton_connectSb;
    QHBoxLayout *horizontalLayout_2;
    QTextBrowser *textBrowser_2;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_send;
    QLabel *label_satus;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(718, 192);
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_ip = new QLabel(Widget);
        label_ip->setObjectName(QString::fromUtf8("label_ip"));

        horizontalLayout->addWidget(label_ip);

        lineEdit_ip = new QLineEdit(Widget);
        lineEdit_ip->setObjectName(QString::fromUtf8("lineEdit_ip"));
        lineEdit_ip->setMaxLength(15);

        horizontalLayout->addWidget(lineEdit_ip);

        label_port = new QLabel(Widget);
        label_port->setObjectName(QString::fromUtf8("label_port"));

        horizontalLayout->addWidget(label_port);

        spinBox_port = new QSpinBox(Widget);
        spinBox_port->setObjectName(QString::fromUtf8("spinBox_port"));
        spinBox_port->setMinimum(49152);
        spinBox_port->setMaximum(65535);
        spinBox_port->setValue(59050);

        horizontalLayout->addWidget(spinBox_port);

        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBox_topics = new QComboBox(Widget);
        comboBox_topics->setObjectName(QString::fromUtf8("comboBox_topics"));

        horizontalLayout->addWidget(comboBox_topics);

        pushButton_connect = new QPushButton(Widget);
        pushButton_connect->setObjectName(QString::fromUtf8("pushButton_connect"));

        horizontalLayout->addWidget(pushButton_connect);

        pushButton_connectPb = new QPushButton(Widget);
        pushButton_connectPb->setObjectName(QString::fromUtf8("pushButton_connectPb"));

        horizontalLayout->addWidget(pushButton_connectPb);

        pushButton_connectSb = new QPushButton(Widget);
        pushButton_connectSb->setObjectName(QString::fromUtf8("pushButton_connectSb"));

        horizontalLayout->addWidget(pushButton_connectSb);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        textBrowser_2 = new QTextBrowser(Widget);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));

        horizontalLayout_2->addWidget(textBrowser_2);

        plainTextEdit = new QPlainTextEdit(Widget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        horizontalLayout_2->addWidget(plainTextEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_send = new QPushButton(Widget);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));

        horizontalLayout_3->addWidget(pushButton_send);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        label_satus = new QLabel(Widget);
        label_satus->setObjectName(QString::fromUtf8("label_satus"));

        verticalLayout_2->addWidget(label_satus);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label_ip->setText(QCoreApplication::translate("Widget", "IP address", nullptr));
        lineEdit_ip->setText(QCoreApplication::translate("Widget", "127.0.0.1", nullptr));
        label_port->setText(QCoreApplication::translate("Widget", "Port", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Topics", nullptr));
        pushButton_connect->setText(QCoreApplication::translate("Widget", "Connect", nullptr));
        pushButton_connectPb->setText(QCoreApplication::translate("Widget", "Become a publisher", nullptr));
        pushButton_connectSb->setText(QCoreApplication::translate("Widget", "Become a subscriber", nullptr));
        pushButton_send->setText(QCoreApplication::translate("Widget", "Send", nullptr));
        label_satus->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
