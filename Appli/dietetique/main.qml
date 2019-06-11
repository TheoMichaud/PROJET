import QtQuick 2.9
import QtQuick.Controls 2.2
import "calculpoids.js" as CalculImc

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Calcul IMC")

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex
            onCurrentIndexChanged: {
                    if (currentIndex===1)
                    {
                        var imc;
                        var poids;
                        var taille;

                        poids=pageUi1.sliderPoids.value;
                        taille=pageUi1.sliderTaille.value;

                        imc= poids/(taille*taille);
                        pageUi2.textLabelIMC.text=imc;

                        pageUi2.textCorpulence.text=CalculImc.getCorpulence(imc);

                        //affiche valeur du poids selectionné page1 sur la page2
                        pageUi2.roundButton.text=pageUi1.sliderPoids.value;
                        pageUi2.dial.value=pageUi1.sliderPoids.value;

                  }
}
        Page1Form {
            id:pageUi1
            switchSexe.onCheckedChanged:
            {
                if(switchSexe.text==="Femme")
                {
                    switchSexe.text="Homme";
                }
                else
                {
                    switchSexe.text="Femme";
                }
            }

            sliderPoids.onValueChanged:
            {
                labelValPoids.text=sliderPoids.value;

                console.log("Poids :" + sliderPoids.value);

            }

            sliderTaille.onValueChanged:
            {
                labelValTaille.text=sliderTaille.value;

                console.log("Taille :" + sliderTaille.value);
            }
        }

        Page2Form {
            id: pageUi2
            buttonLorentz.onClicked:
            {
                var taille=pageUi1.sliderTaille.value;
                var sexe=pageUi1.switchSexe.text;
                console.log("taille : "+taille);
                console.log("sexe : "+sexe);

                labelPoidsIdeal.text = (CalculImc.lorentz(taille,sexe)  + " kg");
                console.log("Lorentz :" + CalculImc.lorentz(taille,sexe));
            }
            buttonDevine.onClicked:
            {
                var taille=pageUi1.sliderTaille.value;
                var sexe=pageUi1.switchSexe.text;
                console.log("taille : "+taille);
                console.log("sexe : "+sexe);

                labelPoidsIdeal.text = (CalculImc.devine(taille,sexe) + " kg");
                console.log("Devine :" + CalculImc.devine(pageUi1.labelTaille.text,pageUi1.switchSexe.text));

            }
            buttonAge.onClicked:
            {
                var taille=pageUi1.sliderTaille.value;
                var age=pageUi1.spinBoxAge.value;
                console.log("taille : "+taille);
                console.log("age : "+age);

                labelPoidsIdeal.text = (CalculImc.lorentzAge(taille,age) + " kg");
                console.log("Lorentz Age :" + CalculImc.lorentzAge(pageUi1.labelTaille.text,pageUi1.spinBoxAge.text));

            }


        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        TabButton {
            text: qsTr("Informations Personnelles")
        }
        TabButton {
            text: qsTr("IMC et Poids idéal")
        }
    }
}
