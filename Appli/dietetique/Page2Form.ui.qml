import QtQuick 2.9
import QtQuick.Controls 2.2

Page {
    id: page
    width: 539
    height: 400
    property alias textCorpulence: textCorpulence
    property alias textLabelIMC: textLabelIMC
    property alias labelPoidsIdeal: labelPoidsIdeal
    property alias page: page
    property alias buttonAge: buttonAge
    property alias buttonLorentz: buttonLorentz
    property alias buttonDevine: buttonDevine
    property alias roundButton: roundButton
    property alias dial: dial
    property alias row2: row2
    property alias labelCorpulence: labelCorpulence
    property alias row1: row1
    property alias labelIMC: labelIMC
    property alias row: row
    property alias column: column

    header: Label {
        text: qsTr("IMC et Poids idéal")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Column {
        id: column
        x: 7
        y: -12
        width: 525
        height: 371

        Row {
            id: row
            width: 69
            height: 22
            spacing: 3

            Label {
                id: labelIMC
                text: qsTr("IMC")
            }

            Text {
                id: textLabelIMC
                width: 36
                height: 17
                lineHeight: 0.9
                font.pixelSize: 12
            }
        }

        Row {
            id: row1
            width: 133
            height: 24
            spacing: 8

            Label {
                id: labelCorpulence
                text: qsTr("Corpulence")
            }

            Text {
                id: textCorpulence
                width: 52
                font.pixelSize: 12
            }
        }

        Row {
            id: row2
            width: 200
            height: 190

            Dial {

                property string couleurCercle: "Teal"
                property string couleurCercleFamine: "red"
                property string poidsPersonne: "OKg"

                stepSize: 0.01
                to: 300
                from: 15
                value: 15
                id: dial

                RoundButton {
                    id: roundButton
                    text: dial.poidsPersonne
                    spacing: 3
                    opacity: 0.6
                    anchors.fill: parent
                    background: Rectangle{
                        radius: roundButton.radius
                        color: dial.couleurCercle
                    }


                }

                Label {
                    id: labelPoidsIdeal
                    x: 199
                    y: 84
                    text: qsTr("Poids Ideal")
                }
            }
        }

        Button {
            id: buttonDevine
            x: 0
            y: 237
            width: 525
            text: qsTr("Poids idéal selon Devine")
            focusPolicy: Qt.NoFocus
        }

        Button {
            id: buttonLorentz
            width: 525
            text: qsTr("Poids idéal selon Lorentz")
        }

        Button {
            id: buttonAge
            width: 525
            text: qsTr("Poids idéal selon Lorentz/age")
        }
    }
}

/*##^## Designer {
    D{i:11;anchors_height:38;anchors_width:38;anchors_x:73;anchors_y:73}
}
 ##^##*/
