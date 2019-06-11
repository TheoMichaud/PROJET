import QtQuick 2.9
import QtQuick.Controls 2.2

Page {
    width: 400
    height: 600
    smooth: false
    rotation: 0

    Rectangle {
        id: rectangle
        x: 0
        y: 199
        width: 0
        height: 201
        color: "#ffffff"
    }

    Rectangle {
        id: rectangle2
        x: 0
        y: 100
        width: 200
        height: 250
        color: "#ffffff"

        Text {
            id: text1
            x: 81
            y: 8
            text: qsTr("Zone 1")
            font.pixelSize: 12
        }

        RadioButton {
            id: radioButton
            x: 20
            y: 48
            width: 160
            height: 24
            text: qsTr("Mode Programmé")
        }

        RadioButton {
            id: radioButton1
            x: 20
            y: 78
            width: 160
            height: 24
            text: qsTr("Mode Automatique")
        }

        RadioButton {
            id: radioButton2
            x: 20
            y: 108
            width: 160
            height: 24
            text: qsTr("Arrêt Complet")
        }

        RadioButton {
            id: radioButton3
            x: 20
            y: 138
            width: 160
            height: 24
            text: qsTr("Mode Manuel")
        }

        Switch {
            id: switch1
            x: 15
            y: 189
            text: qsTr("Ouverture Vanne")
        }
    }

    Text {
        id: text3
        x: 115
        y: 22
        color: "#db740d"
        text: qsTr("SERRE EN DIRECT")
        font.capitalization: Font.MixedCase
        font.underline: false
        font.bold: true
        font.pixelSize: 19
        font.strikeout: false
        font.family: "Courier"
    }

    Rectangle {
        id: rectangle5
        x: 200
        y: 100
        width: 200
        height: 250
        color: "#ffffff"
        Text {
            id: text2
            x: 81
            y: 8
            text: qsTr("Zone 2")
            font.pixelSize: 12
        }

        RadioButton {
            id: radioButton4
            x: 20
            y: 48
            width: 160
            height: 24
            text: qsTr("Mode Programmé")
        }

        RadioButton {
            id: radioButton5
            x: 20
            y: 78
            width: 160
            height: 24
            text: qsTr("Mode Automatique")
        }

        RadioButton {
            id: radioButton6
            x: 20
            y: 108
            width: 160
            height: 24
            text: qsTr("Arrêt Complet")
        }

        RadioButton {
            id: radioButton7
            x: 20
            y: 138
            width: 160
            height: 24
            text: qsTr("Mode Manuel")
        }

        Switch {
            id: switch2
            x: 15
            y: 189
            text: qsTr("Ouverture Vanne")
        }
    }

    Rectangle {
        id: rectangle3
        x: 0
        y: 350
        width: 200
        height: 250
        color: "#ffffff"
        Text {
            id: text4
            x: 81
            y: 8
            text: qsTr("Zone 3")
            font.pixelSize: 12
        }

        RadioButton {
            id: radioButton8
            x: 20
            y: 48
            width: 160
            height: 24
            text: qsTr("Mode Programmé")
        }

        RadioButton {
            id: radioButton9
            x: 20
            y: 78
            width: 160
            height: 24
            text: qsTr("Mode Automatique")
        }

        RadioButton {
            id: radioButton10
            x: 20
            y: 108
            width: 160
            height: 24
            text: qsTr("Arrêt Complet")
        }

        RadioButton {
            id: radioButton11
            x: 20
            y: 138
            width: 160
            height: 24
            text: qsTr("Mode Manuel")
        }

        Switch {
            id: switch3
            x: 15
            y: 189
            text: qsTr("Ouverture Vanne")
        }
    }

    Rectangle {
        id: rectangle4
        x: 200
        y: 350
        width: 200
        height: 250
        color: "#ffffff"
        Text {
            id: text5
            x: 81
            y: 8
            text: qsTr("Zone 4")
            font.pixelSize: 12
        }

        RadioButton {
            id: radioButton12
            x: 20
            y: 48
            width: 160
            height: 24
            text: qsTr("Mode Programmé")
        }

        RadioButton {
            id: radioButton13
            x: 20
            y: 78
            width: 160
            height: 24
            text: qsTr("Mode Automatique")
        }

        RadioButton {
            id: radioButton14
            x: 20
            y: 108
            width: 160
            height: 24
            text: qsTr("Arrêt Complet")
        }

        RadioButton {
            id: radioButton15
            x: 20
            y: 138
            width: 160
            height: 24
            text: qsTr("Mode Manuel")
        }

        Switch {
            id: switch4
            x: 15
            y: 189
            text: qsTr("Ouverture Vanne")
        }
    }
}
