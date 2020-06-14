import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import assets 1.0
import components 1.0

Window {
    visible: true
    width: 960
    height: 720
    title: qsTr("Qt Init Project")

    Connections {
        target: masterController.ui_navigationController
        function onGoDashboardView() { contentFrame.replace("qrc:/views/DashboardView.qml") }
        function onPop() { contentFrame.pop() }
    }

    NavigationBar {
        id: navigationBar
    }

    StackView {
        id: contentFrame
        anchors {
            top: parent.top
            bottom: parent.bottom
            right: parent.right
            left: navigationBar.right
        }
        clip: true
        initialItem: "qrc:/views/SplashView.qml"
    }
}
