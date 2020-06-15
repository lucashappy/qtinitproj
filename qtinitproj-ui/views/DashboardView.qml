import QtQuick 2.9
import assets 1.0
import QTINITPROJ 1.0
import components 1.0


Item {

    Rectangle{
        anchors.fill: parent
        anchors.bottom: commandBar.top
        color: Style.colourBackground

        Text {
            anchors.centerIn: parent
            text: masterController.ui_welcomeMessage //"Dashboard View"
        }
    }

    CommandBar {
        id: commandBar
        commandList: masterController.ui_commandController.ui_dashboardViewContextCommands
    }

}
