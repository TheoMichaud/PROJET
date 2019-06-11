/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QStackedWidget *stackedWidgetPage;
    QWidget *pageAccueil;
    QLabel *labelInfoZone_2;
    QPushButton *pushButtonGo;
    QWidget *pageChoixMode;
    QPushButton *pushButtonModeManuel;
    QPushButton *pushButtonModeProgramme;
    QPushButton *pushButtonModeAuto;
    QPushButton *pushButtonArretTotal;
    QWidget *pageChoixManuel;
    QLabel *label_6;
    QLabel *labelInfoZone;
    QLabel *label_4;
    QPushButton *pushButtonLancerOuverture;
    QPushButton *pushButtonLanceFermeture;
    QLabel *label_5;
    QLabel *labelInfoHumiditSol;
    QLabel *labelInfoDebit;
    QWidget *page;
    QLabel *labelInfoZone_3;
    QLabel *label_7;
    QLabel *labelTitre;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(494, 528);
        stackedWidgetPage = new QStackedWidget(Widget);
        stackedWidgetPage->setObjectName(QStringLiteral("stackedWidgetPage"));
        stackedWidgetPage->setGeometry(QRect(10, 110, 481, 411));
        pageAccueil = new QWidget();
        pageAccueil->setObjectName(QStringLiteral("pageAccueil"));
        labelInfoZone_2 = new QLabel(pageAccueil);
        labelInfoZone_2->setObjectName(QStringLiteral("labelInfoZone_2"));
        labelInfoZone_2->setGeometry(QRect(150, 60, 151, 31));
        labelInfoZone_2->setAlignment(Qt::AlignCenter);
        pushButtonGo = new QPushButton(pageAccueil);
        pushButtonGo->setObjectName(QStringLiteral("pushButtonGo"));
        pushButtonGo->setGeometry(QRect(180, 190, 80, 25));
        stackedWidgetPage->addWidget(pageAccueil);
        pageChoixMode = new QWidget();
        pageChoixMode->setObjectName(QStringLiteral("pageChoixMode"));
        pushButtonModeManuel = new QPushButton(pageChoixMode);
        pushButtonModeManuel->setObjectName(QStringLiteral("pushButtonModeManuel"));
        pushButtonModeManuel->setGeometry(QRect(160, 40, 151, 41));
        pushButtonModeProgramme = new QPushButton(pageChoixMode);
        pushButtonModeProgramme->setObjectName(QStringLiteral("pushButtonModeProgramme"));
        pushButtonModeProgramme->setGeometry(QRect(160, 100, 151, 41));
        pushButtonModeAuto = new QPushButton(pageChoixMode);
        pushButtonModeAuto->setObjectName(QStringLiteral("pushButtonModeAuto"));
        pushButtonModeAuto->setGeometry(QRect(160, 160, 151, 41));
        pushButtonArretTotal = new QPushButton(pageChoixMode);
        pushButtonArretTotal->setObjectName(QStringLiteral("pushButtonArretTotal"));
        pushButtonArretTotal->setGeometry(QRect(160, 220, 151, 41));
        stackedWidgetPage->addWidget(pageChoixMode);
        pageChoixManuel = new QWidget();
        pageChoixManuel->setObjectName(QStringLiteral("pageChoixManuel"));
        label_6 = new QLabel(pageChoixManuel);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 310, 131, 31));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        labelInfoZone = new QLabel(pageChoixManuel);
        labelInfoZone->setObjectName(QStringLiteral("labelInfoZone"));
        labelInfoZone->setGeometry(QRect(150, 40, 151, 31));
        labelInfoZone->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(pageChoixManuel);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(130, 200, 171, 31));
        label_4->setAlignment(Qt::AlignCenter);
        pushButtonLancerOuverture = new QPushButton(pageChoixManuel);
        pushButtonLancerOuverture->setObjectName(QStringLiteral("pushButtonLancerOuverture"));
        pushButtonLancerOuverture->setGeometry(QRect(210, 260, 80, 25));
        pushButtonLanceFermeture = new QPushButton(pageChoixManuel);
        pushButtonLanceFermeture->setObjectName(QStringLiteral("pushButtonLanceFermeture"));
        pushButtonLanceFermeture->setGeometry(QRect(210, 310, 80, 25));
        label_5 = new QLabel(pageChoixManuel);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 260, 131, 31));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        labelInfoHumiditSol = new QLabel(pageChoixManuel);
        labelInfoHumiditSol->setObjectName(QStringLiteral("labelInfoHumiditSol"));
        labelInfoHumiditSol->setGeometry(QRect(40, 110, 131, 31));
        labelInfoHumiditSol->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        labelInfoDebit = new QLabel(pageChoixManuel);
        labelInfoDebit->setObjectName(QStringLiteral("labelInfoDebit"));
        labelInfoDebit->setGeometry(QRect(40, 150, 131, 31));
        labelInfoDebit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        stackedWidgetPage->addWidget(pageChoixManuel);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        labelInfoZone_3 = new QLabel(page);
        labelInfoZone_3->setObjectName(QStringLiteral("labelInfoZone_3"));
        labelInfoZone_3->setGeometry(QRect(150, 40, 151, 31));
        labelInfoZone_3->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(page);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(130, 200, 191, 31));
        label_7->setAlignment(Qt::AlignCenter);
        stackedWidgetPage->addWidget(page);
        labelTitre = new QLabel(Widget);
        labelTitre->setObjectName(QStringLiteral("labelTitre"));
        labelTitre->setGeometry(QRect(130, 0, 221, 61));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(3);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(labelTitre->sizePolicy().hasHeightForWidth());
        labelTitre->setSizePolicy(sizePolicy);
        labelTitre->setAlignment(Qt::AlignCenter);

        retranslateUi(Widget);

        stackedWidgetPage->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        labelInfoZone_2->setText(QApplication::translate("Widget", "S\303\251lection de la Zone", nullptr));
        pushButtonGo->setText(QApplication::translate("Widget", "Go", nullptr));
        pushButtonModeManuel->setText(QApplication::translate("Widget", "Mode Manuel", nullptr));
        pushButtonModeProgramme->setText(QApplication::translate("Widget", "Mode Programm\303\251", nullptr));
        pushButtonModeAuto->setText(QApplication::translate("Widget", "Mode Automatique", nullptr));
        pushButtonArretTotal->setText(QApplication::translate("Widget", "Arr\303\252t Total", nullptr));
        label_6->setText(QApplication::translate("Widget", "Fermeture Vanne ", nullptr));
        labelInfoZone->setText(QApplication::translate("Widget", "Information Zone 1", nullptr));
        label_4->setText(QApplication::translate("Widget", "Gestion Mode Manuel Zone 1", nullptr));
        pushButtonLancerOuverture->setText(QApplication::translate("Widget", "Lancer", nullptr));
        pushButtonLanceFermeture->setText(QApplication::translate("Widget", "Lancer", nullptr));
        label_5->setText(QApplication::translate("Widget", "Ouverture Vanne ", nullptr));
        labelInfoHumiditSol->setText(QApplication::translate("Widget", "Humidit\303\251 du sol", nullptr));
        labelInfoDebit->setText(QApplication::translate("Widget", "D\303\251bit d'eau", nullptr));
        labelInfoZone_3->setText(QApplication::translate("Widget", "Information Zone 1", nullptr));
        label_7->setText(QApplication::translate("Widget", "Gestion Mode Programm\303\251 Zone 1", nullptr));
        labelTitre->setText(QApplication::translate("Widget", "SERRE EN DIRECT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
