import QtQuick 2.0

Item {
    width: 320
    height: 480

    Rectangle {
        color: "#272822"
        width: 320
        height: 480
    }

    Column {
        width: childrenRect.width
        anchors.centerIn: parent
        spacing: 8
        // Each of these is a Button as styled in Button.qml
        Button { caption: "Eeny"; onClicked: console.log("Eeny");}
        Button { caption: "Meeny"; onClicked: console.log("Meeny");}
        Button { caption: "Miny"; onClicked: console.log("Miny");}
        Button { caption: "Mo"; onClicked: console.log("Mo");}
    }
}

