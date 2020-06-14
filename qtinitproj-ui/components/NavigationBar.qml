import QtQuick 2.9
import assets 1.0

Item {

    property bool isCollapsed: true

    anchors {
        top: parent.top
        bottom: parent.bottom
        left: parent.left
    }
    width: isCollapsed ? Style.widthNavigationBarCollapsed :
                         Style.widthNavigationBarExpanded

    Rectangle {
        anchors.fill: parent
        color: Style.colourNavigationBarBackground

        Column {
            width: parent.width

            NavigationButton {
                iconCharacter: "\uf0c9"
                description: ""
                hoverColour: "#993333"
                onNavigationButtonClicked: isCollapsed = !isCollapsed
            }
            NavigationButton {
                iconCharacter: "\uf015"
                description: "Dashboard"
                hoverColour: "#dc8a00"
                onNavigationButtonClicked: masterController.ui_navigationController.goDashboardView()
            }          
        }
    }
}
