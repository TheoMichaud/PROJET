import QtQuick 2.9
import QtQuick.Controls 2.2

Page {
    width: 600
    height: 400

    header: Label {
        x: 175
        text: qsTr("SERRE EN DIRECT")
        font.pixelSize: 24
        transformOrigin: Item.Center
        font.wordSpacing: -0.3
        font.bold: true
        font.family: "Times New Roman"
        padding: 10
    }

    Rectangle {
        id: rectangle
        x: 22
        y: 6
        width: 554
        height: 21
        color: "#fd9402"
    }

    Label {
        id: label
        x: 188
        y: 61
        width: 224
        height: 23
        color: "#3b884a"
        text: qsTr("Information sur le Contrôleur 1")
        font.pointSize: 12
        font.family: "Arial"
        font.underline: true
    }

    Label {
        id: label1
        x: 79
        y: 116
        width: 160
        height: 28
        text: qsTr("Luminosité")
        font.pointSize: 11
    }

    Label {
        id: label2
        x: 79
        y: 150
        width: 160
        height: 28
        text: qsTr("Débit D'eau")
        font.pointSize: 11
    }

    Label {
        id: label3
        x: 79
        y: 184
        width: 160
        height: 28
        text: qsTr("Température")
        font.pointSize: 11
    }

    Label {
        id: label4
        x: 79
        y: 218
        width: 160
        height: 28
        text: qsTr("Humidité sol")
        font.pointSize: 11
    }

    Label {
        id: label5
        x: 79
        y: 252
        width: 160
        height: 28
        text: qsTr("Humidité air")
        font.pointSize: 11
    }

    Text {
        id: text1
        x: 338
        y: 119
        width: 69
        height: 23
        text: qsTr("25 Lux")
        font.pixelSize: 13
    }

    Text {
        id: text2
        x: 338
        y: 153
        width: 69
        height: 23
        text: qsTr("1 L/Heure")
        font.pixelSize: 13
    }

    Text {
        id: text3
        x: 338
        y: 187
        width: 69
        height: 23
        text: qsTr("15°C")
        font.pixelSize: 13
    }

    Text {
        id: text4
        x: 338
        y: 221
        width: 69
        height: 23
        text: qsTr("25%")
        font.pixelSize: 13
    }

    Text {
        id: text5
        x: 338
        y: 255
        width: 69
        height: 23
        text: qsTr("32%")
        font.pixelSize: 13
    }
}
