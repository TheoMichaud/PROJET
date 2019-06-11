import QtQuick 2.9
import QtQuick.Controls 2.2

Page {
    id: page1
    width: 539
    height: 400
    property alias sliderTaille: sliderTaille
    property alias labelPoids: labelPoids
    property alias labelValPoids: labelValPoids
    property alias labelValTaille: labelValTaille
    property alias sliderPoids: sliderPoids
    property alias labelTaille: labelTaille
    property alias row3: row3
    property alias row2: row2
    property alias spinBoxAge: spinBoxAge
    property alias labelAge: labelAge
    property alias row1: row1
    property alias labelSexe: labelSexe
    property alias row: row
    property alias column: column
    property alias page1: page1
    property alias switchSexe: switchSexe
    header: Label {
        text: qsTr("Informations personnelles")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Column {
        id: column
        x: 16
        y: 30
        width: 255
        height: 287
        spacing: 28

        Row {
            id: row
            width: 148
            height: 40

            Label {
                id: labelSexe
                y: 11
                width: 28
                height: 19
                text: qsTr("Sexe")
            }

            Switch {
                id: switchSexe
                text: qsTr("Femme")
            }
        }

        Row {
            id: row1
            width: 200
            height: 49
            spacing: 5

            Label {
                id: labelAge
                y: 12
                height: 17
                text: qsTr("Age")
            }

            SpinBox {
                id: spinBoxAge
                to: 200
                from: 1
                value: 30
            }
        }

        Row {
            id: row2
            width: 232
            height: 42

            Label {
                id: labelPoids
                y: 11
                height: 17
                text: qsTr("Poids")
                textFormat: Text.PlainText
            }

            Slider {
                id: sliderPoids
                stepSize: 0.01
                to: 300
                from: 15
                value: 15
            }

            Label {
                id: labelValPoids
                y: 10
                text: qsTr("15")
            }
        }

        Row {
            id: row3
            width: 234
            height: 40

            Label {
                id: labelTaille
                y: 10
                text: qsTr("Taille")
            }

            Slider {
                id: sliderTaille
                stepSize: 0.01
                to: 3
                from: 0.5
                value: 0.5
            }

            Label {
                id: labelValTaille
                y: 12
                width: 22
                height: 17
                text: qsTr("0,5")
            }
        }
    }
}
