import QtQuick 2.9
import QtQuick.Controls 2.2

Page {
    id: page
    width: 600
    height: 400
    property alias buttonModeManuel: buttonModeManuel

    header: Label {
        text: qsTr("SERRE EN DIRECT")
        font.pixelSize: 27
        horizontalAlignment: Text.AlignHCenter
        padding: 10
    }

    Button {
        id: buttonModeProgramme
        x: 176
        y: 102
        width: 249
        height: 35
        text: qsTr("Mode Programmé")
        font.pointSize: 13
    }

    Button {
        id: buttonModeAuto
        x: 176
        y: 154
        width: 249
        height: 35
        text: qsTr("Mode Auto")
        font.pointSize: 13
    }

    Button {
        id: buttonArretTotal
        x: 176
        y: 208
        width: 249
        height: 35
        text: qsTr("Arrêt Total")
        spacing: 3
        font.pointSize: 13
    }

    Button {
        id: buttonModeManuel
        x: 176
        y: 53
        width: 249
        height: 35
        text: qsTr("Mode Manuel")
        font.pointSize: 13
    }
}
