/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsClass
{
public:
    QWidget *centralWidget;
    QComboBox *comboBox_2;
    QPushButton *btn_OK;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *cbb_LeftHandUp;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_2;
    QComboBox *cbb_RightHandUp;
    QComboBox *cbb_LeftHandLeft;
    QComboBox *cbb_RightHandRight;
    QLabel *label_4;
    QComboBox *cbb_HandsClosed;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SettingsClass)
    {
        if (SettingsClass->objectName().isEmpty())
            SettingsClass->setObjectName(QStringLiteral("SettingsClass"));
        SettingsClass->resize(481, 330);
        centralWidget = new QWidget(SettingsClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(340, 10, 131, 22));
        btn_OK = new QPushButton(centralWidget);
        btn_OK->setObjectName(QStringLiteral("btn_OK"));
        btn_OK->setGeometry(QRect(120, 240, 75, 23));
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 311, 231));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setHorizontalSpacing(20);
        formLayout->setVerticalSpacing(20);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        cbb_LeftHandUp = new QComboBox(formLayoutWidget);
        cbb_LeftHandUp->setObjectName(QStringLiteral("cbb_LeftHandUp"));

        formLayout->setWidget(0, QFormLayout::FieldRole, cbb_LeftHandUp);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        cbb_RightHandUp = new QComboBox(formLayoutWidget);
        cbb_RightHandUp->setObjectName(QStringLiteral("cbb_RightHandUp"));

        formLayout->setWidget(1, QFormLayout::FieldRole, cbb_RightHandUp);

        cbb_LeftHandLeft = new QComboBox(formLayoutWidget);
        cbb_LeftHandLeft->setObjectName(QStringLiteral("cbb_LeftHandLeft"));

        formLayout->setWidget(2, QFormLayout::FieldRole, cbb_LeftHandLeft);

        cbb_RightHandRight = new QComboBox(formLayoutWidget);
        cbb_RightHandRight->setObjectName(QStringLiteral("cbb_RightHandRight"));

        formLayout->setWidget(3, QFormLayout::FieldRole, cbb_RightHandRight);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        cbb_HandsClosed = new QComboBox(formLayoutWidget);
        cbb_HandsClosed->setObjectName(QStringLiteral("cbb_HandsClosed"));

        formLayout->setWidget(4, QFormLayout::FieldRole, cbb_HandsClosed);

        SettingsClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SettingsClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 481, 23));
        SettingsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SettingsClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SettingsClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SettingsClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SettingsClass->setStatusBar(statusBar);

        retranslateUi(SettingsClass);

        QMetaObject::connectSlotsByName(SettingsClass);
    } // setupUi

    void retranslateUi(QMainWindow *SettingsClass)
    {
        SettingsClass->setWindowTitle(QApplication::translate("SettingsClass", "Settings", 0));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("SettingsClass", "\345\261\217\345\271\2251*1\346\216\222\345\210\227", 0)
         << QApplication::translate("SettingsClass", "\345\261\217\345\271\2252*2\346\216\222\345\210\227", 0)
         << QApplication::translate("SettingsClass", "\345\261\217\345\271\2253*3\346\216\222\345\210\227", 0)
         << QApplication::translate("SettingsClass", "\351\237\263\351\207\217\345\242\236\345\212\240", 0)
         << QApplication::translate("SettingsClass", "\351\237\263\351\207\217\345\207\217\345\260\221", 0)
         << QApplication::translate("SettingsClass", "\346\230\276\347\244\272\344\270\273\351\235\242\346\235\277", 0)
         << QApplication::translate("SettingsClass", "\351\232\220\350\227\217\344\270\273\351\235\242\346\235\277", 0)
         << QApplication::translate("SettingsClass", "PPT\344\270\212\347\277\273", 0)
         << QApplication::translate("SettingsClass", "PPT\344\270\213\347\277\273", 0)
        );
        btn_OK->setText(QApplication::translate("SettingsClass", "\347\241\256\345\256\232", 0));
        label->setText(QApplication::translate("SettingsClass", "\345\267\246\346\211\213\344\270\212\344\270\276", 0));
        cbb_LeftHandUp->clear();
        cbb_LeftHandUp->insertItems(0, QStringList()
         << QApplication::translate("SettingsClass", "Layout11", 0)
         << QApplication::translate("SettingsClass", "Layout22", 0)
         << QApplication::translate("SettingsClass", "Layout33", 0)
         << QApplication::translate("SettingsClass", "PanelVisible", 0)
         << QApplication::translate("SettingsClass", "PanelUnvisible", 0)
         << QApplication::translate("SettingsClass", "VolumnUp", 0)
         << QApplication::translate("SettingsClass", "VolumnDown", 0)
         << QApplication::translate("SettingsClass", "PPTPrev", 0)
         << QApplication::translate("SettingsClass", "PPTNext", 0)
        );
        label_5->setText(QApplication::translate("SettingsClass", "\345\217\214\346\211\213\351\235\240\346\213\242", 0));
        label_3->setText(QApplication::translate("SettingsClass", "\345\267\246\346\211\213\345\220\221\345\267\246", 0));
        label_2->setText(QApplication::translate("SettingsClass", "\345\217\263\346\211\213\344\270\212\344\270\276", 0));
        cbb_RightHandUp->clear();
        cbb_RightHandUp->insertItems(0, QStringList()
         << QApplication::translate("SettingsClass", "Layout11", 0)
         << QApplication::translate("SettingsClass", "Layout22", 0)
         << QApplication::translate("SettingsClass", "Layout33", 0)
         << QApplication::translate("SettingsClass", "PanelVisible", 0)
         << QApplication::translate("SettingsClass", "PanelUnvisible", 0)
         << QApplication::translate("SettingsClass", "VolumnUp", 0)
         << QApplication::translate("SettingsClass", "VolumnDown", 0)
         << QApplication::translate("SettingsClass", "PPTPrev", 0)
         << QApplication::translate("SettingsClass", "PPTNext", 0)
        );
        cbb_LeftHandLeft->clear();
        cbb_LeftHandLeft->insertItems(0, QStringList()
         << QApplication::translate("SettingsClass", "Layout11", 0)
         << QApplication::translate("SettingsClass", "Layout22", 0)
         << QApplication::translate("SettingsClass", "Layout33", 0)
         << QApplication::translate("SettingsClass", "PanelVisible", 0)
         << QApplication::translate("SettingsClass", "PanelUnvisible", 0)
         << QApplication::translate("SettingsClass", "VolumnUp", 0)
         << QApplication::translate("SettingsClass", "VolumnDown", 0)
         << QApplication::translate("SettingsClass", "PPTPrev", 0)
         << QApplication::translate("SettingsClass", "PPTNext", 0)
        );
        cbb_LeftHandLeft->setCurrentText(QApplication::translate("SettingsClass", "Layout11", 0));
        cbb_RightHandRight->clear();
        cbb_RightHandRight->insertItems(0, QStringList()
         << QApplication::translate("SettingsClass", "Layout11", 0)
         << QApplication::translate("SettingsClass", "Layout22", 0)
         << QApplication::translate("SettingsClass", "Layout33", 0)
         << QApplication::translate("SettingsClass", "PanelVisible", 0)
         << QApplication::translate("SettingsClass", "PanelUnvisible", 0)
         << QApplication::translate("SettingsClass", "VolumnUp", 0)
         << QApplication::translate("SettingsClass", "VolumnDown", 0)
         << QApplication::translate("SettingsClass", "PPTPrev", 0)
         << QApplication::translate("SettingsClass", "PPTNext", 0)
        );
        label_4->setText(QApplication::translate("SettingsClass", "\345\217\263\346\211\213\345\220\221\345\217\263", 0));
        cbb_HandsClosed->clear();
        cbb_HandsClosed->insertItems(0, QStringList()
         << QApplication::translate("SettingsClass", "Layout11", 0)
         << QApplication::translate("SettingsClass", "Layout22", 0)
         << QApplication::translate("SettingsClass", "Layout33", 0)
         << QApplication::translate("SettingsClass", "PanelVisible", 0)
         << QApplication::translate("SettingsClass", "PanelUnvisible", 0)
         << QApplication::translate("SettingsClass", "VolumnUp", 0)
         << QApplication::translate("SettingsClass", "VolumnDown", 0)
         << QApplication::translate("SettingsClass", "PPTPrev", 0)
         << QApplication::translate("SettingsClass", "PPTNext", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class SettingsClass: public Ui_SettingsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
