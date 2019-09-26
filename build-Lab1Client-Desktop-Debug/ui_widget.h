/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(800, 600);
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_ip = new QLabel(Widget);
        label_ip->setObjectName(QStringLiteral("label_ip"));

        horizontalLayout->addWidget(label_ip);

        lineEdit_ip = new QLineEdit(Widget);
        lineEdit_ip->setObjectName(QStringLiteral("lineEdit_ip"));
        lineEdit_ip->setMaxLength(15);

        horizontalLayout->addWidget(lineEdit_ip);

        label_port = new QLabel(Widget);
        label_port->setObjectName(QStringLiteral("label_port"));

        horizontalLayout->addWidget(label_port);

        spinBox_port = new QSpinBox(Widget);
        spinBox_port->setObjectName(QStringLiteral("spinBox_port"));
        spinBox_port->setMinimum(49152);
        spinBox_port->setMaximum(65535);
        spinBox_port->setValue(59050);

        horizontalLayout->addWidget(spinBox_port);

        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBox_topics = new QComboBox(Widget);
        comboBox_topics->setObjectName(QStringLiteral("comboBox_topics"));

        horizontalLayout->addWidget(comboBox_topics);

        pushButton_connectPb = new QPushButton(Widget);
        pushButton_connectPb->setObjectName(QStringLiteral("pushButton_connectPb"));

        horizontalLayout->addWidget(pushButton_connectPb);

        pushButton_connectSb = new QPushButton(Widget);
        pushButton_connectSb->setObjectName(QStringLiteral("pushButton_connectSb"));

        horizontalLayout->addWidget(pushButton_connectSb);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        textBrowser_2 = new QTextBrowser(Widget);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));

        horizontalLayout_2->addWidget(textBrowser_2);

        plainTextEdit = new QPlainTextEdit(Widget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        horizontalLayout_2->addWidget(plainTextEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_send = new QPushButton(Widget);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));

        horizontalLayout_3->addWidget(pushButton_send);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        label_satus = new QLabel(Widget);
        label_satus->setObjectName(QStringLiteral("label_satus"));

        verticalLayout_2->addWidget(label_satus);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label_ip->setText(QApplication::translate("Widget", "IP address", Q_NULLPTR));
        lineEdit_ip->setText(QApplication::translate("Widget", "127.0.0.1", Q_NULLPTR));
        label_port->setText(QApplication::translate("Widget", "Port", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "Topics", Q_NULLPTR));
        pushButton_connectPb->setText(QApplication::translate("Widget", "Connect as publisher", Q_NULLPTR));
        pushButton_connectSb->setText(QApplication::translate("Widget", "Connect as subscriber", Q_NULLPTR));
        pushButton_send->setText(QApplication::translate("Widget", "Send", Q_NULLPTR));
        label_satus->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
