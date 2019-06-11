import QtQuick 2.9
import QtQuick.Controls 2.2

Page {
    width: 400
    height: 400

    header: Label {
        text: "SERRE EN DIRECT"
        font.pixelSize: 27
        lineHeight: 0.9
        horizontalAlignment: Text.AlignHCenter
        padding: 10
    }

    Text {
        id: text1
        x: 92
        y: 62
        width: 216
        height: 31
        color: "#08a010"
        text: qsTr("Sélection de la Zone")
        styleColor: "#5af20d"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 20
    }

    ComboBox {
        id: comboBox
        x: 137
        y: 117
        displayText: "Zone 1"
        textRole: ""
        currentIndex: -4
    }
}
