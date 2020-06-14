import QtQuick 2.9
import assets 1.0
import QTINITPROJ 1.0

Item {

    Rectangle{
        anchors.fill: parent
        color: Style.colourBackground

        Text {
            anchors.centerIn: parent
            text: masterController.ui_welcomeMessage //"Dashboard View"
        }
    }

}
