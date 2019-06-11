import QtQuick 2.9
import QtQuick.Controls 2.2

Page {
    width: 600
    height: 400

    header: Label {
        x: 175
        y: 1
        height: 42
        text: qsTr("SERRE EN DIRECT")
        lineHeight: 1
        font.capitalization: Font.MixedCase
        font.family: "Times New Roman"
        font.bold: true
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Rectangle {
        id: rectangle
        x: 22
        y: 10
        width: 556
        height: 21
        color: "#fd9402"
    }

    Label {
        id: label
        x: 210
        y: 63
        color: "#3b884a"
        text: qsTr("Gestion du Controleur 1")
        font.underline: true
        font.bold: false
        font.pointSize: 12
    }

    Button {
        id: button
        x: 188
        y: 117
        width: 239
        height: 37
        text: qsTr("Mode Manuel")
        font.pointSize: 11
    }

    Button {
        id: button1
        x: 188
        y: 166
        width: 239
        height: 37
        text: qsTr("Mode Programmé")
        font.pointSize: 11
    }

    Button {
        id: button2
        x: 188
        y: 216
        width: 239
        height: 37
        text: qsTr("Mode Auto")
        font.pointSize: 11
    }

    Button {
        id: button3
        x: 188
        y: 268
        width: 239
        height: 37
        text: qsTr("Arrêt Total")
        focusPolicy: Qt.StrongFocus
        autoRepeat: true
        padding: 4
        font.capitalization: Font.MixedCase
        font.pointSize: 11
    }
}
